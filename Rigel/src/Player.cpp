#include "Player.h"

#include <glm/gtc/matrix_transform.hpp>

Player::Player()
    :m_camera(60, 800, 600), m_position(glm::vec3(0.0f, 0.0f, 0.0f)), m_rotation(0.0f), m_speed(4.0f), m_sensitivity(5.0f)
{
    firstMouse = true;
}

void Player::setPosition(const glm::vec3& position)
{
    m_position = position;
    m_camera.setPosition(position);
    m_camera.update();
}

void Player::update(GLFWwindow* window, float deltaTime)
{
    // Mouse handling
    int width, height;
    glfwGetWindowSize(window, &width, &height);

    if (firstMouse)
    {
        glfwSetCursorPos(window, (double) width / 2, (double) height / 2);
        firstMouse = false;
    }

    double xCenter = (double) width / 2;
    double yCenter = (double) height / 2;

    double xPos, yPos;
    glfwGetCursorPos(window, &xPos, &yPos);

    m_camera.setYaw(m_camera.getYaw() + (xCenter - xPos) * m_sensitivity * deltaTime);
    m_rotation += (xCenter - xPos) * m_sensitivity * deltaTime;

    m_camera.setPitch(m_camera.getPitch() - (yCenter - yPos) * m_sensitivity * deltaTime);
    if (m_camera.getPitch() > 80)
        m_camera.setPitch(80);
    else if(m_camera.getPitch() < -80)
        m_camera.setPitch(-80);

    glfwSetCursorPos(window, (double) width / 2, (double) height / 2);

    // Movement
    glm::vec3 movement(0.0f, 0.0f, 0.0f);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        movement += glm::vec3(0.0f, 0.0f, 1.0f);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        movement += glm::vec3(1.0f, 0.0f, 0.0f);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        movement += glm::vec3(0.0f, 0.0f, -1.0f);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        movement += glm::vec3(-1.0f, 0.0f, 0.0f);

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        movement += glm::vec3(0.0f, 1.0f, 0.0f);
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
        movement += glm::vec3(0.0f, -1.0f, 0.0f);

    if (glm::length(movement) > 1)
        movement = glm::normalize(movement);

    glm::mat4 mat(1.0f);
    mat = glm::rotate(mat, glm::radians(m_rotation), glm::vec3(0.0f, 1.0f, 0.0f));
    movement = glm::mat3(mat) * movement;

    setPosition(getPosition() + movement * m_speed * deltaTime);
}