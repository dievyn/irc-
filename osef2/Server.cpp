#include "ft_irc.hpp"

void Server::SerSocket()
{
	int yes = 1;
	this->serverSocket = socket(PF_INET, SOCK_STREAM, 0);
	setsockopt(this->serverSocket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
	std::cout << bind(this->serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) << "\n";
	std::cout << listen(this->serverSocket, 10) << "\n";


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

void Server::SetNickname(Client client_obj, std::string str)
{
	std::cout << "--Server registered nickname\n";
	client_obj.SetNickname(grab_word(str, 2));
}

void Server::interpret(int fd, std::string command)
{
	if (command == "CAP LS 302\r\n")
	{
		std::cout << "Sent CAP * LS\n";
		send(fd, "CAP * LS :\r\n", 13, 0);
	}
	else if (grab_word(command, 1) == "NICK")
	{
		this->client_list[find_fd(fd)].SetNickname(grab_word(command, 2));
		std::string name = this->client_list[find_fd(fd)].GetNickname();
		std::cout << "--- Printing NAME: " << name << "\n";
		std::string message = ":myserver 001 " + name + " :Welcome to the IRC network\r\n";
		send(fd, message.c_str(), message.size(), 0);
		message = ":myserver 002 " + name + " :Your host is myserver\r\n";
		send(fd, message.c_str(), message.size(), 0);
		message = ":myserver 003 " + name + " :Created today\r\n";
		send(fd, message.c_str(), message.size(), 0);
		message = ":myserver 004 " + name + " myserver 0.1 o o\r\n";
		send(fd, message.c_str(), message.size(), 0);
		message = ":myserver 376 " + name + " :End of MOTD\r\n";
		send(fd, message.c_str(), message.size(), 0);
		//	ca marche ??? jspppp
	}
	else if (command == "CAP END\r\n")
	{
		std::string name = this->client_list[find_fd(fd)].GetNickname();
		std::string message = ":myserver 001 " + name + " :Welcome to the IRC network\r\n";
		send(fd, message.c_str(), message.size(), 0);
		message = ":myserver 002 " + name + " :Your host is myserver\r\n";
		send(fd, message.c_str(), message.size(), 0);
		message = ":myserver 003 " + name + " :Created today\r\n";
		send(fd, message.c_str(), message.size(), 0);
		message = ":myserver 004 " + name + " myserver 0.1 o o\r\n";
		send(fd, message.c_str(), message.size(), 0);
		message = ":myserver 376 " + name + " :End of MOTD\r\n";
		send(fd, message.c_str(), message.size(), 0);
	}
	else if (command == "PING myserver\r\n")
	{
		std::cout << "--Server sent PONG\n";
		send(fd, "PONG :myserver\r\n", 16, 0);
	}
	else if (grab_word(command, 1) == "PASS")
	{
		std::cout << "Reading password: ";
		printAscii(grab_word(command, 2));
		std::cout << "\n";
		if (grab_word(command, 2) != this->password)
		{
			std::cout << "------- PASSWORD !\n";
			std::string message = ":myserver 464 " + this->client_list[find_fd(fd)].GetNickname() + " :Password incorrect\r\n";
			send(fd, message.c_str(), message.size(), 0);
			close(fd);
		}
	}
	else if (grab_word(command, 1) == "PRIVMSG")
		send_message(fd, command);
	else if (grab_word(command, 1) == "JOIN")
		joined_channel(fd, command);
	else if (grab_word(command, 1) == "QUIT")
		disconnect(fd);
}

int is_correct_command(std::string command)
{
	int i = command.size() - 1;

	if (i > 0)
		if (command[i] == '\n')
			if (command[i - 1] == '\r')
				return 1;
	return 0;
}

void Server::parseCommands(int fd, std::string buffer)
{
	std::string command;

	std::cout << "\n--- We recieved this buffer:: ";
	printAscii(buffer);
	std::cout << "--- end of buffer now.\n";
	for (unsigned int i = 0; i < buffer.size(); i++)
	{
		for(; buffer[i]; i++)
		{
			if (end_line(buffer, i) == 1)
			{
				command.push_back('\n');
				break;
			}
			command.push_back(buffer[i]);
		}
		std::cout << "Command: <";
		printAscii(command);
		std::cout << ">\n";
		if (is_correct_command(command) == 1)
			interpret(fd, command);
		command.erase();
	}
}

int Server::find_fd(int fd)
{
	for (unsigned int i = 0; i < this->client_list.size(); i++)
		if (this->client_list[i].GetFd() == fd)
			return (i);
	return -1;
}

int Server::do_use_fd(int fd)
{
    char buffer[1024] = {0};
	int client_idx = find_fd(fd);
	if (client_idx == -1)
		return -1;
    int n = recv(fd, buffer, sizeof(buffer), 0);
	this->client_list[client_idx].SetBuffer
		(this->client_list[client_idx].GetBuffer() + buffer);

    if (n > 0)
    {
		for (int i = 0; i < n; i++)
		{
			unsigned char c = buffer[i];
			if (c == '\r') std::cout << "\\r";
			else if (c == '\n') std::cout << "\\n\n";
			else std::cout << buffer[i];
		}
		parseCommands(fd, buffer);
    }
	return 1;
}

Server::Server( int port, std::string password )
{
	this->password = password;
	this->port = port;
	addrlen = sizeof(sockaddr);
	memset(&this->serverAddress, 0, sizeof this->serverAddress);
	memset(&addr, 0, sizeof addr);
	this->serverAddress.sin_family = PF_INET;
	this->serverAddress.sin_port = htons(port);
	this->serverAddress.sin_addr.s_addr = INADDR_ANY;
}

void Server::accept_new_client(int fd)
{
	Client new_client(fd);
	this->client_list.push_back(new_client);
}

void Server::Run()
{
	int nfds = 0;
	int conn_sock = 0;

	for (;;) 
	{
        nfds = epoll_wait(epollfd, events, MAX_EVENTS, 2500);
		if (nfds == -1)
		{
            perror("epoll_wait");
            exit(EXIT_FAILURE);
        }
		std::cout << "NFDS: " << nfds << "\n";
		for (int n = 0; n < nfds; ++n) {
            if (events[n].data.fd == this->serverSocket)
			{
                conn_sock = accept(this->serverSocket, (struct sockaddr *) &addr, &addrlen);
				if (conn_sock == -1) {
					perror("accept");
					exit(EXIT_FAILURE);
				}
				setnonblocking(conn_sock);
				ev.events = EPOLLIN | EPOLLET;
				ev.data.fd = conn_sock;
				if (epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock, &ev) == -1)
				{
					perror("epoll_ctl: conn_sock");
					exit(EXIT_FAILURE);
				}
				accept_new_client(conn_sock);
    		}
			else
            	do_use_fd(events[n].data.fd);
        }
    }
}