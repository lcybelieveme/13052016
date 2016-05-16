 ///
 /// @file    TimerThread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-05-14 11:39:31
 ///
 
#ifndef __MY_TIMER_TRHEAD_H__
#define __MY_TIMER_TRHEAD_H__

#include "Timer.h"
#include "Thread.h"

namespace wd
{

class TimerThread
{
public:
	typedef Timer::TimerCallback TimerThreadCallback;
	TimerThread(int initial_time, 
			    int interval_time,
				TimerThreadCallback cb);
	void start();
	void stop();
private:
	Timer _timer;
	Thread _thread;
};

}// end of namespace wd

#endif
