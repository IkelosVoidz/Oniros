#include "onipch.h"
#include "Application.h"

namespace Oniros {
	Application::Application() {
		m_Window = Scope<Window>(Window::Create());
		m_Window->SetEventCallback(ONI_BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application() {}

	void Application::Run() {
		while (m_Running) {
			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& event) {
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(ONI_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(ONI_BIND_EVENT_FN(Application::OnWindowResize));
		ONI_CORE_TRACE("{0}", event);
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		/*if (e.GetWidth() == 0 || e.GetHeight() == 0)
		{
			m_Minimized = true;
			return false;
		}

		m_Minimized = false;
		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

		return false;*/

		return false;
	}
}
