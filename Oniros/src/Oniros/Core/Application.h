#pragma once

#include "Oniros/Core/Window.h"


namespace Oniros {

	class Application
	{
	public:
		Application(); 
		virtual ~Application();


		void Run();

	private:

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		void OnEvent(int& event);
	};
}

