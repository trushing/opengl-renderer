#include <stdio.h>
#include <stdlib.h>

#include <glfw3.h>


int stuff(GLFWwindow*);

int main()
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}

	//glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 

	// Create a window using GLFW and pass it to 
	GLFWwindow* window;
	window = glfwCreateWindow(800, 600, "Model Renderer", NULL, NULL);
	stuff(window);


	return 0;
}

