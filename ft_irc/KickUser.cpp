#include "ft_irc.hpp"

int Server::KickUser(Client *client_obj, std::string name)
{
	std::string message;

	if (CheckPerms(client_obj) == 0)
	{
		message = "You are not admin of this channel. Therefore, you cannot use this command.\n";
		return send(client_obj->GetFd(), message.c_str(), message.size(), 0), 0;
	}
	if (name.size() < 1)
	{
		message = "No such user currently connected.\n";
		return send(client_obj->GetFd(), message.c_str(), message.size(), 0), 0;
	}
	for (unsigned int i = 0; i < this->clients.size(); i++)
	{
		if (this->clients[i].GetName() == name)
		{
			message = "You have been kicked out of " + this->clients[i].GetChannel() + " by an admin. You have been redirected to channel_1.\n";
			this->clients[i].SetChannel("channel_1");
			send(this->clients[i].GetFd(), message.c_str(), message.size(), 0);
			return 1;
		}
	}
	message = "No such user currently connected.\n";
	return send(client_obj->GetFd(), message.c_str(), message.size(), 0), 0;
}
