/* lPointer.hpp - Pointer
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

/* Pointer */
class ptr_t
{
public:
	/* Create by any kind of pointer */
	template<typename T>
	ptr_t(T* ptr) : addr(ptr) {}
	
	/* Transport to any kind of pointer */
	template<typename T>
	operator T*() const { return static_cast<T*>(addr); }

	/* Assign by any kind of pointer */
	template<typename T>
	ptr_t& operator = (T* ptr) { this->addr = static_cast<void*>(ptr); return *this; }

	/* Compare with class can be tranported to void* */
	bool operator == (ptr_t another) const { return addr == another.addr; }
	bool operator != (ptr_t another) const { return addr != another.addr; }

	/* Compare with nullptr in C++11 */
#if __cplusplus >= 201103L  // C++11
	friend bool operator == (ptr_t self, std::nullptr_t ptr) { return self.addr == ptr; }
	friend bool operator == (std::nullptr_t ptr, ptr_t self) { return self.addr == ptr; }
	friend bool operator != (ptr_t self, std::nullptr_t ptr) { return self.addr != ptr; }
	friend bool operator != (std::nullptr_t ptr, ptr_t self) { return self.addr != ptr; }
#endif // C++11

private:
	void* addr;
};

/* Const Pointer */
typedef const ptr_t cstptr_t;   
#endif // LUMINOUS_POINTER_HPP
