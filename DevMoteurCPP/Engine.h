#pragma once

#include "InfraStructure.h"

namespace ESGI
{
	// "forward declaration" d'une structure qui elle meme reference des classes
	// qui ne sont pas encore definies (fonctionne ici car il s'agit de pointeurs,
	// seul le typage interesse le compilateur dans ce cas)	
	__declspec(dllexport) struct EngineContext;
	class Scene;
	__declspec(dllexport) struct Engine : public InfraStructure
	{
		// Un exemple basique de sous-systeme du moteur (par ex. le moteur Behaviour)
		__declspec(dllexport) struct EngineSystem
		{
			double targetFrameRate = 1.0 / 60.0;
			double accumulatedTime = 0.0;
			int maxIterations = 2;

			bool Create() { return true; }
			void Destroy() {}
			bool Initialize() { return true; }
			void DeInitialize() {}
			void Update(float deltaTime) {}
			void FixedUpdate(float deltaTime) {}
		};

		// simple exemple, ou alors un vector ou une liste simplement chainee (intrusive) de systems
		EngineSystem* m_AIEngine;


		__declspec(dllexport) void ProcessSystems(double elapsedTime);

		// ---

		__declspec(dllexport) bool Initialize() final;

		__declspec(dllexport) void DeInitialize() final;

		// ce n'est pas une fonction virtuelle !
		__declspec(dllexport) void Update(EngineContext& context, Scene* scene);

	};
}
