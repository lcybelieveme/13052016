///
///@date   2016-05-13 21:51:09
///
 
#ifndef __MY_CONDITION_H__
#define __MY_CONDITION_H__
#include "Mutex.h"

namespace wd
{
class Condition:Noncpyable
{
public:
	Condition(Mutexlock&);
	~Condition();

	void wait();
	void notify();
	void notifyall();
private:
	Mutexlock& _mutex;
	pthread_cond_t _cond;
};



}//endof namespace ed;

#endif
