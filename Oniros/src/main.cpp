#define SDL_MAIN_HANDLED 
#include <SDL3/SDL.h>
#include <Oniros.h>

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

void SetVSync(bool enabled)
{
	if (enabled) {
		SDL_GL_SetSwapInterval(1);
	}
	else {
		SDL_GL_SetSwapInterval(0);
	}
}

WindowProps m_WindowData = (WindowProps("Oniros App", 1280, 720));

int main() {
	// Initialize the Oniros engine
	Oniros::Log::Init();
	// Log a welcome message
	ONI_INFO("Welcome to the Oniros Engine!");

	SDL_Window* m_Window = nullptr;
	SDL_GLContext m_Context = nullptr;


	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
		return 0;
	}

	// Create SDL window
	m_Window = SDL_CreateWindow(m_WindowData.Title.c_str(),
		m_WindowData.Width,
		m_WindowData.Height,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	if (!m_Window) {
		std::cerr << "Failed to create SDL window: " << SDL_GetError() << std::endl;
		return 0;
	}

	// Create OpenGL context
	m_Context = SDL_GL_CreateContext(m_Window);
	if (!m_Context) {
		std::cerr << "Failed to create OpenGL context: " << SDL_GetError() << std::endl;
		return 0;
	}

	// Enable VSync by default
	SetVSync(true);




	SDL_GL_SwapWindow(m_Window);

	if (m_Context) {
		SDL_GL_DestroyContext(m_Context);
	}
	if (m_Window) {
		SDL_DestroyWindow(m_Window);
	}
	SDL_Quit();
	
	return 0;
}