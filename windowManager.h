#pragma once
#include <string>
#include <GL/glew.h>
#include <glfw3.h>

class WindowManager
{
public:
	WindowManager(int _height = 800, int _width = 600, char* _title = " ")
	{
		window = glfwCreateWindow(_height, _width, _title, NULL, NULL);
		glfwSetWindowUserPointer(window, this);
		glfwSetKeyCallback(window, windowEvent);
	}

	~WindowManager()
	{
		glfwDestroyWindow(window);
	}

	virtual void windowEvent(int _key, int _scancode, int _actions, int _mods)
	{

	}

private:
	GLFWwindow* window;

	static void windowEvent(GLFWwindow* _window, int _key, int _scancode, int _actions, int _mods)
	{
		WindowManager* obj = glfwGetWindowUserPointer(_window);
		obj->windowEvent(_key, _scancode, _actions, _mods);
	}
};