#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <sstream>

//#include <glad/glad.h>
//#include <GLFW/glfw3.h>

#include "Shapes.h"
#include "alg.h"




int main()
{
	// Task 1.
	{
		/*glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		GLFWwindow* window{ glfwCreateWindow(640, 480, "Shapes", nullptr, nullptr) };
		if (window == nullptr)
		{
			std::cerr << "ERROR: Failed to create GLFW window!" << std::endl;
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window);

		if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
		{
			std::cerr << "ERROR: Failed to initialize GLAD!" << std::endl;
			glfwTerminate();
			return -2;
		}

		glViewport(0, 0, 640, 640);

		glfwSetFramebufferSizeCallback(
			window,
			[](GLFWwindow* win, int width, int height)
			{
				glViewport(0, 0, width, height);
			}
		);
		glfwSetCursorPosCallback(
			window,
			[](GLFWwindow* win, double xPos, double yPos)
			{
				glfwGetCursorPos(win, &xPos, &yPos);
				std::ostringstream title{};
				title << "(" << yPos << " ," << xPos << ")";

				glfwSetWindowTitle(win, title.str().c_str());
			}
		);*/

		std::vector<std::unique_ptr<EPAM::IShape>> shapes{};
		shapes.push_back(std::make_unique<EPAM::Circle>(EPAM::Point{ 0.1f, 0.2f }, 0.2f));
		shapes.push_back(std::make_unique<EPAM::Square>(EPAM::Point{ 0.5f, 0.2f }, 0.3f));
		shapes.push_back(std::make_unique<EPAM::Rectangle>(EPAM::Point{ 0.1f, 0.6f }, EPAM::Point{ 0.9f, 0.8f }));

		for (int i{ 0 }; i < 3; ++i)
		{
			std::cout << shapes[i]->perimeter() << '\t';
			std::cout << shapes[i]->square() << '\n';
		}

		std::cout << "\n\n\n";

		/*std::pair<GLint, GLuint> shapesData[3] = {
			shapes[0]->dataForDraw(),
			shapes[1]->dataForDraw(),
			shapes[2]->dataForDraw()
		};

		while (!glfwWindowShouldClose(window))
		{
			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(window, true);

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glUseProgram(shapesData[2].first);
			glBindVertexArray(shapesData[2].second);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		glDeleteProgram(shapesData[0].first);
		glDeleteProgram(shapesData[1].first);
		glDeleteProgram(shapesData[2].first);

		glfwTerminate();*/
	}
	// Task 2.
	{
		std::vector<int> vec_from{ 1, 2, 5, 6, 2, 3, 5 };
		std::vector<int> vec_to{};
		
		std::list<int> lst_from{ 2, 5, 2, 6, 7, 3, 3 };
		std::list<int> lst_to{};
		
		std::deque<int> dqu_from{ 7, 6, 9, 4, 2, 6, 2 };
		std::deque<int> dqu_to{ 1, 2, 3 };
		
		EPAM::copy(vec_from, vec_to);
		EPAM::copy(lst_from, lst_to);
		EPAM::copy(dqu_from, dqu_to);

		for (const auto& elemV : vec_to)
			std::cout << elemV << ' ';
		std::cout << std::endl;
		for (const auto& elemL : lst_to)
			std::cout << elemL << ' ';
		std::cout << std::endl;
		for (const auto& elemD : dqu_to)
			std::cout << elemD << ' ';
		std::cout << std::endl;
	}

	return 0;
}