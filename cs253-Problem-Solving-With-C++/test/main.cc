#include <iostream>
#include <filesystem>

using namespace std::filesystem;

int main() {
	path a("12"), b("3");
	std::cout << a/b;


	return 0;
}

