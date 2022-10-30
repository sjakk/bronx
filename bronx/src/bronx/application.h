#pragma once
#include "core.h"
namespace bronx {
	 class BRX_API Application
	{
	public:
		Application()
		{

		};
		virtual ~Application()
		{

		};


		void run();
	};
	 Application* createApplication();
};