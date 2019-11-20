#pragma once
#include "Core.h"
#include "Event/Event.h"
#include "Window.h"

// Basic Application class to be inherited from by
// applications using Tyrone4.

namespace Tyrone4 {

	class TYRONE4_API Application {

	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in client.
	Application* CreateApplication();

}