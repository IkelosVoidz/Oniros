#include "onipch.h"
#include "Application.h"

#include "Oniros/Events/KeyEvent.h"

#include <glad/glad.h> //Provisional 



namespace Oniros {
	Application::Application() {

		s_Instance = this;
		m_Window = Scope<Window>(Window::Create());
		m_Window->Init();
		m_Window->SetEventCallback(ONI_BIND_EVENT_FN(Application::OnEvent));


		m_ImGuiSystem = CreateScope<ImGuiSystem>();
		m_ImGuiSystem->Init();
	}

	Application::~Application() {

		//m_ImGuiSystem->Shutdown();
		m_Window->Shutdown();
		s_Instance = nullptr;
		ONI_CORE_INFO("Application destroyed");
	
	}

	void Application::Run() {
		while (m_Running) {
			m_Window->OnUpdate(); //TODO : rename to ProcessEvents , its basically what its doing, nothing more


			glClearColor(1.0f, 0.0f, 0.0f, 1.0f); //Provisional 
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			RenderUI(); //Render the UI, this is where we will render our ImGui stuff
			
			m_Window->SwapBuffers(); //This is the last thing that we have to do
		}
	}

	void Application::OnImGuiRender()
	{
		//TODO : REMOVE TEST
		static bool show = true;
		ImGui::ShowDemoWindow(&show);
	}

	void Application::OnEvent(Event& event) {
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(ONI_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(ONI_BIND_EVENT_FN(Application::OnWindowResize));

		/*ONI_CORE_TRACE("Event: {0}", event);*/
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

	void Application::RenderUI()
	{
		m_ImGuiSystem->Begin();
		OnImGuiRender(); //To be implemented by children applications
		m_ImGuiSystem->End();
	}
}
