///
///@date   2016-05-15 20:48:23
///
 
#ifndef __MY_THREAD_H__
#define __MY_THREAD_H__
#include <pthread.h> 
#include <functional>
namespace wd
{
class Thread
{
public:
	typedef std::function<void()> Threadcallback;
	Thread(Threadcallback );
	~Thread();

	void start();
	void join();
	static void* ThreadFunc(void*);
private:
	Threadcallback _cb;
	pthread_t _pId;
	bool _isrunning;
};




}//endof namespace wd;

#endif 
