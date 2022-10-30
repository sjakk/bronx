#pragma once

#ifdef BRX_PLATFORM_WINDOWS

extern bronx::Application* bronx::createApplication();

int main()
{
	auto app = bronx::createApplication();

	app->run();
	delete app;

};

#else
#error JUST WINDOWS
#endif