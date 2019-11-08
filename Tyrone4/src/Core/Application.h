#pragma once
#include "Core.h"

namespace Tyrone4 {

	class TYRONE4_API Application {

	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();

}