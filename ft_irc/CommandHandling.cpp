#include "ft_irc.hpp"


int Server::CheckPerms(Client *client_obj)
{
	for (unsigned int i = 0; i < client_obj->GetCreatedChannels().size(); i++)
	{
		std::cout << "Created channel: " << client_obj->GetCreatedChannels()[i] << "\n";
		if (client_obj->GetCreatedChannels()[i] == client_obj->GetChannel())
			return 1;
	}
	return 0;
}

std::string dup_command(std::string buffer)
{
	std::string result;

	for (int i = 0; buffer[i] && buffer[i] != '\n' && buffer[i] != '\r' && buffer[i] != ' '; i++)
		result.push_back(buffer[i]);
	return result;
}

std::string catch_name(std::string buffer)
{
	int i = 0;
	std::string name;

	for (i = 0; buffer[i] && buffer[i] != '\n' && buffer[i] != '\r' && buffer[i] != ' '; i++);
	i += skipSpace(&buffer[i]);
	for (; buffer[i] && buffer[i] != '\n' && buffer[i] != '\r'; i++)
		name.push_back(buffer[i]);
	return name;
}

int Server::check_commands(Client *client_obj, std::string buffer)
{
	if (buffer[0] == '/')
	{
		std::string coms[] = {"/MSG", "/JOIN", "/NICK", "/KICK", "/TOPIC", "/INVITE", "/MODE"};
		std::string command = dup_command(buffer);
		std::cout << "Command: " << command << std::endl;
		if (command == coms[0])
			return PrivateMsg(client_obj, buffer), 1;
		if (command == coms[1])
			return Join(client_obj, buffer), 1;
		if (command == coms[2])
			return ChangeName(client_obj, catch_name(buffer)), 1;
		if (command == coms[3])
			return KickUser(client_obj, catch_name(buffer)), 1;
		if (command == coms[5])
			return Invite(client_obj, catch_name(buffer)), 1;
	}
	return std::cout << "Client " << client_obj->GetName() << " sent \""
		<< buffer << "\" to channel " << client_obj->GetChannel() << ".\n", 0;
}


void print_ascii(std::string str)
{
	std::cout << "String to ascii";
	for (int i = 0; str[i] != '\0'; i++)
		std::cout << (int)str[i] << "-";
	std::cout << std::endl;
}

