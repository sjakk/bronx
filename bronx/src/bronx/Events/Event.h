#pragma once

#include "bronx/core.h"
#include <string>
#include <functional>


namespace bronx 
{

	enum class EventType
	{
		none = 0,
		windowClose,windowResize,windowMoved,windowFocused,windowLostFocus,
		appTick,appUpdate,appRender,
		keyPressed,keyReleased,
		mouseButtonPressed,mouseButtonReleased,mouseMoved,mouseScrolled
	};



	enum EventCategory {
		none = 0,
		eventCategoryApp = BIT(0),
		eventCategoryInput = BIT(1),
		eventCategoryKeyboard = BIT(2),
		eventCategoryMouse = BIT(3),
		eventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_EVENT_TYPE(type) static EventType getStaticType(){ return EventType::##type;}\
									 virtual EventType getEventType() const override {return getStaticType();}\
									virtual const char* getEventName() const override {return #type;}				
									

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }

	class BRX_API Event {
		friend class EventDispatcher;
	public:
		virtual EventType getEventType() const = 0; 
		virtual const char* getEventName() const = 0; 
		virtual int getCategoryFlags() const = 0;
		virtual std::string toString() const { return getEventName(); } 

		inline bool isInCategory(EventCategory category) {
			return getCategoryFlags() &category;
		}
	protected:
		bool m_Handled = false;
	};


	class EventDispatcher {
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) : m_Event(event){}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.getEventType() == T::getStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		
		Event& m_Event;


	};

	inline std::ostream& operator<<(std::ostream& os,const Event& e)
	{
		return os << e.toString(); // look at const in function declaration or smt of class to do a research
	}




}
