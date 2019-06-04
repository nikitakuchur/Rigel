#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "Camera.h"

class Spectator
{
private:
    rigel::Camera m_camera;
    glm::vec3 m_position;
    float m_rotation;
    float m_speed;
    float m_sensitivity;

    // Mouse handling
    bool firstMouse;
public:
    Spectator();

    inline rigel::Camera getCamera() const { return m_camera; }
    void setPosition(const glm::vec3& position);
    inline glm::vec3 getPosition() const { return m_position; }
    inline void setRotation(float rotation) { m_rotation = rotation; }
    inline float getRotation() const { return m_rotation; }
    inline void setSpeed(float speed) { m_speed = speed; }
    inline float getSpeed() const { return m_speed; };
    inline void setSensitivity(float sensitivity) { m_sensitivity = sensitivity; }
    inline float getSensitivity() const { return m_sensitivity; };

    void update(GLFWwindow* window, float deltaTime);
};