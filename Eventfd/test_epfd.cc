///
///@date   2016-05-16 21:18:23
///
 
 
#include "Event.h" 
#include "Thread.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <iostream>
using std::cout;
using std::endl;

struct Task
{
	void process()
	{
		::srand(::time(NULL));
		cout<<"produce : "<<rand()%100<<endl;		
	}
};

int main()
{
	Task task;
	wd::Event event(std::bind(&Task::process,&task));
	wd::Thread thread(std::bind(&wd::Event::start,&event));

	thread.start();
	while(1)
	{
		sleep(2);
		event.wakeup();
	}

	thread.join();

	return 0;
}
