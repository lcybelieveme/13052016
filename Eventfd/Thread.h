///
///@date   2016-05-16 20:56:33
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
	Thread(Threadcallback cb);
	~Thread();

	void start();
	void join();
	static void* ThreadFunc(void*);
private:
	pthread_t _pId;
	Threadcallback _cb;
	bool _isStarted;
};



}//endof namespace wd;




#endif
