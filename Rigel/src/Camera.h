#pragma once

#include <glm/glm.hpp>

class Camera
{
private:
    glm::vec3 m_position;
    glm::vec3 m_front;
    glm::vec3 m_up;
    glm::vec3 m_right;
    glm::vec3 m_worldUp;

    float m_pitch;
    float m_yaw;
public:
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f));
    
    glm::mat4 getViewMatrix();
    
    void update();
    
    inline void setPosition(glm::vec3 position) { m_position = position; }
    inline glm::vec3 getPosition() const { return m_position; }
    inline void setPitch(float pitch) { m_pitch = pitch; }
    inline float getPitch() const { return m_pitch; }
    inline void setYaw(float yaw) { m_yaw = yaw; }
    inline float getYaw() const { return m_yaw; }
};