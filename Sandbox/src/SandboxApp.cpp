#include <Tyrone4.h>

class Sandbox : public Tyrone4::Application {

public:
	Sandbox() {

	}
	~Sandbox() {

	}

};

Tyrone4::Application* Tyrone4::CreateApplication() {

	return new Sandbox();

}