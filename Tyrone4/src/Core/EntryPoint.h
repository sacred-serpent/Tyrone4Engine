#pragma once

#ifdef TY_PLATFORM_WINDOWS

extern Tyrone4::Application* Tyrone4::CreateApplication();

int main() {

	Tyrone4::Log::Init(); // Creates the Client and Core loggers.
	Tyrone4::Log::GetCoreLogger()->warn("Tyrone4 Engine initialized.");
	Tyrone4::Log::GetClientLogger()->info("Application initialized.");

	auto app = Tyrone4::CreateApplication(); // Creates Application object.
	app->Run();
	delete app;

}

#endif