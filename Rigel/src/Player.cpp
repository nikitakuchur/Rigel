#include "Player.h"

#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

Player::Player()
    :m_position(glm::vec3(0.0f, 0.0f, 0.0f)), m_rotation(0.0f), m_speed(4.0f), m_sensitivity(80.0f)
{
}

void Player::setPosition(const glm::vec3& position)
{
    m_position = position;
    m_camera.setPosition(position);
    m_camera.update();
}

glm::mat4 Player::getModelMatrix() const
{
    glm::mat4 mat(1.0f);
    mat = glm::rotate(mat, glm::radians(m_rotation), glm::vec3(0.0f, 1.0f, 0.0f));

    return mat;
}

void Player::update(GLFWwindow* window, float deltaTime)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    // Rotation
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    {
        m_camera.setPitch(m_camera.getPitch() - m_sensitivity * deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) 
    {
        m_camera.setYaw(m_camera.getYaw() + m_sensitivity * deltaTime);
        m_rotation += m_sensitivity * deltaTime;
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
        m_camera.setYaw(m_camera.getYaw() - m_sensitivity * deltaTime);
        m_rotation -= m_sensitivity * deltaTime;
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        m_camera.setPitch(m_camera.getPitch() + m_sensitivity * deltaTime);
    }

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