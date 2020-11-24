#include <chrono>
#include <iostream>
#include <algorithm>
#include <functional>

void mySort  (int* first, int* last);
void mySearch(int* first, int* last, int elem);

int comp(const int* i, const int* j)
{
	return *i - *j;
}

void check(std::function<void(int[10])>&& func)
{
	int arr[]{ 1, 5, 2, 7, 9, 1, 3, 6, 7, 1 };

	auto start{ std::chrono::high_resolution_clock::now() };

	func(arr);

	auto end{ std::chrono::high_resolution_clock::now() };
	auto res{ end - start };
	std::cout << res.count() / 100000.0f << std::endl;
}

int main()
{
	check([](int arr[10]) { std::qsort(arr, 10, sizeof(int), (int(*) (const void*, const void*)) comp); });
	check([](int arr[10]) { std::sort(arr, arr + 10); });
	check([](int arr[10]) { std::search(arr, arr + 10, 9); });
	check([](int arr[10]) { mySort(arr, arr + 10); });
	check([](int arr[10]) { mySearch(arr, arr + 10, 9); });

	return 0;
}

void mySort(int* first, int* last)
{

}
void mySearch(int* first, int* last, int elem)
{

}