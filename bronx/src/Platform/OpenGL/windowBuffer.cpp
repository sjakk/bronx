#include "Platform/OpenGL/windowBuffer.h"



namespace bronx 
{

	static bool s_GLFWInitialized = false;
	Window* Window::Create(const WindowProps& props) {
		return new WindowBuffer(props);
	}

	WindowBuffer::WindowBuffer(const WindowProps& props) {
		Init(props);
	}

	WindowBuffer::~WindowBuffer() {
		Shutdown();
	}


	void WindowBuffer::Init(const WindowProps& props) {
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		if (!s_GLFWInitialized) {
			int success = glfwInit();
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		setVSync(true);
	}


	void WindowBuffer::Shutdown() {
		glfwDestroyWindow(m_Window);
	}


	void WindowBuffer::onUpdate(){
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	
	}

	void WindowBuffer::setVSync(bool enabled) {
		if (enabled) {
			glfwSwapInterval(1);
		}
		else {
			glfwSwapInterval(0);
		}
		m_Data.VSync = enabled;
	}

	bool WindowBuffer::isVsync() const {
		return m_Data.VSync;
	}


}