#include <iostream>

std::string dup_command(char *buffer)
{
	std::string result;

	for (int i = 0; buffer[i] && buffer[i] != '\n' && buffer[i] != ' '; i++)
		result.push_back(buffer[i]);
	return result;
}

int check_commands(char *buffer)
{
	if (buffer[0] == '/')
	{
		std::string coms[] = {"/MSG", "/JOIN", "/NICK", "/KICK", "/TOPIC", "/INVITE"};
		std::string command = dup_command(buffer);
		std::cout << "Command: " << command << std::endl;
		if (command == coms[0] || command == coms[1]
			|| command == coms[2]
			|| command == coms[3]
			|| command == coms[4]
			|| command == coms[5])
			return std::cout << "It is a command!\n", 1;
	}
	return std::cout << "Not a command.\n", 0;
}

int main (void)
{
	char commande[] = "/KICK";
	std::string str1 = "/KICK";
	std::string str2;

	if (check_commands(commande) == 1)
		str2 = dup_command(commande);
	else
	{
		std::cout << "t deja dans la merde.\n";
		exit(0);
	}
	if (str1 == str2)
		std::cout << "oui";
	else
		std::cout << "T dans la merde.\n";
}