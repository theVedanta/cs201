#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

template< class RandomIt >
void print(RandomIt start, RandomIt end) {
	while (start != end) {
		std::cout << *start << " ";
		++start;
	}
	std::cout << std::endl;
}

int main(int argc, char *argv[]) {
	int a0[] = {56, 23, 11, 64, 43, 99, 72, 88, 3, 31};
	std::array<int, 10> a1 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	std::array<std::string, 10> a2 = {"ant", "bear", "cat", "dog", "elephant", "fox", "goat", "horse", "iguana", "jaguar"};
	std::vector<double> v = {4.2, 3.1, 5.6, 2.8, 1.9, 7.4, 6.3, 8.5, 9.8, 10.1};

	std::sort(a0, a0+10);
	print(a0, a0+10);

	std::sort(&a0[0], &a0[10]);
	print(&a0[0], &a0[10]);

	std::sort(a1.begin(), a1.end());
	print(a1.begin(), a1.end());

	std::sort(a2.begin(), a2.end());
	print(a2.begin(), a2.end());

	std::reverse(a2.begin(), a2.end());
	print(a2.begin(), a2.end());

	std::sort(a2.begin(), a2.end());
	print(a2.begin(), a2.end());

	std::sort(v.begin(), v.end());
	print(v.begin(), v.end());

	return 0;
}

