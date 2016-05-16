///
///@date   2016-05-14 00:41:28
///
 
 

#include "Threadpool.h"
#include "Task.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using std::cout;
using std::endl;

class Mytask:public wd::Task
{
public:
	void process()
	{
		::srand(time(NULL));
		int num =::rand()%100;

		cout<<"produce :"<<num<<endl;

		::sleep(1);
	}
};

int main()
{
	wd::Task *pTask= new Mytask;

	wd::Threadpool threadpool(4,10);
	threadpool.start();

	int cnt=20;
	while(cnt-->0)
	{
		threadpool.addTask(pTask);
	//	cout<<" cnt = "<<cnt<<endl;
	}

//	sleep(5);
	cout<<"============"<<endl;
	return 0;
}
