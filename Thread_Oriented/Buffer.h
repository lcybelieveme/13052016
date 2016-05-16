///
///@date   2016-05-13 22:12:33
///
 
 
#include "Condition.h" 
#include <queue>

using std::queue;
namespace wd
{
template<typename T>
class Buffer
{
public:
	Buffer(int);
	~Buffer();

	bool full();
	bool empty();
	void push(T);
	T pop();
	void wakeall();
private:
	Mutexlock _mutex;
	Condition _notempty;
	Condition _notfull;
	queue<T> _que;
	int _quesize;
	bool _isempty;
};






template<typename T>
Buffer<T>::Buffer(int s)
:_mutex()
,_quesize(s)
,_notempty(_mutex)
,_notfull(_mutex)
,_isempty(true)
{
}

template<typename T>
Buffer<T>::~Buffer()
{
}

template<typename T>
bool Buffer<T>::full()
{
	return _quesize==_que.size();
}

template<typename T>
bool Buffer<T>::empty()
{
	return _que.size()==0;
}

template<typename T>
void Buffer<T>::push(T t)
{
	_mutex.lock();
	while(full())
	{
		_notfull.wait();
	}
	_que.push(t);
	_notempty.notify();
	_mutex.unlock();
}

template<typename T>
T Buffer<T>::pop()
{
	_mutex.lock();
	while(empty()&&_isempty)
	{
		_notempty.wait();
	}
	if(_isempty)
	{
		T t=_que.front();
		_que.pop();
		_notfull.notify();
		_mutex.unlock();
		return t;
	}
	else
	{
		_mutex.unlock();
		return NULL;
	}
}

template<typename T>
void Buffer<T>::wakeall()
{
	_isempty=false;
	_notempty.notifyall();
}

}//endof namespace wd;
