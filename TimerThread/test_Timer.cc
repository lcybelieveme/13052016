 ///
 /// @file    test_Timer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-05-14 11:26:27
 ///
 
#include "TimerThread.h"
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;

struct Producer
{
	void product()
	{
		::srand(::time(NULL));
		int num = ::rand() %100;
		cout << "produce a number: " << num << endl;
	}
};

int main(void)
{
	Producer producer;
	wd::TimerThread timer(3, 6, std::bind(&Producer::product, &producer));
	timer.start();
	::sleep(20);
	timer.stop();
	return 0;
}
