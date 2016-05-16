 ///
 /// @file    TimerThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-05-14 11:42:13
 ///
 
#include "TimerThread.h"
#include <iostream>
using std::cout;
using std::endl;


namespace wd
{

TimerThread::TimerThread(int inital_time,
						 int interval_time,
						 TimerThreadCallback cb)
: _timer(inital_time, interval_time, cb)
, _thread(std::bind(&Timer::start, &_timer))
{
}

void TimerThread::start()
{
	_thread.start();
}

void TimerThread::stop()
{
	_timer.stop();
	_thread.join();
}

}// end of namesapce 
