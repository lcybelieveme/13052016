///
///@date   2016-05-13 23:51:23
///
 
 
#include "Thread.h"
#include "Threadpool.h"

namespace wd
{
class ThreadpoolThread:public Thread
{
public:
	ThreadpoolThread(Threadpool&);
	void run();
private:
	Threadpool &_Threadpool;
};



}//endof namespace wd;
