#include "application.h"
#include "bronx/Events/applicationEvent.h"
#include "bronx/log.h"
#include <GLFW/glfw3.h>

namespace bronx {
	
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}


	void Application::run() {
		while (m_Running);
		glClearColor(1, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		m_Window->onUpdate();
	}
	
}