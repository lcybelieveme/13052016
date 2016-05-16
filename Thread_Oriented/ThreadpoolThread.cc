///
///@date   2016-05-13 23:54:54
///
 
 
#include "ThreadpoolThread.h"

namespace wd
{
ThreadpoolThread::ThreadpoolThread(Threadpool&rhs)
:_Threadpool(rhs)
{}

void ThreadpoolThread::run()
{
	_Threadpool.ThreadpoolFunc();
}



}//endof namespace wd;
