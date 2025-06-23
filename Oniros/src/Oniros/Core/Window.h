#pragma once

#include "Oniros/Core/Base.h"
#include "Oniros/Events/Event.h"
#include "Oniros/Renderer/RendererContext.h"

namespace Oniros
{
	struct WindowProps
	{
		std::string Title = "Oniros Engine";
		uint32_t Width = 1600;
		uint32_t Height = 900;
		bool Fullscreen = false;
		bool Borderless = false;
		bool Resizable = true;
		bool VSync = true;	
	};

	class Window
	{
	public:

		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void Init() = 0;
		virtual void Shutdown() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual std::pair<uint32_t, uint32_t> GetSize() const = 0;
		virtual std::pair<float, float> GetWindowPos() const = 0;

		virtual void Maximize() = 0;
		virtual void CenterWindow() = 0;

		virtual void OnUpdate() = 0;
		virtual void SwapBuffers() = 0; //Always to be called after on update and after rendering pass

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

		//Window properties
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;
		virtual void SetResizable(bool resizable) = 0;
		virtual bool isResizable() const = 0;
		virtual void SetFullscreen(bool enabled) = 0;
		virtual bool IsFullscreen() const = 0;
		virtual void SetBorderless(bool enabled) = 0;
		virtual bool IsBorderless() const = 0;

		virtual const std::string& GetTitle() const = 0;
		virtual void SetTitle(const std::string& title) = 0;


		virtual void* GetNativeWindow() const = 0;
		virtual Ref<RendererContext> GetRenderContext() = 0;


		static Window* Create(const WindowProps& props = WindowProps());

	};
}

