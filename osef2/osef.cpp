#include "ft_irc.hpp"

#define MAX_EVENTS 10
           struct epoll_event ev, events[MAX_EVENTS];
           int listen_sock, conn_sock, nfds, epollfd;

int main( int argc, char **argv )
{
	if (argc != 3)
		return 0;

	Server serv(atoi(argv[1]), argv[2]);
	serv.SerSocket();
	serv.Run();    
}
