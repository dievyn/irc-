#include "ft_irc.hpp"

Client::Client( int client_fd )
{ this->fd = client_fd; }

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

