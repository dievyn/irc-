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

int is_space(char c)
{
	if (c == '\v' || c == '\f' || c < 12
		|| (c > 15 && c < 32))
		return 1;
	return 0;
}

std::string grab_word(std::string buffer, int word_idx)
{
	std::string new_line;
	int words_detected = 0;
	unsigned int i = 0;

	word_idx--;
	for (; buffer[i] && words_detected < word_idx; i++)
	{
		for (; buffer[i] < 33; i++);
		for (; buffer[i] > 33 && buffer[i] < 127; i++);
		words_detected++;
	}
	if (buffer.size() == 0)
		return "";
	for(; buffer[i] && buffer[i] > 33 && buffer[i] < 127; i++)
		new_line.push_back(buffer[i]);
	return new_line;
}

int end_line(std::string str, int idx)
{
	if (str.size() <= 2)
		return 1;
	if (str[idx] && str[idx] == '\n')
		if (str[idx - 1] && str[idx - 1] == '\r')
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
	for (unsigned int i = 0; i < buffer.size(); i++)
	{
		unsigned char c = buffer[i];
		if (c == '\r')
			std::cout << "\\r";
		else if (c == '\n')
			std::cout << "\\n\n";
		else
			std::cout << buffer[i];
	}
}

void Server::disconnect(int fd)
{
	std::vector<Client>::iterator cl_it = this->client_list.begin();
	int it = find_fd(fd);
	std::string room = this->client_list.at(it).GetChannel();
	std::string message = ":" + this->client_list[it].GetNickname()
		+ "!tdenis@localhost PART " + this->client_list[it].GetChannel() + "\r\n";

	std::cout << "Disconnecting user " << this->client_list[it].GetNickname() << "\n";
	for(int i = 0; i < it; i++)
		cl_it++;

	for (unsigned int i = 0; i < this->client_list.size(); i++)
		if (this->client_list[i].GetChannel() == room 
			&& this->client_list[i].GetFd() != fd)
			send(this->client_list[i].GetFd(), message.c_str(), message.size(), 0);
	close(fd);
	this->client_list.erase(cl_it);
}

int Server::find_username(std::string username)
{
	for (unsigned int i = 0; i < this->client_list.size(); i++)
		if (this->client_list[i].GetNickname() == username)
			return i;
	return -1;
}

void Server::check_password(int fd, std::string message)
{
		std::cout << "Reading password: ";
		printAscii(grab_word(message, 2));
		std::cout << "\n";
		if (grab_word(message, 2) != this->password)
		{
			std::cout << "------- PASSWORD !\n";
			std::string message = ":myserver 464 " + this->client_list[find_fd(fd)].GetNickname() + " :Password incorrect\r\n";
			send(fd, message.c_str(), message.size(), 0);
			close(fd);
		}
}
