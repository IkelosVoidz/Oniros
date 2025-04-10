#include "onipch.h"
#include "Application.h"

namespace Oniros {
	Application::Application() {
		m_Window = std::make_unique<Window>(WindowProps("Oniros App", 1280, 720));
		m_Window->SetEventCallback([this](int& event) { OnEvent(event); });
	}

	Application::~Application() {}

	void Application::Run() {
		while (m_Running) {
			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(int& eventType) {
		if (eventType == 0) {
			std::cout << "Closing application...\n";
			m_Running = false;
		}
	}
}
