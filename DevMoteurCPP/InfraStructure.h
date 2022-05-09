#pragma once

#include <string>

namespace ESGI
{
	// Cores

	__declspec(dllexport) struct InfraStructure
	{
#if defined(_DEBUG)
		std::string m_DebugName;
		const std::string& DebugName() { return m_DebugName; }
#endif

		// on pourrait egalement ajouter des fonctions Create() & Destroy() 
		// si l'on souhaite controler les allocations memoires des classes "cores"

		__declspec(dllexport) virtual bool Initialize() = 0;
		__declspec(dllexport) virtual void DeInitialize() = 0;

	};
}