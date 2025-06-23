#include "onipch.h"
#include "OpenGLContext.h"

#include <glad/glad.h>     
#include <SDL3/SDL.h> 

namespace Oniros {

 
    void OpenGLContext::Create()
    {
        ONI_CORE_INFO("OpenGLContext::Create");

        // Set attributes for the OpenGL context

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

        // Create OpenGL context
        m_Context = SDL_GL_CreateContext(m_WindowHandle);
        if (m_Context == NULL) {

            ONI_CORE_ERROR("Failed to create OpenGL context: {0}", SDL_GetError());
            return;
        }

        // Make the context current
        if (!SDL_GL_MakeCurrent(m_WindowHandle, m_Context))
        {
            ONI_CORE_ERROR("Failed to make OpenGL context current: {0}", SDL_GetError());
            return;
        }

        // Initialize GLAD (or your preferred OpenGL loader)
        if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
        {
            ONI_CORE_ERROR("Failed to initialize GLAD!");
            return;
        }

        ONI_CORE_INFO("OpenGL Info:");
        ONI_CORE_INFO("  Vendor: {0}", reinterpret_cast<const char*>(glGetString(GL_VENDOR)));
        ONI_CORE_INFO("  Renderer: {0}", reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
        ONI_CORE_INFO("  Version: {0}", reinterpret_cast<const char*>(glGetString(GL_VERSION)));
    }

    void OpenGLContext::Destroy()
    {
        if (m_Context) {
			SDL_GL_DestroyContext(m_Context);
			m_Context = nullptr;
        }
    }

    void OpenGLContext::SwapBuffers()
    {
        SDL_GL_SwapWindow(m_WindowHandle);
    }
    
}
