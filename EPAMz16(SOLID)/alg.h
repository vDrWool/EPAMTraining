#pragma once
#include <stdexcept>
#include <concepts>

namespace EPAM
{
	//template<typename T>
	//concept Container = requires(T t)
	//{
	//	t.begin();      
	//	t.end();  
	//  t.size();
	//  t.clear();
	//	t.push_back();
	//};
	
	template<typename T>
	//	requires Container<T>
	void copy(T&& from, T&& to)
	{
		if (to.size() != 0)
			to.clear();
		
		auto iter{ from.begin() };
		auto last{ from.end()   };
		for (;iter != last; ++iter)
			to.push_back(*iter);
	}
}