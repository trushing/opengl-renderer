#pragma once
#include <string>
#include <GL/glew.h>
#include <glfw3.h>

class WindowManager
{
public:
	WindowManager(int _height = 800, int _width = 600, std::string _title = " ");
	~WindowManager();
	virtual void windowKeyEvent(int _key, int _scancode, int _actions, int _mods);
	void setCurrentContext();
	void update();
	void kill();
	bool isAlive();

private:
	GLFWwindow* window;
	bool killFlag;

	static void windowKeyEvent(GLFWwindow* _window, int _key, int _scancode, int _actions, int _mods)
	{
		void* userPointer = glfwGetWindowUserPointer(_window);
		WindowManager* obj = static_cast<WindowManager *>(userPointer);
		obj->windowKeyEvent(_key, _scancode, _actions, _mods);
	}
};