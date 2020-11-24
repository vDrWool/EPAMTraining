#include "string.h"

int main()
{
	string s("hagabgnAaJBJHaJa");

	std::cout << s << std::endl;
	std::cout << s.changeA() << std::endl;
	std::cout << s << std::endl;

	return 0;
}