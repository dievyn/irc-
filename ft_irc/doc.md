basic socket programming:
https://www.geeksforgeeks.org/cpp/socket-programming-in-cpp/

non blocking fd flag:
O_NONBLOCK


Each time a client tries to connect, we use "accept", this will create a new fd that will correspond to this user's socket.

TLS/IPv4 : PF_INET

basics of sockets
https://berthub.eu/simplesocket/md_socket-api.html

accept() creates a new socket for a client and returns its descriptor.

beej:
https://beej.us/guide/bgnet/html/split/man-pages.html#recvman


QUESTIONS :

- error 107 ??
- Connection etablished, pas de message
- chaques salons du serveur = 1 fd ?
- une socket par client
- on attends une communication, 
	si le fd correspond pas a la database = nouveau client
  else
	message dans salon
- classe client : 	- nom
					- fd salon
					- fd client
- classe serveur :	- fd serveur (duh)
					- tab clients
					- tab salons ?
					- password

	// setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

ssl protocol ??
https://youtu.be/cY3jLY3c0tk?si=PWFBdediA_ckPaCs
