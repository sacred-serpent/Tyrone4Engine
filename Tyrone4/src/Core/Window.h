#pragma once

#include "typch.h"
#include "Event/Event.h"
#include "Core.h"
#include "Core/Log.h"

namespace Tyrone4 {

	struct WindowProps {

		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Tyrone4", unsigned int width = 1280, unsigned int height = 720)
			: Title(title), Width(width), Height(height) {}

	};

	// Base window class to be inherited from by platform specific window classes.

	class TYRONE4_API Window {

	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());

	};

}