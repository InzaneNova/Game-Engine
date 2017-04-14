#include "Window.h"

namespace engine {
	namespace gfx {

		void framebuffer_size_callback(GLFWwindow* window, int width, int height);

		Window::Window(const char* title, int width, int height) {
			this->title = title;
			this->width = width;
			this->height = height;

			if (!init())
				glfwTerminate();
		}

		bool Window::init() {
			if (!glfwInit()) {
				std::cout << "Failed to initialize GLFW." << std::endl;
				
				return false;
			}
			window = glfwCreateWindow(width, height, title, NULL, NULL);
			if (!window) {
				glfwTerminate();
				std::cout << "Failed to create window..." << std::endl;
				return false;
			}

			glfwMakeContextCurrent(window);

			glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

			return true;
		}

		Window::~Window() {
			glfwTerminate();
		}

		void Window::clear() const {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update() {
			glfwPollEvents();
			glfwSwapBuffers(window);
		}

		bool Window::isClosed() const {
			return glfwWindowShouldClose(window) == 1;
		}

		void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);
		}

	}
}