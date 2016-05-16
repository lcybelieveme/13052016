///
///@date   2016-05-13 23:11:46
///
 
#ifndef __MY_THREADPOOL_H__
#define __MY_THREADPOOL_H__
#include "Buffer.h"
#include "Thread.h"

#include <vector>
using std::vector;

namespace wd
{
class Task;
class Thread;
class Threadpool
{
public:
	Threadpool(int,int);
	~Threadpool();

	void start();
	void stop();
	void ThreadpoolFunc();

	void addTask(Task*);
	Task*getTask();
private:
	int _threadnum;
	int _quesize;
	Buffer<Task*> _buff;
	vector<Thread*> _vecThread;
	bool _isexited;
};




}//endof namespace wd;

#endif
