///
///@date   2016-05-13 21:46:42
///
 
 
#include "Mutex.h"

namespace wd
{
Mutexlock::Mutexlock()
:_islocked(false)
{
	pthread_mutex_init(&_mutex,NULL);
}

Mutexlock::~Mutexlock()
{
	pthread_mutex_destroy(&_mutex);
}

void Mutexlock::lock()
{
	pthread_mutex_lock(&_mutex);
}

void Mutexlock::unlock()
{
	pthread_mutex_unlock(&_mutex);
}

pthread_mutex_t*Mutexlock::getMutex()
{
	return &_mutex;
}

}//endof namespace wd;
