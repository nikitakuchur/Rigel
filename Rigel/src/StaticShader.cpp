#include "StaticShader.h"

namespace rigel
{
    StaticShader::StaticShader() 
        :Shader("res/shaders/standart.shader")
    {
    }

    void StaticShader::setModelMatrix(const glm::mat4& model)
    {
        this->setUniformMat4f("u_model", model);
    }

    void StaticShader::setViewMatrix(const glm::mat4& view)
    {
        this->setUniformMat4f("u_view", view);
    }

    void StaticShader::setProjectionMatrix(const glm::mat4& proj)
    {
        this->setUniformMat4f("u_proj", proj);
    }

    void StaticShader::setTexture(int slot)
    {
        this->setUniform1i("u_texture", slot);
    }

    void StaticShader::setMaterial(const Material& material)
    {
        this->setUniform3f("u_material.ambient", material.getAmbient());
        this->setUniform3f("u_material.diffuse", material.getDiffuse());
        this->setUniform3f("u_material.specular", material.getSpecular());
        this->setUniform1f("u_material.shininess", material.getShininess());
    }

    void StaticShader::setDirectionalLights(std::vector<DirectionalLight> directionalLights)
    {
        this->setUniform1i("u_numDirectionalLights", directionalLights.size());

        for (int i = 0; i < directionalLights.size(); i++)
        {
            this->setUniform3f("u_directionalLights[" + std::to_string(i) + "].direction", directionalLights[i].getDirection());
            this->setUniform3f("u_directionalLights[" + std::to_string(i) + "].ambient", directionalLights[i].getAmbient());
            this->setUniform3f("u_directionalLights[" + std::to_string(i) + "].diffuse", directionalLights[i].getDiffuse());
            this->setUniform3f("u_directionalLights[" + std::to_string(i) + "].specular", directionalLights[i].getSpecular());
        }
    }

    void StaticShader::setPointLights(std::vector<PointLight> pointLights)
    {
        this->setUniform1i("u_numPointLights", pointLights.size());

        for (int i = 0; i < pointLights.size(); i++)
        {
            this->setUniform3f("u_pointLights[" + std::to_string(i) + "].position", pointLights[i].getPosition());

            this->setUniform1f("u_pointLights[" + std::to_string(i) + "].constant", pointLights[i].getConstant());
            this->setUniform1f("u_pointLights[" + std::to_string(i) + "].linear", pointLights[i].getLinear());
            this->setUniform1f("u_pointLights[" + std::to_string(i) + "].quadratic", pointLights[i].getQuadratic());

            this->setUniform3f("u_pointLights[" + std::to_string(i) + "].ambient", pointLights[i].getAmbient());
            this->setUniform3f("u_pointLights[" + std::to_string(i) + "].diffuse", pointLights[i].getDiffuse());
            this->setUniform3f("u_pointLights[" + std::to_string(i) + "].specular", pointLights[i].getSpecular());
        }
    }

    void StaticShader::setSpotLights(std::vector<SpotLight> spotLights)
    {
        this->setUniform1i("u_numSpotLights", spotLights.size());

        for (int i = 0; i < spotLights.size(); i++)
        {
            this->setUniform3f("u_spotLights[" + std::to_string(i) + "].position", spotLights[i].getPosition());
            this->setUniform3f("u_spotLights[" + std::to_string(i) + "].direction", spotLights[i].getDirection());

            this->setUniform1f("u_spotLights[" + std::to_string(i) + "].cutOff", spotLights[i].getCutOff());
            this->setUniform1f("u_spotLights[" + std::to_string(i) + "].outerCutOff", spotLights[i].getOuterCutOff());

            this->setUniform1f("u_spotLights[" + std::to_string(i) + "].constant", spotLights[i].getConstant());
            this->setUniform1f("u_spotLights[" + std::to_string(i) + "].linear", spotLights[i].getLinear());
            this->setUniform1f("u_spotLights[" + std::to_string(i) + "].quadratic", spotLights[i].getQuadratic());

            this->setUniform3f("u_spotLights[" + std::to_string(i) + "].ambient", spotLights[i].getAmbient());
            this->setUniform3f("u_spotLights[" + std::to_string(i) + "].diffuse", spotLights[i].getDiffuse());
            this->setUniform3f("u_spotLights[" + std::to_string(i) + "].specular", spotLights[i].getSpecular());
        }
    }

    void StaticShader::setViewPosition(const glm::vec3& position)
    {
        this->setUniform3f("u_viewPos", position);
    }
}