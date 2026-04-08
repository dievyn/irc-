#include "ft_irc.hpp"

int skipSpace(std::string buffer)
{
	int i = 0;
	for (; buffer[i] && buffer[i] == ' ' && buffer[i] != '\r' && buffer[i] != '\n'; i++);
	return i;
}

int Server::PrivateMsg(Client *client_obj, std::string command)
{
	int i = 0;
	std::string homie;
	std::string message = "<Direct message from " + client_obj->GetName() + "> ";

	for (; command[i] && command[i] != ' ' && command[i] != '\r' && command[i] != '\n'; i++);
	i += skipSpace(&command[i]);
	for(; command[i] && command[i] != ' ' && command[i] != '\r' && command[i] != '\n'; i++)
		homie.push_back(command[i]);
	i += skipSpace(&command[i]);
	for(; command[i] && command[i] != '\r' && command[i] != '\n'; i++)
		message.push_back(command[i]);
	message.push_back('\n');
	
	for(unsigned int i = 0; i < this->clients.size(); i++)
		if (this->clients[i].GetName() == homie)
			return send(this->clients[i].GetFd(), message.c_str(), message.size(), 0), 1;
	message = homie + " isn't currently online or doesn't exist.\n";
	send(client_obj->GetFd(), message.c_str(), message.size(), 0);
	return 0;
}
