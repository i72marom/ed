#include <iostream>
#include <vector>

int main() {
	std::vector <int> v;

	for (int i = 0; i < 100; ++i)
		v.push_back(i);

	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << std::endl;
}
