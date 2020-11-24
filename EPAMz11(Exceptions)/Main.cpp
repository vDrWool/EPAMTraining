#include <iostream>
#include <queue>

#include "Task1.h"
#include "Queue.h"

int main()
{
	/*{
		try
		{
			EPAM::numberAnalise("+7(029)555-35-35");
			EPAM::devide(1, 0);
		}
		catch (const EPAM::invalid_number& err)
		{
			std::cerr << err.what() << '\n';
		}
		catch (const std::runtime_error& err)
		{
			std::cerr << err.what() << '\n';
		}
	}*/
	{
		EPAM::Queue<int> a;
		a.push(11);
		a.push(22);
		a.push(33);
		a.push(44);
		a.push(55);

		std::cout << a << '\n';

		a.pop();
		
		std::cout << a << '\n';

		EPAM::Queue<char> b;
		b.push('a');
		b.push('b');
		b.push('c');
		b.push('d');
		b.push('e');

		std::cout << b << '\n';

		b.pop();
		b.pop();

		std::cout << b << '\n';

		EPAM::Queue<std::string> c;
		c.push("aaa");
		c.push("bbb");
		c.push("ccc");
		c.push("ddd");
		c.push("eee");

		std::cout << c << '\n';

		c.pop();
		c.pop();
		c.pop();

		std::cout << c << '\n';
	}

	return 0;
}