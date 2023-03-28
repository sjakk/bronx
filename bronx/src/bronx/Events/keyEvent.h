#pragma once

#include "Event.h"
#include <sstream>



namespace bronx {

	class BRX_API KeyEvent : public Event {

	public:
		inline int getKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(eventCategoryKeyboard | eventCategoryInput)
		

	protected:
		KeyEvent(int keyCode) : m_KeyCode(keyCode) {}
		int m_KeyCode;




	};

	












}