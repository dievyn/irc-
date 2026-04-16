#include "ft_irc.hpp"


std::string dup_command(char *buffer)
{
	std::string result;

	for (int i = 0; buffer[i] && buffer[i] != '\n' && buffer[i] != '\r' && buffer[i] != ' '; i++)
		result.push_back(buffer[i]);
	return result;
}


int Server::check_commands(Client *client_obj, char *buffer)
{
	if (buffer[0] == '/')
	{
		std::string coms[] = {"/MSG", "/JOIN", "/NICK", "/KICK", "/TOPIC", "/INVITE"};
		std::string command = dup_command(buffer);
		std::cout << "Command: " << command << std::endl;
		if (command == coms[0])
			return PrivateMsg(client_obj, buffer), 1;
		if (command == coms[1])
			return switch_channels(client_obj, buffer), 1;
	}
	return std::cout << "Not a command.(yet ?)\n", 0;
}


void print_ascii(std::string str)
{
	std::cout << "String to ascii";
	for (int i = 0; str[i]; i++)
		std::cout << (int)str[i] << "-";
	std::cout << std::endl;
}

