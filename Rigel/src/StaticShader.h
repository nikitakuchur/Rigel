#pragma once

#include "glutils/Shader.h"
#include "Material.h"

#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"

namespace rigel
{
    class StaticShader : public Shader
    {
    public:
        StaticShader();

        void setModelMatrix(const glm::mat4& model);
        void setViewMatrix(const glm::mat4& view);
        void setProjectionMatrix(const glm::mat4& proj);

        void setTexture(int slot);
        void setMaterial(const Material& material);

        void setDirectionalLights(std::vector<DirectionalLight> directionalLights);
        void setPointLights(std::vector<PointLight> pointLights);
        void setSpotLights(std::vector<SpotLight> spotLights);

        void setViewPosition(const glm::vec3& position);
    };
}