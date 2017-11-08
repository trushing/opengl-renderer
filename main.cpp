#pragma once

#include "windowManager.h"
#include "loader.h"

#include <stdio.h>
#include <stdlib.h>

#include <glfw3.h>
#include <glm/glm.hpp>


int main()
{
	// Load GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Could not load GLFW.\n");
		return -1;
	}

	// Set OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create window
	WindowManager window(800, 600, "Model Renderer");
	window.setCurrentContext();

	// Main loop
	while (window.isAlive())
	{
		window.update();
	}

	return 0;
}

