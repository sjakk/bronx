#pragma once
#include "Event.h"
#include <sstream>

namespace bronx {


	class BRX_API WindowResizeEvent : public Event {

	public:
		WindowResizeEvent(unsigned int width, unsigned int heigth) : m_Width(width), m_Heigth(heigth) {}

		inline unsigned int getWidth() const { return m_Heigth; }
		inline unsigned int getHeigth() const { return m_Heigth; }

		std::string toString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Heigth;
			return ss.str();
		}
		EVENT_CLASS_CATEGORY(eventCategoryApp)
		
		EVENT_CLASS_EVENT_TYPE(windowResize)
	private:
		unsigned int m_Width, m_Heigth;
	

	};


	class BRX_API WindowCloseEvent : public Event {

	public:
		WindowCloseEvent() { ; }



	};












}