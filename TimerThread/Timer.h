 ///
 /// @file    timer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-05-14 10:56:46
 ///
 
#ifndef __MY_TIMER_H__
#define __MY_TIMER_H__
#include "Noncopyable.h"

#include <functional>

namespace wd
{
class Timer : Noncopyable
{
public:
	typedef std::function<void()> TimerCallback;
	Timer(int intial_time, 
		  int interval_time,
		  TimerCallback cb);
	~Timer();

	void start();
	void stop();
private:
	int _timerfd;
	int _intialTime;
	int _intervalTime;
	bool _isStarted;
	TimerCallback _cb;
};

}// end of namespace wd
#endif
