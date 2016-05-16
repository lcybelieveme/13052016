///
///@date   2016-05-13 21:39:00
///

#ifndef __MY_MUTEX_H__
#define __MY_MUTEX_H__
#include "Noncpyable.h"
#include <pthread.h>

namespace wd
{
class Mutexlock:Noncpyable
{
public:
	Mutexlock();
	~Mutexlock();

	void lock();
	void unlock();
	pthread_mutex_t *getMutex();
private:
	pthread_mutex_t _mutex;
	bool _islocked;
};



}//endof namespace wd
#endif
