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
		Client(int fd);
		void SetUsername(std::string user);
		void SetNickname(std::string name);
		void SetFd(int fd);
		void SetChannel(std::string channel);
		void SetBuffer(std::string tmp_buffer);
		std::string GetUsername( void );
		std::string GetNickname( void );
		int GetFd( void );
		std::string GetChannel( void );
		std::string GetBuffer( void );
	private:
		int fd;
		std::string username;
		std::string nickname;
		std::string channel;
		std::string buffer;
};

class Server {
	public:
		Server( int port, std::string password );
		int do_use_fd(int fd);
		int find_fd(int fd);
		void send_to_channel(int fd, std::string message);
		void joined_channel(int fd, std::string command);
		void accept_new_client(int fd);
		void SetNickname(Client client_obj, std::string name);
		void parseCommands(int fd, std::string buffer);
		void interpret(int fd, std::string command);
		void SerSocket( void );
		void Run( void );

	private:
		std::string password;
		int port;
		int serverSocket; //-> server socket file descriptor
		static bool Signal; //-> static boolean for signal
		std::vector <Client> client_list;

		std::vector<std::string> channels;
		sockaddr_in serverAddress;
		struct sockaddr addr;
		socklen_t addrlen;
		struct epoll_event ev, events[MAX_EVENTS];
		int nfds, epollfd;
};

std::string grab_name(std::string buffer);
void printAscii(std::string buffer);
std::string grab_line(std::string buffer);
std::string grab_word(std::string buffer, int idx);
int end_line(std::string str, int idx);
void setnonblocking(int sock);
void print_vector( std::vector<std::string> victor );

#endif
