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


int Server::Join(Client *client_obj, std::string command)
{
	std::string message;
	std::string new_chan = grab_new_channel(command);

	for(unsigned int i = 0; i < this->channels.size(); i++)
	{
		if (new_chan == this->channels[i])
		{
			client_obj->SetChannel(new_chan);
			message = client_obj->GetName() + " just joined " + client_obj->GetChannel() + " ! Say hi !\n";
			for (unsigned int i = 0; i < this->clients.size(); i++)
				if (this->clients[i].GetChannel() == client_obj->GetChannel())
					send(this->clients[i].GetFd(), message.c_str(), message.size(), 0);
			std::cout << "Client " << client_obj->GetName() << " just joined channel " << new_chan << ".\n";
			return 1;
		}
	}
	this->channels.push_back(new_chan);
	client_obj->SetChannel(new_chan);
	message = "You just created channel " + new_chan + "!\nInvite your friends with /INVITE !"
		+ "\nYou can change the topic of the channel using /TOPIC !\n"
		+ "Someone bothering you ? You can just /KICK them !\n"
		+ "Have fun discovering all the option of the /MODE command!\n";
	client_obj->SetCreatedChannels(new_chan);
	return 1;
}
