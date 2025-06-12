#pragma once
#include "Oniros/Core/Window.h"
#include "Oniros/Core/Base.h"
#include <SDL3/SDL.h>

namespace Oniros
{
	class SDLWindow : public Window
	{
	public:

		SDLWindow(const WindowProps& props = WindowProps());
		virtual ~SDLWindow();
		void OnUpdate() override;
		inline uint32_t GetWidth() const override { return m_WindowData.Width; };
		inline uint32_t GetHeight() const override { return m_WindowData.Height; }


		inline void SetEventCallback(const EventCallbackFn& callback) override { m_WindowData.EventCallback = callback; };
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
		
		virtual inline void* GetNativeWindow() const { return m_Window; }
		virtual void Initialize(const WindowProps& props);
		virtual void Shutdown();

	private:

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_WindowData;

		SDL_Window* m_Window;
		SDL_GLContext m_Context;
	};
}

