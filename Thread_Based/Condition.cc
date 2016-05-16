///
///@date   2016-05-13 21:54:46
///
 
 
#include "Condition.h"

namespace wd
{
Condition::Condition(Mutexlock& mutex)
:_mutex(mutex)
{
	pthread_cond_init(&_cond,NULL);
}

Condition::~Condition()
{
	pthread_cond_destroy(&_cond);
}

void Condition::wait()
{
	pthread_cond_wait(&_cond,_mutex.getMutex());
}

void Condition::notify()
{
	pthread_cond_signal(&_cond);
}

void Condition::notifyall()
{
	pthread_cond_broadcast(&_cond);
}

}//endof namespace wd;
