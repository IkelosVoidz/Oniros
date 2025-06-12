#pragma once
#include "Oniros/Core/Window.h"
#include "Oniros/Core/Base.h"

#include "Oniros/Events/Event.h"
#include "Oniros/Events/ApplicationEvent.h"

namespace Oniros {
	class Application
	{
	public:
		Application(); 
		virtual ~Application();


		void Run();

	private:

		Scope<Window> m_Window;
		bool m_Running = true;

		void OnEvent(Event& event);
		bool OnWindowClose(WindowCloseEvent& event);
		bool OnWindowResize(WindowResizeEvent& event);
		
	};
}

