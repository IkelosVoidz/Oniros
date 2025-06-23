#pragma once
#include "Oniros/Core/Window.h"
#include "Oniros/Core/Base.h"

#include "Oniros/Events/Event.h"
#include "Oniros/Events/ApplicationEvent.h"

#include "Oniros/ImGui/ImGuiSystem.h"

namespace Oniros {
	class Application
	{
	public:
		Application(); 
		virtual ~Application();


		void Run();

		inline Window& GetWindow() { return *m_Window; }

		static inline Application& Get() { return *s_Instance; }

		virtual void OnImGuiRender();

	private:

		Scope<Window> m_Window;
		Scope<ImGuiSystem> m_ImGuiSystem;


		bool m_Running = true;

		void OnEvent(Event& event);
		bool OnWindowClose(WindowCloseEvent& event);
		bool OnWindowResize(WindowResizeEvent& event);


		void RenderUI();


		inline static Application* s_Instance = nullptr;
	};
}

