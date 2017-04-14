#include <GLFW/glfw3.h>
#include <iostream>

#include "graphics\Window.h"

int main() {

	using namespace engine;
	using namespace gfx;

	Window window("Window!!", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	while (!window.isClosed()) {
		std::cout << window.getWidth() << ", " << window.getHeight() << std::endl;
		window.clear();

		glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-0.5f, -0.5f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f( 0.0f,  0.5f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();

		window.update();
	}


	return 0;
}