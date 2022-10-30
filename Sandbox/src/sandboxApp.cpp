#include <bronx.h>

class Sandbox : public bronx::Application {
public:
	Sandbox()
	{

	};
	~Sandbox()
	{

	};
};

bronx::Application* bronx::createApplication()
{
	return new Sandbox();
};
