#include "onipch.h"
#include "Application.h"

#include "Oniros/Events/KeyEvent.h"
#include "Oniros/Core/Input.h"

#include <glad/glad.h> //Provisional 



namespace Oniros {


	Application::Application(const ApplicationSpecification& specification) : m_Specification(specification) {


		s_Instance = this;

		WindowProps props;

		props.Title = m_Specification.Name;
		props.Width = m_Specification.WindowWidth;
		props.Height = m_Specification.WindowHeight;
		props.Borderless = m_Specification.WindowBorderless;
		props.Fullscreen = m_Specification.Fullscreen;
		props.VSync = m_Specification.VSync;
		props.Resizable = m_Specification.Resizable;

		m_Window = Scope<Window>(Window::Create(props));
		m_Window->Init();
		m_Window->SetEventCallback(ONI_BIND_EVENT_FN(Application::OnEvent));


		if (specification.StartMaximized)
			m_Window->Maximize();
		else
			m_Window->CenterWindow();

		m_Window->SetResizable(specification.Resizable);

		m_ImGuiSystem = CreateScope<ImGuiSystem>();
			m_ImGuiSystem->Init();
		
	}

	Application::~Application() {

		m_ImGuiSystem->Shutdown();
		m_Window->Shutdown();
		s_Instance = nullptr;
		ONI_CORE_INFO("Application destroyed");
	
	}

	void Application::Run() {

		OnInit(); //To be implemented by children applications
		while (m_Running) {
			
			ProcessEvents();

			OnUpdate(0.0f); //TODO : Implement a delta time system, this is just a placeholder

			if (!m_Minimized) //If the window is not minimized, we can render
			{
				glClearColor(0.1f, 0.1f, 0.1f, 1.0f); //Provisional 
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



				//Render the UI, this is where we render our ImGui stuff that has been declared on the clients
				if(m_Specification.EnableImGui) RenderImGui(); 
				m_Window->SwapBuffers(); //This is the last thing that we have to do
			}

			Input::ResetInputStates(); //We clear all the input states that have been released so that they're not taken into consideration for the next frame
		}
		OnShutdown(); //To be implemented by children applications
	}

	void Application::ProcessEvents()
	{

		//Custom way of handling pressed to held states, we only want pressed to be 1 frame, so we manually transition to held after the first frame
		Input::TransitionKeyStates();
		Input::TransitionMouseButtonStates();
		m_Window->ProcessEvents();
	}

	void Application::OnEvent(Event& event) {
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(ONI_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowMinimizeEvent>(ONI_BIND_EVENT_FN(Application::OnWindowMinimize));
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

	bool Application::OnWindowMinimize(WindowMinimizeEvent& event)
	{
		m_Minimized = event.IsMinimized();
		return false;
	}

	void Application::RenderImGui()
	{
		m_ImGuiSystem->Begin();
		OnImGuiRender(); //To be implemented by children applications
		m_ImGuiSystem->End();
	}
}
