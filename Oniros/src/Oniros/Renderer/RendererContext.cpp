#include "onipch.h"
#include "RendererContext.h"
#include "Oniros/Renderer/RendererAPI.h"
#include "Oniros/Platform/OpenGL/OpenGLContext.h"


namespace Oniros {

    Ref<RendererContext> Oniros::RendererContext::Create(SDL_Window* windowHandle)
    {
		switch (RendererAPI::GetCurrentAPI())
		{
		case RendererAPIType::None:    ONI_CORE_ERROR("Only OpenGL is supported!"); return nullptr;
		case RendererAPIType::OpenGL:  return CreateRef<OpenGLContext>(windowHandle);
		case RendererAPIType::Vulkan:  ONI_CORE_ERROR("Only OpenGL is supported!"); return nullptr;
		}
	
		return nullptr;
    }
}