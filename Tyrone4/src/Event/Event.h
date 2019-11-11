#pragma once
#include "typch.h"
#include "Core/Core.h"

namespace Tyrone4 {

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, 
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory {
		None = 0,
		EventCategoryApplication =	BIT(0),
		EventCategoryInput =		BIT(1),
		EventCategoryKeyboard =		BIT(2),
		EventCategoryMouse =		BIT(3),
		EventCategoryMouseButton =	BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
							virtual EventType GetEventType() { return GetStaticType(); }\
							virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class TYRONE4_API Event {

	public:
		bool Handled = false;

		virtual Tyrone4::EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}

	};

	/*class TYRONE4_API EventBuffer {

	public:
		EventBuffer(int size) : m_Buffer(new std::vector< std::vector<Event> >), m_size(size) {
			m_Buffer->resize(m_size);
		}
		~EventBuffer() {
			delete &m_Buffer;
		}

		inline int GetSize() { return m_size; }
		void Push(Event& event) { m_Buffer[0].push_back(event);  }
		void Forward() {

			for (int i = m_size - 2; i >= 0; --i) {
				m_Buffer[i + 1].swap(m_Buffer[i]);
			}
			m_Buffer[0].resize(0);
		};
		
	private:
		int m_size;
		std::vector<std::vector<Event>>* m_Buffer;
		

	};*/

}