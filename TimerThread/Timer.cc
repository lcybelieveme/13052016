 ///
 /// @file    Timer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-05-14 10:59:28
 ///
 
#include "Timer.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <poll.h>
#include <sys/timerfd.h>

#include <iostream>
using std::cout;
using std::endl;

int createTimerFd()
{
	int fd = ::timerfd_create(CLOCK_REALTIME, 0);
	if(-1 == fd)
	{
		perror("timerfd_create error");
	}
	return fd;
}

void setTimerfd(int timerfd, int intial_time, int interval_time)
{
	struct itimerspec newTime;
	newTime.it_value.tv_sec = intial_time;
	newTime.it_value.tv_nsec = 0;
	newTime.it_interval.tv_sec = interval_time;
	newTime.it_interval.tv_nsec = 0;
	int ret = ::timerfd_settime(timerfd, 0, &newTime, NULL);
	if(-1 == ret)
	{
		perror("timerfd_settime error");
	}
}

void stopTimerfd(int timerfd)
{
	setTimerfd(timerfd, 0, 0);
}

int readTimerfd(int timerfd)
{
	uint64_t howmany;
	int ret = read(timerfd, &howmany, sizeof(uint64_t));
	if(ret != sizeof(uint64_t))
	{
		perror("read error");
	}
	return ret;
}



namespace wd
{

Timer::Timer(int intial_time, int interval_time, TimerCallback cb)
: _timerfd(createTimerFd())
, _intialTime(intial_time)
, _intervalTime(interval_time)
, _isStarted(false)
, _cb(cb)
{
}

void Timer::start()
{	
	setTimerfd(_timerfd, _intialTime, _intervalTime);
	_isStarted = true;

	struct pollfd pfd;
	pfd.fd = _timerfd;
	pfd.events = POLLIN;

	while(_isStarted)
	{
		int ret = ::poll(&pfd, 1, 5000);
		if(-1 == ret)
		{
			if(errno == EINTR)
				continue;
			exit(EXIT_FAILURE);
		}
		else if(0 == ret)
		{
			cout << "poll timeout!" << endl;
		}
		else
		{
			if(pfd.revents & POLLIN)
			{
				readTimerfd(_timerfd);
				if(_cb)
				{	_cb();	}//处理任务
			}
		}
	}
}


void Timer::stop()
{
	if(_isStarted)
	{
		::stopTimerfd(_timerfd);
		_isStarted = false;
	}
}

Timer::~Timer()
{
	if(_isStarted)
	{
		stop();
	}
}

	
}//end of namespace wd
