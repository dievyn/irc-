#include "ft_irc.hpp"

Server::Server( int port )
{
	serverSocket = -1;
	this->channels[0] = "channel_1";
	this->channels[1] = "purgatory";
	this->channels[2] = "minecraft";
	this->password = "abricot";
	addrlen = sizeof(sockaddr);
	memset(&this->serverAddress, 0, sizeof this->serverAddress);
	memset(&addr, 0, sizeof addr);
	this->serverAddress.sin_family = PF_INET;
	this->serverAddress.sin_port = htons(port);
	this->serverAddress.sin_addr.s_addr = INADDR_ANY;
}


std::vector<Client> Server::GetClients( void )
{ return this->clients; }

void Server::SerSocket()
{
	int yes = 1;
	this->serverSocket = socket(PF_INET, SOCK_STREAM, 0);
	setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
	std::cout << bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) << "\n";
	std::cout << listen(serverSocket, 10) << "\n";


    this->epollfd = epoll_create1(0);
    if (this->epollfd == -1)
	{
        perror("epoll_create1");
        exit(EXIT_FAILURE);
    }
    ev.events = EPOLLIN;
    ev.data.fd = serverSocket;
    if (epoll_ctl(this->epollfd, EPOLL_CTL_ADD, serverSocket, &ev) == -1) 
	{
        perror("epoll_ctl: serverSocket");
        exit(EXIT_FAILURE);
    }
}

void setnonblocking(int sock)
{
	int flags;

	flags=fcntl(sock, F_GETFL, 0);  // DO CHECK ERRORS!
    flags |= O_NONBLOCK;
    flags=fcntl(sock, F_SETFL, flags);  // SERIOUSLY
}

int find_client(int target_fd, std::vector<Client> client_list)
{
	for(unsigned int i = 0; i < client_list.size(); i++)
		if (target_fd == client_list[i].GetFd())
			return i;
	return std::cout << "Unexpected error while searching clients. Returning 0.\n", 0;
}

void Server::RunServer( void )
{
    for (;;)
	{
//		we wait for events to occur (messages being sent to our socket)
        nfds = epoll_wait(epollfd, events, MAX_EVENTS, 2500);
		std::cout << "NFDS: " << nfds << "\n";
        if (nfds == -1)
		{
            perror("epoll_wait");
            exit(EXIT_FAILURE);
        }
//		we go through each fd corresponding to each client_fds
        for (int n = 0; n < nfds; ++n)
		{
//			if new client_fd :
            if (events[n].data.fd == serverSocket)
				AcceptNewClient(events[n].data.fd);
		    else
				this->clients[find_client(events[n].data.fd, this->clients)] = ReceiveNewData(&this->clients[find_client(events[n].data.fd, this->clients)]);
    	}
	}
}

void Server::AcceptNewClient( int fd )
{
	Client new_client;

	new_client.SetFd(accept(fd, &this->addr, &this->addrlen));
    if (new_client.GetFd() == -1)
	{
		perror("accept");
        exit(EXIT_FAILURE);
    }
	this->clients.push_back(new_client);
	std::cout << "Client_fd " << new_client.GetFd() << " is connecting..\n";


//	setup new socket :
	setnonblocking(new_client.GetFd());
    ev.events = EPOLLIN;
	ev.data.fd = new_client.GetFd();
	if (epoll_ctl(this->epollfd, EPOLL_CTL_ADD, new_client.GetFd(), &ev) == -1)
	{
       	perror("epoll_ctl: client_fd");
      	exit(EXIT_FAILURE);
    }
	send(new_client.GetFd(), "Enter username followed by password to authenticate.\n", 55, 0);
}

void ChangeName(Client *client_obj, char *name)
{
	std::string new_name;

	client_obj->GetName().clear();
	for (int i = 0; name[i] && name[i] != ' ' && name[i] != '\n' && name[i] != '\r'; i++)
		new_name.push_back(name[i]);
	client_obj->SetName(new_name);
}

void authenticate(Client *client_obj, char *buffer, std::string password)
{
	std::string pass;

	ChangeName(client_obj, buffer);
	int i = client_obj->GetName().size();
	for (; buffer[i] == ' '; i++);
	for(; buffer[i] && buffer[i] != ' ' && buffer[i] != '\n' && buffer[i] != '\r'; i++)
		pass.push_back(buffer[i]);
	if (pass == password)
	{
		send(client_obj->GetFd(), "Authentication successful ! Welcome in channel_1.\n", 52, 0);
		client_obj->SetStatus(true);
	}
	else
	{
		send (client_obj->GetFd(), "You failed to authenticate. You will now be disconnected.\n", 60, 0);
		close (client_obj->GetFd());
	}
}

Client Server::ReceiveNewData( Client *client_obj )
{
	std::string message;
	char buffer[1024] = {0};
	int siz = recv(client_obj->GetFd(), buffer, sizeof(buffer) - 1, 0);
	if (siz == 0)
	{
		message = "<" + client_obj->GetChannel() + "> " + client_obj->GetName() + " disconected...\n"; 
		for (unsigned int i = 0; i < this->clients.size(); i++)
			if (this->clients[i].GetChannel() == client_obj->GetChannel())
				send(this->clients[i].GetFd(), message.c_str(), message.size(), 0);
		send(1, message.c_str(), message.size(), 0);

		close (client_obj->GetFd());
		client_obj->GetName().erase();
		client_obj->GetChannel().erase();
	}
	else if (client_obj->GetStatus() == 0)
		authenticate(client_obj, buffer, this->password);
	else
	{
		buffer[siz] = '\0';
		if (check_commands(client_obj, buffer) == 0)
		{
			message = "<" + client_obj->GetChannel() + "> by client " + client_obj->GetName() + ": " + buffer; 
			for (unsigned int i = 0; i < this->clients.size(); i++)
				if (this->clients[i].GetChannel() == client_obj->GetChannel())
					send(this->clients[i].GetFd(), message.c_str(), message.size(), 0);
			send(1, message.c_str(), message.size(), 0);
		}
	}
	return *client_obj;
}
