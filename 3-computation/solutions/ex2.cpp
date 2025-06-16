#include <iostream>

int main()
{
	for (char c; std::cout << "> ";)
	{
        std::cin >> c;
        if (std::cin.eof()) break;
		std::cout << c << " " << static_cast<int>(c) << '\n';
	}
	return 0;
}
