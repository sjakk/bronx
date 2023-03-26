#pragma once

#include "bronx/core.h"
#include <string>


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


	class BRX_API Event {
		friend class EventDispatcher; // research friend keyword ()
	public:
		virtual EventType getEventType() const = 0; // analyse const = 0 ()
		virtual const char* getEventName() const = 0; //research again virtual
		virtual int getCategoryFlags() const = 0;
		virtual std::string toString() { return getEventName(); } // analyse and research type class string ()

		inline bool isInCategory(EventCategory category) {
			return getCategoryFlags() &category;
		}
	protected:
		bool m_Handled = false;
	};








}
