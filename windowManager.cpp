#include "windowManager.h"


WindowManager::WindowManager(int _height, int _width, std::string _title)
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

WindowManager::~WindowManager()
{
	glfwDestroyWindow(window);
}

void WindowManager::windowKeyEvent(int _key, int _scancode, int _actions, int _mods)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		killFlag = true;
	}
}

void WindowManager::setCurrentContext()
{
	glfwMakeContextCurrent(window);
}

void WindowManager::update()
{
	glfwSwapBuffers(window);
	glfwPollEvents();

	if (glfwWindowShouldClose(window) || killFlag)
	{
		kill();
	}
}

void WindowManager::kill()
{
	glfwDestroyWindow(window);
	window = NULL;
}

bool WindowManager::isAlive()
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