#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <string>
#include <utility>
#include <sys/types.h>
#include <sys/poll.h>
#include <sys/epoll.h>
#include <sys/time.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>

#include <sys/poll.h>

int main ( int argc, char **argv )
{
	int s1;
	int rv;
	char buf1[256], buf2[256];
	struct pollfd ufds[1];

	if (argc == 1)
		return std::cout << "bah nan\n", 1;

	s1 = socket(PF_INET, SOCK_STREAM, 0);
	// s2 = socket(PF_INET, SOCK_STREAM, 0);

	int n;
	struct sockaddr *addr = NULL;
	socklen_t addrlen;

	sockaddr_in serverAddress;
	memset(&serverAddress, 0, sizeof serverAddress);
	serverAddress.sin_family = PF_INET;
	serverAddress.sin_port = htons(atoi(argv[1]));
	serverAddress.sin_addr.s_addr = INADDR_ANY;

//	SOCK_STREAM = TCP
	std::cout << bind(s1, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) << "\n";

	std::cout << listen(s1, 5) << "\n";

	// set up the array of file descriptors.
	//
	// in this example, we want to know when there's normal or
	// out-of-band (OOB) data ready to be recv()'d...

	ufds[0].fd = s1;
	ufds[0].events = POLLIN | POLLPRI; // check for normal or OOB

	for (;;) {
	// wait for events on the sockets, 3.5 second timeout
	rv = poll(ufds, 1, 3500);

	if (rv == -1) {
		perror("poll"); // error occurred in poll()
	} else if (rv == 0) {
		printf("Timeout occurred! No data after 3.5 seconds.\n");
	} else {
		// check for events on s1:
		if (ufds[0].revents & POLLIN) {
			if (recv(s1, buf1, sizeof buf1, 0) > 0) // receive normal data
				std::cout << "message: " << buf1 << "\n";
		}
		if (ufds[0].revents & POLLPRI) {
			if (recv(s1, buf1, sizeof buf1, MSG_OOB) > 0) // out-of-band data
				std::cout << "message: " << buf1 << "\n";
		}
	}
}}