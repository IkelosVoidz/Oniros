#include "VoxelApplication.h"
#include <Oniros.h>


int main(int argc, char* argv[])
{
	Oniros::Log::Init();

	ONI_INFO("Welcome to the Voxel Engine!");


	Oniros::ApplicationSpecification specification;

	specification.Fullscreen = false;
	specification.Name = "Oniros Voxel Application";
	specification.WindowWidth = 1600;
	specification.WindowHeight = 900;
	specification.WindowBorderless = specification.Fullscreen;
	specification.Resizable = !specification.Fullscreen;
	specification.StartMaximized = true;
	specification.EnableImGui = true;


	VoxelApplication* voxelApp = new VoxelApplication(specification);
	voxelApp->Run();
	delete voxelApp;
}