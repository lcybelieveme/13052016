///
///@date   2016-05-16 19:48:51
///
#ifndef __MY_NONCPYABLE_H__
#define __MY_NONCPYABLE_H__
 
namespace wd
{
class Noncpyable
{
protected:
	Noncpyable(){};
private:
	Noncpyable(const Noncpyable&rhs);
	Noncpyable&operator=(const Noncpyable&rhs);
};




}//endof namespace wd;

#endif
