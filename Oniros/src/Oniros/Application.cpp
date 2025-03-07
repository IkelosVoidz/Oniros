#include <iostream> 
#include "Application.h"


namespace Oniros {
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		std::cout << "Hello from Oniros" << std::endl;
		while (true);
	}
}
