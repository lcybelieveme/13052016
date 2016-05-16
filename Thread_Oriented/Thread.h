///
///@date   2016-05-13 22:59:18
///
 
#ifndef __MY_THREAD_H__
#define __MY_THREAD_H__
#include "Condition.h"

namespace wd
{
class Thread
{
public:
	Thread();
	~Thread();

	void start();
	void join();
	
	virtual void run()=0;
	static void* ThreadFunc(void*);
private:
	pthread_t _pId;
	bool _isrunning;
};




}//endof namespace wd;

#endif
