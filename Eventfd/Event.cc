///
///@date   2016-05-16 20:00:41
///
 
 
#include "Event.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <poll.h>
#include <sys/eventfd.h>
#include <errno.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int createfd()
{
	int fd=eventfd(0,0);
	if(-1==fd)
	{
		perror("eventfd()");
	}

	return fd;
}

namespace wd
{
Event::Event(Eventcallback cb)
:_cb(cb)
,_eventfd(createfd())
,_isStarted(false)
{}

Event::~Event()
{
	if(_isStarted)
	{
		stop();
	}
}

void Event::start()
{
	_isStarted=true;
	struct pollfd pfd;
	pfd.fd=_eventfd;
	pfd.events=POLLIN;

	while(_isStarted)
	{
		int ret=::poll(&pfd,1,500);
		if(-1==ret)
		{
			if(errno==EINTR)
				continue;
			exit(EXIT_FAILURE);
		}
		else if(0==ret)
		{
			cout<<"poll timeout\n";
		}
		else
		{
			if(pfd.revents==POLLIN)
			{
				handleRead();
				if(_cb)
					_cb();
			}
		}
	}
}

void Event::stop()
{
	if(_isStarted)
	{
		_isStarted=false;
	}
}

void Event::wakeup()
{
	uint64_t u=1;
	int ret=::write(_eventfd,&u,sizeof(u));
	if(sizeof(u)!=ret)
	{ perror("write"); }
}

void Event::handleRead()
{
	uint64_t u;
	int ret=::read(_eventfd,&u,sizeof(u));
	if(ret!=sizeof(u))
	{
		perror("read");
	}
}

}//endof namespace wd;
