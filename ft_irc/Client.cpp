#include "ft_irc.hpp"

Client::Client( void )
{
	std::cout << "Client Constructor.\n"; 
	this->authenticate = false;
	this->current_channel = "channel_1";
}

int Client::GetFd( void )
{ return (this->client_fd); }

std::string Client::GetChannel( void )
{ return this->current_channel; }

std::string Client::GetName( void )
{ return this->nickname; }

bool Client::GetStatus( void )
{ return this->authenticate; }

void Client::SetFd( int fd )
{ this->client_fd = fd; }

void Client::SetChannel( std::string new_channel )
{ this->current_channel = new_channel; }

void Client::SetName( std::string name )
{ this->nickname = name; }

void Client::SetStatus( bool status )
{ this->authenticate = status; }
