#include "bronx/window.h"

#include <GLFW/glfw3.h>


namespace bronx {
	class   WindowBuffer : public Window
	{
	public:
		WindowBuffer(const WindowProps& props);
		virtual ~WindowBuffer();

		void onUpdate() override;

		inline unsigned int getWidth() const override { return m_Data.Width; }
		inline unsigned int getHeight() const override { return m_Data.Height; }

		inline void setEventCallback(const eventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void setVSync(bool enabled) override;
		bool isVsync() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:

		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			eventCallbackFn EventCallback;
		};

		WindowData m_Data;

	};
	
}