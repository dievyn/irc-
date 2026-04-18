//	client_fd: IRSSI
#include "ft_irc.hpp"

int serverSocket;

void do_use_fd(int fd)
{
	char *buffer[1024] = {0};
	if (recv(fd, buffer, sizeof(buffer), 0) > 0)
	{
		std::cout << "Message from client_fd: " << buffer << std::endl;
		// send(fd, buffer, buffer->size(), 0);
	}
}

// void Server::SignalHandler(int sig)
// {
// 	(void)sig;
// 	std::cout << "EXIT\n";
// 	close(this->serverSocket);
// 	this->clients.clear();
// 	exit (0);
// }

void exit_sig(int sig)
{
	(void)sig;
	std::cout << "EXIT\n";
	close(serverSocket);
	exit (0);
}


int main (int argc, char **argv)
{
	if (argc <= 2)
	return std::cout << "ERROR. You must enter the server port AND password to start server.\n", 1;


	signal(SIGINT, &exit_sig);
	Server serv( atoi(argv[1]) );
	serv.SetPassword(argv[2]);
	serv.SerSocket();
	serv.RunServer();
//	SOCK_STREAM = TCP

}
