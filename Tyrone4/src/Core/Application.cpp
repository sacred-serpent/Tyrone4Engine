#include "typch.h"
#include "Application.h"

#include "Event/ApplicationEvent.h"
#include "Log.h"

namespace Tyrone4 {

	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {

	}

	void Application::Run() {
		while (true) {
			m_Window->OnUpdate();
		}
	}

}