#pragma once

#include "Oniros/Core/Base.h"

namespace Oniros
{
	struct WindowProps
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProps(const std::string& title = "Oniros Engine",
			uint32_t width = 1600,
			uint32_t height = 900)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	class Window
	{
	public:

		using EventCallbackFn  = std::function<void(int&)>; //TODO :replace with Event TYPE
		
		Window(const WindowProps& props = WindowProps());
		~Window();
		void OnUpdate();
		uint32_t GetWidth();
		uint32_t GetHeight();


		// Window attributes
		void SetEventCallback(const EventCallbackFn&);
		void SetVSync(bool enabled);
		bool IsVSync();


	private:

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_WindowData;
	};
}

