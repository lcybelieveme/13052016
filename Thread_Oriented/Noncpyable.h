///
///@date   2016-05-13 21:37:06
///
#ifndef __MY_NONCPYABLE_H__
#define __MY_NONCPYABLE_H__
#include <iostream>

namespace wd
{
class Noncpyable
{
protected:
	Noncpyable(){}
private:
	Noncpyable(const Noncpyable&);
	Noncpyable&operator=(const Noncpyable&);
};



}//endof namespace wd;

#endif
