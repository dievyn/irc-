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

hint for CAP LS 302
https://medium.com/@leonardo_santangelo/implementing-an-irc-server-from-scratch-in-rust-d387e6850b6e

https://dd.ircdocs.horse/refs/numerics/001

https://modern.ircdocs.horse/

https://stackoverflow.com/questions/12886573/implementing-irc-rfc-how-to-respond-to-mode

https://dd.ircdocs.horse/refs/commands/join

http://chi.cs.uchicago.edu/chirc/irc_examples.html
http://chi.cs.uchicago.edu/chirc/index.html