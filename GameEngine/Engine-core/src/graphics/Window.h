#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

namespace engine { namespace gfx {

		class Window {
		private:
			const char *title;
			int width, height;

			GLFWwindow *window;
		public:
			Window(const char* name, int width, int height);
			~Window();

			void clear() const;
			void update();
			bool isClosed() const;

			inline int getWidth() const { return width; }
			inline int getHeight() const { return height; }
		private:
			bool init();
		};

} }