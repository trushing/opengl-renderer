#pragma once
#include <string>
#include <GL/glew.h>
#include <glfw3.h>

class WindowManager
{
public:
	bool killFlag;

	WindowManager(int _height = 800, int _width = 600, std::string _title = " ")
	{
		killFlag = false;
		window = glfwCreateWindow(_height, _width, _title.c_str(), NULL, NULL);
		glfwSetWindowUserPointer(window, this);
		glfwSetKeyCallback(window, windowKeyEvent);

		if (window == NULL)
		{
			fprintf(stderr, "Failed to create window.");
		}
	}

	~WindowManager()
	{
		glfwDestroyWindow(window);
	}

	virtual void windowKeyEvent(int _key, int _scancode, int _actions, int _mods)
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			killFlag = true;
		}
	}

	void setCurrentContext()
	{
		glfwMakeContextCurrent(window);
	}

	void update()
	{
		glfwSwapBuffers(window);
		glfwPollEvents();

		if (glfwWindowShouldClose(window) || killFlag)
		{
			kill();
		}
	}

	void kill()
	{
		glfwDestroyWindow(window);
		window = NULL;
	}

	bool isAlive()
	{
		if (window == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

private:
	GLFWwindow* window;

	static void windowKeyEvent(GLFWwindow* _window, int _key, int _scancode, int _actions, int _mods)
	{
		void* userPointer = glfwGetWindowUserPointer(_window);
		WindowManager* obj = static_cast<WindowManager *>(userPointer);
		obj->windowKeyEvent(_key, _scancode, _actions, _mods);
	}
};