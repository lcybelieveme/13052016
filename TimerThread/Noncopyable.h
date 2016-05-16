 ///
 /// @file    Noncopyable.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-05-12 14:50:43
 ///
 
#ifndef __MY_NONCOPYABLE_H__
#define __MY_NONCOPYABLE_H__


namespace wd
{
class Noncopyable
{
protected:
	Noncopyable(){}
private:
	Noncopyable(const Noncopyable & rhs);
	Noncopyable & operator=(const Noncopyable & rhs);
};
}// end of namespace wd

#endif
