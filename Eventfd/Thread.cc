///
///@date   2016-05-16 21:01:31
///
 
 
#include "Thread.h" 

namespace wd
{
Thread::Thread(Threadcallback cb)
:_cb(cb)
,_pId(0)
,_isStarted(false)
{}

Thread::~Thread()
{
	if(_isStarted)
	{
		_isStarted=false;
		pthread_detach(_pId);
	}
}

void Thread::start()
{
	pthread_create(&_pId,NULL,&ThreadFunc,this);
	_isStarted=true;
}

void Thread::join()
{
	if(_isStarted)
	{
		pthread_join(_pId,NULL);
		_isStarted=false;
	}
}

void* Thread::ThreadFunc(void*rhs)
{
	Thread*pth=static_cast<Thread*>(rhs);
	if(pth)
		pth->_cb();
}



}//endof namespace wd;
