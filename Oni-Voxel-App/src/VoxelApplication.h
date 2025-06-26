#pragma once
#include <Oniros.h>

class VoxelApplication : public Oniros::Application
{
public:

	VoxelApplication(const Oniros::ApplicationSpecification& specification)
		: Application(specification)
	{
		
	}

	virtual void OnImGuiRender() override;

	virtual void OnUpdate(Oniros::DeltaTime deltaTime) override;
	
};

