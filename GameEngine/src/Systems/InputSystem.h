#pragma once

#include "entityx/entityx.h"
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "../engine.h"
#include "../Input.h"
#include "../logger.h"

using namespace entityx;
class InputSystem : public System<InputSystem> {
    public:
        void update(EntityManager& es, EventManager& events, TimeDelta dt) override {
            if (!hasWindow) {
                window = Engine::getInstance().window;

                glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
                    {
                        keyCallback(window, key, action);
                    });

                glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xpos, double ypos) {
                        cursorPositionCallback(window, xpos, ypos);
                    });

                glfwSetCursorEnterCallback(window, [](GLFWwindow* window, int entered) {
                        cursorEnterCallback(window, entered);
                    });

                glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods) {
                        mouseButtonCallback(window, button, action, mods);
                    });

                glfwSetScrollCallback(window, [](GLFWwindow* window, double xoffset, double yoffset) {
                        scrollCallback(window, xoffset, yoffset);
                    });

                hasWindow = true;
            }
            Input::getInstance().pressedChar.clear();

            double xpos, ypos;
            glfwGetCursorPos(window, &xpos, &ypos);

            //Poll for and process events
            glfwPollEvents();
            
        }


        // key input call back
        static void keyCallback(GLFWwindow* window, int key, int action)
        {
            // if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_REPEAT){ 
            char letter = static_cast<char> (key);
            std::cout << letter << " is pressed" << std::endl;
            if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
            
                glfwSetWindowShouldClose(window, true);
            }

            Input::getInstance().pressedChar.push_back(key);
        }

        //cursor position input call back 
        static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
            std::cout << "x position: " << xpos << "y position: " << ypos << std::endl;
        }

        //cursor enter input call back
        static void cursorEnterCallback(GLFWwindow* window, int entered) {
            std::cout << "Entered window" << std::endl;
        }

        //mouse button input call back
        static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
            if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
                std::cout << "Right button pressed" << std::endl;
            }

            if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
                std::cout << "Left button presse" << std::endl;
            }
        }

        //mouse scroll input call back
        static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
            std::cout << "scroll x offset: " << xoffset << " yoffset: " << yoffset << std::endl;
        }

        GLFWwindow* window;
        bool hasWindow = false;
};