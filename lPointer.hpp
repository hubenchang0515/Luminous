/* lPointer.hpp - Pointer in C++
** https://github.com/hubenchang0515/Luminous
**
** Copyright (C) 2017 hubenchang0515
** Date    : 2017-8-15
** E-mail  : hubenchang0515@outlook.com
** Blog    : blog.kurukurumi.com
** LISENCE : LGPL v3.0
*/

#ifndef LUMINOUS_POINTER_HPP
#define LUMINOUS_POINTER_HPP

#include <stdint.h>
#include <cstddef>

/* Pointer */
class ptr_t
{
public:
	/* Convert from any kind of pointer */
	template<typename T>
	ptr_t(T ptr)
	{
		this->addr = static_cast<void*>(ptr);
	}
	
	template<typename T>
	ptr_t& operator = (T* ptr) 
	{ 
		this->addr = static_cast<void*>(ptr);
		return *this; 
	}
	
	
	/* Convert to any kind of pointer */
	template<typename T>
	operator T*() const 
	{ 
		return static_cast<T*>(addr); 
	}

	/* Pointer +  */
	ptr_t operator + (ptrdiff_t n)
	{
		uint8_t* p = static_cast<uint8_t*>(this->addr);
		p += n;
		return static_cast<ptr_t>(p);
	}

	/* Pointer - */
	ptr_t operator - (ptrdiff_t n)
	{
		uint8_t* p = static_cast<uint8_t*>(this->addr);
		p -= n;
		return static_cast<ptr_t>(p);
	}

	/* Compare with other ptr_t */
	friend bool operator == (ptr_t one, ptr_t another) 
	{ 
		return one.addr == another.addr; 
	}
	
	friend bool operator != (ptr_t one, ptr_t another) 
	{ 
		return one.addr != another.addr; 
	}

	/* Compare with other type can be converted to void* */
	template<typename T>
	friend bool operator == (ptr_t self,T ptr) 
	{ 
		return self.addr == static_cast<void*>(ptr); 
	}
	
	template<typename T>
	friend bool operator != (ptr_t self, T ptr) 
	{ 
		return self.addr != static_cast<void*>(ptr); 
	}
	
	template<typename T>
	friend bool operator == (T ptr, ptr_t self) 
	{ 
		return self.addr == static_cast<void*>(ptr); 
	}
	
	template<typename T>
	friend bool operator != (T ptr, ptr_t self) 
	{ 
		return self.addr != static_cast<void*>(ptr); 
	}


private:
	void* addr;
};

/* Const Pointer */
typedef const ptr_t cstptr_t;  
 
#endif // LUMINOUS_POINTER_HPP

