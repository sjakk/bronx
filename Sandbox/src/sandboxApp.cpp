#include "bronx.h"
#include <stdio.h>
class Sandbox : public bronx::Application {
public:
	
};


bronx::Application* bronx::createApp() {
	return new Sandbox();
}
