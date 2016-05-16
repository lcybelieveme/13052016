///
///@date   2016-05-13 23:02:53
///
 
 
#include "Thread.h"

namespace wd
{
Thread::Thread()
:_pId(0)
,_isrunning(false)
{}

Thread::~Thread()
{
	if(_isrunning)
	{
		pthread_detach(_pId);
		_isrunning=false;
	}
}

void Thread::start()
{
	_isrunning=true;
	pthread_create(&_pId,NULL,&ThreadFunc,this);
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
	Thread*pth=static_cast<Thread*>(rhs);
	if(pth)
		{
			pth->run();
		}
}



}//endof namespace wd;
