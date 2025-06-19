#include <iostream>

int main()
{
	for (char c; std::cin >> c;) {
		std::cout << c << " " << static_cast<int>(c) << '\n';
	}
	return 0;
}
