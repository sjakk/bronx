#pragma once
#include "core.h"
#include "window.h"
namespace bronx {
	 class BRX_API Application
	{
	public:
		Application();
		void run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

	};


	 // defined in client
	 Application* createApp();
}