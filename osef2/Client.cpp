#include "ft_irc.hpp"

Client::Client( int client_fd )
{ this->fd = client_fd; this->authenticate = 0; }

void Client::SetUsername(std::string user)
{ this->username = user; }

void Client::SetNickname(std::string name)
{ this->nickname = name; }

void Client::SetFd(int client_fd)
{ this->fd = client_fd; }

void Client::SetChannel(std::string client_channel)
{ this->channel = client_channel; }

void Client::SetBuffer(std::string tmp_buffer)
{ this->buffer = tmp_buffer; }

std::string Client::GetUsername( void )
{ return this->username; }

std::string Client::GetNickname( void )
{ return this->nickname; }

int Client::GetFd( void )
{ return this->fd; }

std::string Client::GetChannel( void )
{ return this->channel; }

std::string Client::GetBuffer( void )
{ return this->buffer; }

// int is_special(char c)
// {
// 	if ((c > 90 && c < 97)
// 		|| c == '{' || c == '}'
// 		|| c == '|' || c == '-')
// 		return 1;
// 	return 0;
// }

// int is_nick_good(std::string name, std::vector<Client> client_list)
// {
// 	if (isalpha(name[0]))
// 	{
// 		for(unsigned int i = 1; i < name.size(); i++)
// 			if (!isalnum(name[i]) && is_special(name[i]) == 0)
// 				return -1;
// 		return 0;
// 	}
// 	return -1;
// }

void Server::register_nickname(int fd, std::string command)
{
	std::string name = grab_word(command, 2);
	std::string channel = this->client_list[find_fd(fd)].GetChannel();

	if (this->client_list[find_fd(fd)].GetStatus() > 0)
	{
		std::string message = ":" + this->client_list[find_fd(fd)].GetNickname() + "!"
			+ this->client_list[find_fd(fd)].GetUsername() + "@localhost " + command;
		for(unsigned int i = 0; i < this->client_list.size(); i++)
			if (this->client_list[i].GetChannel() == channel)
				send(this->client_list[i].GetFd(), message.c_str(), message.size(), 0);
		this->client_list[find_fd(fd)].SetNickname(name);
	}
	else
	{
		this->client_list[find_fd(fd)].SetNickname(name);
		this->client_list[find_fd(fd)].auth_increase();
	}
}
