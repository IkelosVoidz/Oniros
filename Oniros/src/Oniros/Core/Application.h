#pragma once
#include "Oniros/Core/Window.h"
#include "Oniros/Core/Base.h"

#include "Oniros/Events/Event.h"
#include "Oniros/Events/ApplicationEvent.h"

#include "Oniros/ImGui/ImGuiSystem.h"

namespace Oniros {

	struct ApplicationSpecification
	{
		std::string Name = "Oniros";
		uint32_t WindowWidth = 1600, WindowHeight = 900;
		bool WindowBorderless = false;
		bool Fullscreen = false;
		bool VSync = true;
		std::string WorkingDirectory;
		bool StartMaximized = true;
		bool Resizable = true;
		bool EnableImGui = true;
	};


	class Application
	{
	public:
		Application(const ApplicationSpecification& specification); 
		virtual ~Application();


		void Run();

		inline Window& GetWindow() { return *m_Window; }
		static inline Application& Get() { return *s_Instance; }


		//LifeCycle methods
		virtual void OnInit() {}
		virtual void OnUpdate(float deltaTime) {} //TODO : implement a delta time system
		virtual void OnShutdown() {}
		virtual void OnImGuiRender() {}

	private:

		void ProcessEvents();

		void OnEvent(Event& event);
		bool OnWindowClose(WindowCloseEvent& event);
		bool OnWindowResize(WindowResizeEvent& event);
		bool OnWindowMinimize(WindowMinimizeEvent& event);


		void RenderImGui();

	private:

		Scope<Window> m_Window;
		Scope<ImGuiSystem> m_ImGuiSystem;
		ApplicationSpecification m_Specification;


		bool m_Running = true, m_Minimized = false;
		inline static Application* s_Instance = nullptr;
	};
}

