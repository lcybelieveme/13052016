///
///@date   2016-05-14 00:41:28
///
 
 

#include "Threadpool.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using std::cout;
using std::endl;

class Mytask
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
	Mytask task;

	wd::Threadpool threadpool(4,10);
	threadpool.start();


	int cnt=20;
	while(cnt-->0)
	{
		threadpool.addTask(std::bind(&Mytask::process,&task));
	//	cout<<" cnt = "<<cnt<<endl;
	}

//	sleep(5);
	cout<<"============"<<endl;
	return 0;
}
