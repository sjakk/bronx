#pragma once
#include "bronx/core.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


namespace bronx {
	class BRX_API  WindowBuffer
	{
	public:
		WindowBuffer();

		inline static void processInput(GLFWwindow* window);
		inline static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	};

}