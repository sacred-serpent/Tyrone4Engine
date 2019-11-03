#include <Tyrone4.h>

class Sandbox : public Tyrone4::Application {

public:
	Sandbox() {
		TY_CORE_INFO("Started Sandbox Application.");
	}
	~Sandbox() {

	}

};

Tyrone4::Application* Tyrone4::CreateApplication() {

	return new Sandbox();

}