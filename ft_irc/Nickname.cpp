#include "ft_irc.hpp"

void Server::ChangeName(Client *client_obj, std::string name)
{
	std::string new_name;

	if (name.size() < 1)
	{ send(client_obj->GetFd(), "Invalid name: too short. Operation cannot succeed.\n", 53, 0); return ; }

	client_obj->GetName().clear();
	for (int i = 0; name[i] && name[i] != ' ' && name[i] != '\n' && name[i] != '\r'; i++)
		new_name.push_back(name[i]);
	client_obj->SetName(new_name);
}
