///
///@date   2016-05-13 23:36:34
///
 
#include "Task.h" 
#include "Threadpool.h"
#include "ThreadpoolThread.h"
#include <unistd.h>
using std::cout;
using std::endl;


namespace wd
{
Threadpool::Threadpool(int a,int b)
:_threadnum(a)
,_quesize(b)
,_buff(_quesize)
,_isexited(false)
{
	_vecThread.reserve(_threadnum);
}

Threadpool::~Threadpool()
{
	if(!_isexited)
		stop();
}

void Threadpool::start()
{
	for(int i=0;i<_threadnum;++i)
	{
		Thread*pth=new ThreadpoolThread(*this);
		_vecThread.push_back(pth);
	}
	for(	vector<Thread*>::iterator it=
			_vecThread.begin();
			it!=_vecThread.end();
			++it)
	{
		(*it)->start();
	}
}

void Threadpool::stop()
{
	if(!_isexited)
	{
		while(!_buff.empty())
		{
			sleep(1);
		}

		_isexited=true;
		_buff.wakeall();

		for(auto &elem:_vecThread)
		{
			elem->join();
			delete elem;
		}
	}
}

void Threadpool::ThreadpoolFunc()
{
	while(!_isexited)
	{
		Task*pt=getTask();
//		cout<<"getTask()"<<endl;
		if(pt)
			pt->process();
	}
}
	
void Threadpool::addTask(Task *t)
{
	_buff.push(t);
}

Task*Threadpool::getTask()
{
	Task*ta=_buff.pop();
	return ta;
}

}//endof namespace wd;
