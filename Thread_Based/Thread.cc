///
///@date   2016-05-15 20:54:11
///
 
 
#include "Thread.h"

namespace wd
{
Thread::Thread(Threadcallback cb)
:_cb(cb)
,_isrunning(false)
{
}

Thread::~Thread()
{
	if(_isrunning)
	{
		_isrunning=false;
		pthread_detach(_pId);
	}
}

void Thread::start()
{
	pthread_create(&_pId,NULL,ThreadFunc,this);
	_isrunning=true;
}

void Thread::join()
{
	if(_isrunning)
	{
		pthread_join(_pId,NULL);
		_isrunning=false;
	}
}

void*Thread::ThreadFunc(void*rhs)
{
	Thread*pt=static_cast<Thread*>(rhs);
	if(pt)
	{
		pt->_cb();
	}
}


}//endof namespace wd;
