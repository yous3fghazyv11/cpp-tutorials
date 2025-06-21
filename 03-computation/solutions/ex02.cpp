#include <iostream>

int main()
{
	for (char c; std::cin >> c;) {
		std::cout << "\b:  " << static_cast<int>(c) << '\n';
	}
	return 0;
}
