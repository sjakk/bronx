#pragma once
#include "log.h"

#include "Platform/OpenGL/windowBuffer.h"


#ifdef BRX_PLATFORM_WINDOWS

int main()
{
	
	auto* app = bronx::createApp();
	bronx::Log::Init();
	bronx::Log::GetCoreLogger()->info("Initialized bronx");
	bronx::Log::GetClientLogger()->warn("v1");
	app->run();
	delete app;
	
};

	#else
		#error JUST WINDOWS
#endif