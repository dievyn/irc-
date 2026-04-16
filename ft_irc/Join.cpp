#include "ft_irc.hpp"

std::string grab_new_channel(std::string command)
{
	std::string result;
	int i = 0;
	for (i = 0; command[i] && command[i] != ' ' && command[i] != '\n' && command[i] != '\r'; i++);
	for (; command[i] && command[i] == ' ' && command[i] != '\n' && command[i] != '\r'; i++);
	for (; command[i] && command[i] != ' ' && command[i] != '\n' && command[i] != '\r'; i++)
		result.push_back(command[i]);
	return result;
}


int Server::switch_channels(Client *client_obj, std::string command)
{
	std::string message;
	std::string new_chan = grab_new_channel(command);
	if (new_chan == this->channels[0]
		|| new_chan == this->channels[1]
		|| new_chan == this->channels[2])
	{
		client_obj->SetChannel(new_chan);
		message = client_obj->GetName() + " just joined " + client_obj->GetChannel() + " ! Say hi !\n";
		for (unsigned int i = 0; i < this->clients.size(); i++)
			if (this->clients[i].GetChannel() == client_obj->GetChannel())
				send(this->clients[i].GetFd(), message.c_str(), message.size(), 0);
		return 1;
	}
	return send(client_obj->GetFd(), "No such channel. Try again.\n", 30, 0), -1;
}
