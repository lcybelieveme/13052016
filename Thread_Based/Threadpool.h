///
///@date   2016-05-15 21:07:28
///
 
#ifndef __MY_THREADPOOL_H__
#define __MY_THREADPOOL_H__
#include "Thread.h"
#include "Buffer.h"
#include <vector>
#include <functional>
using std::vector;
namespace wd
{
class Threadpool
{
public:
	typedef std::function<void()> Task;
	Threadpool(int ,int );
	~Threadpool();

	void start();
	void stop();
	void addTask(Task);
	Task getTask();
	void ThreadpoolFunc();

private:
	int _buffsize;
	int _Threadnum;
	vector<Thread*> _vecThread;
	Buffer<Task> _buff;
	bool _isexited;
};






}//endof namespace wd;
#endif
