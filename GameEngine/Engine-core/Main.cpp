#include <GLFW/glfw3.h>
#include <iostream>

int y = 0;

int main() {
	if (!glfwInit())
		std::cout << "damnit" << std::endl;
	else
		std::cout << "Hells yeah!" << std::endl;
	system("PAUSE");

	return 0;
}