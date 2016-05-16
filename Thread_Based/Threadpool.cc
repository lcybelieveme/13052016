///
///@date   2016-05-15 21:13:52
///
 
 
#include "Threadpool.h"
#include <unistd.h>
namespace wd
{
Threadpool::Threadpool(int a,int b)
:_buffsize(b)
,_Threadnum(a)
,_buff(_buffsize)
,_isexited(false)
{
	_vecThread.reserve(_Threadnum);
}

Threadpool::~Threadpool()
{
	if(!_isexited)
	{
		stop();
	}
}

void Threadpool::start()
{
	for(int i=0;i<_Threadnum;++i)
	{
		Thread*pth=new Thread(std::bind(&Threadpool::ThreadpoolFunc,
					this));
		_vecThread.push_back(pth);
	}

	for(auto &pth:_vecThread)
	{
		pth->start();
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

		_buff.wakeall();
		_isexited=true;
		for(auto &pth:_vecThread)
		{
			pth->join();
			delete pth;
		}
	}
}

void Threadpool::addTask(Task t)
{
	_buff.push(t);
}

Threadpool::Task Threadpool::getTask()
{
	return _buff.pop();
}

void Threadpool::ThreadpoolFunc()
{
	while(!_isexited)
	{
		Task t=getTask();
		if(t)
			t();
	}
}









}//endof namespace wd;
