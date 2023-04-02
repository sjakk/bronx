#pragma once


#include "bronx/core.h"
#include "bronx/Events/Event.h"
#include <iostream>

namespace bronx
{

	struct WindowProps {
		std::string Title;
		unsigned int Width;
		unsigned int Height;


		WindowProps(const std::string& title = "bronx engine",
			unsigned int width = 620,
			unsigned int height = 480): Title(title),Width(width),Height(height)
		{}


	};


	class BRX_API Window {

	public:
		using eventCallbackFn = std::function<void(Event&)>;

			virtual ~Window() {}


			virtual void onUpdate() = 0;

			virtual unsigned int getWidth() const = 0;
			virtual unsigned int getHeight() const = 0;



			//window atributes

			virtual void setEventCallback(const eventCallbackFn& callback) = 0;
			virtual void setVSync(bool enabled) = 0;
			virtual bool isVsync() const = 0;

			static Window* Create(const WindowProps& props = WindowProps());
	};




}