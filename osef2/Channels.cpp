#include "ft_irc.hpp"

void Server::joined_channel(int fd, std::string command)
{
	int client_id = find_fd(fd);
	std::string channel = grab_word(command, 2);
	this->client_list[client_id].SetChannel(channel);
	std::string client_name = this->client_list[client_id].GetNickname();
	std::string client_username = this->client_list[client_id].GetUsername();


	std::string message = ":" + client_name
		+ "!" + client_username + "@localhost " + command;
	send (fd, message.c_str(), message.size(), 0);

	message = ":myserver 353 " + client_name + " = "
		+ channel + " :@" + client_name + "\r\n";
	send (fd, message.c_str(), message.size(), 0);

	
	message = ":myserver 366 " + client_name + channel
		+ " :End of /NAMES list.\r\n";
	send (fd, message.c_str(), message.size(), 0);


	message = ":" + client_name + "!" + client_username + "@localhost " + command;
	for (unsigned int i = 0; i < this->client_list.size(); i++)
		if (this->client_list[i].GetChannel() == channel && fd != this->client_list[i].GetFd())
			send(this->client_list[i].GetFd(), message.c_str(), message.size(), 0);


	std::cout << "--- " << client_name
		<< " joined channel " << channel << "\n";

//	->  joining a channel
//	:alice!~a@localhost JOIN #test

//	->  lists users in channel:
//	:irc.example.com 353 dan = #test :@dan
//	or
//	:irc.example.com 353 alice @ #test :alice @dan
//	and
//  :irc.example.com 366 dan #test :End of /NAMES list.

//	332 - 333 -> topic je m'en fous completement
}

std::string extract_text(std::string message)
{
	unsigned int i = 0;
	std::string text;

	for (; i < message.size() && message[i] != ':'; i++);
	for(; i < message.size() && end_line(message, i) == 0; i++)
		text.push_back(message[i]);
	return text;
}

void Server::send_to_channel(int fd, std::string message)
{
	std::string channel = grab_word(message, 2);
	std::string text = grab_word(message, 3);
	std::string client_name = this->client_list[find_fd(fd)].GetNickname();
	std::string client_username = this->client_list[find_fd(fd)].GetUsername();

	for (unsigned int i = 0; i < this->client_list.size(); i++)
	{
		std::string retweet = ":" + client_name + "!" + client_username + "@localhost " + message + "\r\n";
		std::cout << "--- Message sent by SERVER " << retweet;
		if (this->client_list[i].GetChannel() == channel 
			&& this->client_list[i].GetFd() != fd)
			send(this->client_list[i].GetFd(), retweet.c_str(), retweet.size(), 0);
	}
}

void Server::send_to_user(int fd, std::string message)
{
	std::string username = grab_word(message, 2);
	int friend_idx = find_username(username);
	int friend_fd = this->client_list[friend_idx].GetFd();

	std::string retweet = ":" + this->client_list[find_fd(fd)].GetNickname() + "!tdenis@localhost " + message + "\r\n";
	std::cout << "--- Message sent by SERVER to "
		<< this->client_list[find_fd(fd)].GetNickname() << " " << retweet;
	send(friend_fd, retweet.c_str(), retweet.size(), 0);
}

void Server::send_message(int fd, std::string message)
{
	std::string tmp = grab_word(message, 2);
	std::string text = grab_word(message, 3);

	if (tmp == "")
	{
		tmp = ":myserver 411 " + this->client_list[find_fd(fd)].GetNickname() + "!tdenis@localhost : no message to be sent\r\n";
		send(fd, tmp.c_str(), tmp.size(), 0);
	}
	if (tmp[0] == '#')
		send_to_channel(fd, message);
	else
		send_to_user(fd, message);
}

//	:nickname!username@localhost