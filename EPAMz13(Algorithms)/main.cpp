#include <chrono>
#include <iostream>
#include <algorithm>
#include <functional>

void mySort  (int* first);
int  myFind  (int* first, int* last, int elem);

int comp(const int* i, const int* j)
{
	return *i - *j;
}

void check(std::function<void(int[10])>&& func)
{
	int arr[]{ 1, 5924, 2, 76373, 9, 1235346, 3, 63243, 7, 1000 };
	// [ 1, 1, 1, 2, 3, 5, 6, 7, 7, 9 ]

	auto start{ std::chrono::high_resolution_clock::now() };

	func(arr);

	std::copy(arr, arr + 10, std::ostream_iterator<int>(std::cout, " "));

	auto end{ std::chrono::high_resolution_clock::now() };
	auto res{ end - start };
	std::cout << res.count() / 100000.0f << std::endl;
}

int main()
{
	check([](int arr[10]) { std::qsort(arr, 10, sizeof(int), (int(*) (const void*, const void*)) comp); });
	check([](int arr[10]) { std::sort(arr, arr + 10);                                                   });
	check([](int arr[10]) { std::find(arr, arr + 10, 9);                                                });
	check([](int arr[10]) { mySort(arr);                                                                });
	check([](int arr[10]) { mySort(arr); myFind(arr, arr + 10, 9);                                      });

	return 0;
}

void mySort(int* first)
{
	int* min{};
	for (int i{ 0 }; i < 10; ++i)
	{
		min = std::min_element(first + i, first + 10);
		std::swap(*min, first[i]);
	}
}
int myFind(int* first, int *last, int elem)
{
	int l = 0, r = std::distance(first, last) - 1;

	while (r > l) {
		int m = (l + r) / 2;    

		if (first[m] < elem) {
			l = m + 1;
		}
		else if (first[m] > elem) {
			r = m - 1;
		}
		else {
			return m;
		}
	}

	if (first[l] == elem) {
		return l;
	}
	else {
		return -1;
	}
}