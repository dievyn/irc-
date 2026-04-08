#ifndef FT_IRC
#define FT_IRC

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <string>
#include <utility>
#include <sys/types.h>
#include <sys/epoll.h>
#include <sys/time.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#include <vector>

#define MAX_EVENTS 10

class Client
{
	public:
		Client( void );
		int GetFd( void );
		std::string GetChannel( void );
		std::string GetName( void );
		bool GetStatus( void );

		void SetFd(int fd);
		void SetChannel( std::string new_channel );
		void SetName( std::string name );
		void SetStatus( bool status );

	private:
		bool authenticate;
		std::string nickname;
		int client_fd;
		std::string current_channel;
};

class Server
{
	public:
		Server( int port );
		void SerSocket();
		void RunServer();
		void AcceptNewClient( int fd );
		Client ReceiveNewData( Client *client_obj );
		int check_commands(Client *client_obj, char *buffer);
		int switch_channels(Client *client_obj, std::string command);
		int PrivateMsg(Client *client_obj, std::string buffer);
		std::vector<Client> GetClients( void );

//		osef (for now):
		static void SignalHandler(int signum); //-> signal handler		
		void CloseFds(); //-> close file descriptors
		void ClearClients(int fd); //-> clear clients

	private:
		int Port; //-> server port
		std::string password;
		int serverSocket; //-> server socket file descriptor
		static bool Signal; //-> static boolean for signal
		std::vector<Client> clients; //-> vector of clients
		// std::vector<struct pollfd> fds; //-> vector of pollfd

		std::string channels[3];
		sockaddr_in serverAddress;
		struct sockaddr addr;
		socklen_t addrlen;

		struct epoll_event ev, events[MAX_EVENTS];
		int nfds, epollfd;
};

#endif
