#include "VoxelApplication.h"

int main(int argc, char* argv[])
{
	VoxelApplication* voxelApp = new VoxelApplication();
	voxelApp->Run();
	delete voxelApp;
}