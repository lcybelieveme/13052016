///
///@date   2016-05-16 19:50:53
///
 
#ifndef __MY_EVENT_H__
#define __MY_EVENT_H__
#include "Noncpyable.h"
#include <iostream>
#include <functional>
namespace wd
{
class Event:Noncpyable
{
public:
	typedef std::function<void()> Eventcallback;
	Event(Eventcallback cb);
	~Event();
	
	void wakeup();
	void handleRead();
		
	void start();
	void stop();

private:
	int _eventfd;
	Eventcallback _cb;
	bool _isStarted;
};




}//endof namespace wd;
#endif
