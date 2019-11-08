#pragma once

#include "Event.h"

namespace Tyrone4 {

	class TYRONE4_API KeyEvent : public Event {

	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput);

	protected:
		KeyEvent(int keycode) : m_KeyCode(keycode) {};

		int m_KeyCode;

	};

	class TYRONE4_API KeyPressedEvent : public KeyEvent {

	public:
		KeyPressedEvent(int keycode) : KeyEvent(keycode) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	};

	class TYRONE4_API KeyReleasedEvent : public KeyEvent {

	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)

	};

}