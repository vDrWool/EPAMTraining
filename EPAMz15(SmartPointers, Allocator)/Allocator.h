#pragma once
#include <iostream>
#include <memory>

namespace EPAM
{
	template<class T>
	class Allocator : public std::allocator<T>
	{
	public:
		T*   allocate(size_t size)
		{
			std::cout << "Allocated size = " << size << " \n";
			return new T[size];
		}	

		void deallocate(T* ptr, size_t size)
		{
			std::cout << "Deallocated size = " << size << " \n";
			delete[] ptr;
		}
	};
}