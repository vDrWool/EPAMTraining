#include <iostream>
#include <vector>

#include "smartPointer.h"
#include "Allocator.h"

int main()
{
	EPAM::unique_ptr<int> sm_ptr = EPAM::make_unique<int>(11);
	std::cout << *sm_ptr << '\n';

	std::vector<int, EPAM::Allocator<int>> vec;
	vec.push_back(15);

	EPAM::Allocator<int> a;
	int* ptr = a.allocate(4);
	a.deallocate(ptr, 4);
	
	return 0;
}