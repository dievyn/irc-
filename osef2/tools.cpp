#include "ft_irc.hpp"

void setnonblocking(int sock)
{
	int flags;

	flags=fcntl(sock, F_GETFL, 0);  // DO CHECK ERRORS!
    flags |= O_NONBLOCK;
    flags=fcntl(sock, F_SETFL, flags);  // SERIOUSLY
}

std::string grab_line(std::string buffer)
{
	std::string new_line;

	for(int i = 0; buffer[i]; i++)
	{
		if (buffer[i] == '\r')
		{
			if (buffer[i + 1] == '\n')
			{
				new_line += "\r\n";
				return new_line;
			}
		}
		new_line.push_back(buffer[i]);
	}
	return new_line;
}

std::string grab_name(std::string buffer)
{
	int i = 0;
	std::string name;

	for(; buffer[i] && buffer[i] == ' '; i++)
	for(; buffer[i] && buffer[i] != ' ' && buffer[i] != '\n' && buffer[i] != '\r'; i++)
		name.push_back(buffer[i]);
	return name;
}

std::string grab_word(std::string buffer)
{
	std::string new_line;

	for(int i = 0; buffer[i] && buffer[i] != ' ' && buffer[i] != '\n' && buffer[i] != '\r'; i++)
		new_line.push_back(buffer[i]);
	return new_line;
}

int end_line(std::string str)
{
	if (str.size() <= 2)
		return 1;
	if (str[0] && str[0] == '\r')
		if (str[1] && str[1] == '\n')
			return 1;
	return 0;
}

void print_vector( std::vector<std::string> victor )
{
	std::cout << "Print vector:\n";
	for (unsigned int i = 0; i < victor.size(); i++)
		std::cout << victor[i];
}

void printAscii(std::string buffer)
{
	std::cout << "Buffer: <<";
	for (unsigned int i = 0; i < buffer.size(); i++)
	{
		unsigned char c = buffer[i];
		if (c == '\r') std::cout << "\\r";
		else if (c == '\n') std::cout << "\\n\n";
		else std::cout << buffer[i];
	}
	std::cout << ">>\n";
}
