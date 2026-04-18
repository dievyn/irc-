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
		std::vector<std::string> GetCreatedChannels ( void )
		{ return this->created_channels; }
		std::string GetBuffer( void )
		{ return this->buffer; }

		void SetFd(int fd);
		void SetChannel( std::string new_channel );
		void SetCreatedChannels( std::string new_created_channel)
		{ this->created_channels.push_back(new_created_channel); }
		void SetName( std::string name );
		void SetStatus( bool status );
		void SetBuffer( std::string str );

	private:
		bool authenticate;
		std::string nickname;
		int client_fd;
		std::string current_channel;
		std::vector<std::string> created_channels;
		std::string buffer;
};

class Server
{
	public:
		Server( int port );
		void SerSocket();
		void RunServer();
		void AcceptNewClient( int fd );
		Client ReceiveNewData( Client *client_obj );
		int check_commands(Client *client_obj, std::string buffer);
		int Join(Client *client_obj, std::string command);
		int PrivateMsg(Client *client_obj, std::string buffer);
		std::vector<Client> GetClients( void );
		void SetPassword( std::string word )
		{ this->password = word; }
		void authenticate(Client *client_obj, std::string buffer, std::string password);
		void ChangeName(Client *client_obj, std::string name);
		int CheckPerms(Client *client_obj);
		int KickUser(Client *client_obj, std::string name);
		int Invite(Client *client_obj, std::string name);

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

		std::vector<std::string> channels;
		sockaddr_in serverAddress;
		struct sockaddr addr;
		socklen_t addrlen;

		struct epoll_event ev, events[MAX_EVENTS];
		int nfds, epollfd;
};

void print_ascii(std::string str);
int skipSpace(std::string buffer);


#endif
