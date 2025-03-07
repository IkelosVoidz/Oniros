#include "VoxelApplication.h"
#include <Oniros.h>


int main(int argc, char* argv[])
{
	Oniros::Log::Init();


	ONI_INFO("Welcome to the Voxel Engine!");

	VoxelApplication* voxelApp = new VoxelApplication();
	voxelApp->Run();
	delete voxelApp;
}