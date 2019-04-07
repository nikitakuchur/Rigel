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

    float m_fieldOfView;
    float m_viewportWidth;
    float m_viewportHeight;

    float m_pitch;
    float m_yaw;
public:
    Camera(float fieldOfView, float viewportWidth, float viewportHeight);
    
    glm::mat4 getViewMatrix();
    glm::mat4 getProjectionMatrix();
    
    void update();
    
    inline void setPosition(glm::vec3 position) { m_position = position; }
    inline glm::vec3 getPosition() const { return m_position; }

    inline void setPitch(float pitch) { m_pitch = pitch; }
    inline float getPitch() const { return m_pitch; }
    inline void setYaw(float yaw) { m_yaw = yaw; }
    inline float getYaw() const { return m_yaw; }
};