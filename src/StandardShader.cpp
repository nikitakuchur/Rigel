#include "StandardShader.h"

namespace rigel {
    StandardShader::StandardShader()
            : Shader("../res/shaders/standard.shader") {
    }

    StandardShader::~StandardShader() = default;

    void StandardShader::setModelMatrix(const glm::mat4 &model) {
        this->setUniformMat4f("u_model", model);
    }

    void StandardShader::setViewMatrix(const glm::mat4 &view) {
        this->setUniformMat4f("u_view", view);
    }

    void StandardShader::setProjectionMatrix(const glm::mat4 &proj) {
        this->setUniformMat4f("u_proj", proj);
    }

    void StandardShader::setTexture(int slot) {
        this->setUniform1i("u_texture", slot);
    }

    void StandardShader::setMaterial(const Material &material) {
        this->setUniform3f("u_material.ambient", material.getAmbient());
        this->setUniform3f("u_material.diffuse", material.getDiffuse());
        this->setUniform3f("u_material.specular", material.getSpecular());
        this->setUniform1f("u_material.shininess", material.getShininess());
    }

    void StandardShader::setDirectionalLights(std::vector<DirectionalLight> directionalLights) {
        this->setUniform1i("u_numDirectionalLights", directionalLights.size());

        for (int i = 0; i < directionalLights.size(); i++) {
            this->setUniform3f("u_directionalLights[" + std::to_string(i) + "].direction",
                               directionalLights[i].getDirection());
            this->setUniform3f("u_directionalLights[" + std::to_string(i) + "].ambient",
                               directionalLights[i].getAmbient());
            this->setUniform3f("u_directionalLights[" + std::to_string(i) + "].diffuse",
                               directionalLights[i].getDiffuse());
            this->setUniform3f("u_directionalLights[" + std::to_string(i) + "].specular",
                               directionalLights[i].getSpecular());
        }
    }

    void StandardShader::setPointLights(std::vector<PointLight> pointLights) {
        this->setUniform1i("u_numPointLights", pointLights.size());

        for (int i = 0; i < pointLights.size(); i++) {
            this->setUniform3f("u_pointLights[" + std::to_string(i) + "].position", pointLights[i].getPosition());

            this->setUniform1f("u_pointLights[" + std::to_string(i) + "].constant", pointLights[i].getConstant());
            this->setUniform1f("u_pointLights[" + std::to_string(i) + "].linear", pointLights[i].getLinear());
            this->setUniform1f("u_pointLights[" + std::to_string(i) + "].quadratic", pointLights[i].getQuadratic());

            this->setUniform3f("u_pointLights[" + std::to_string(i) + "].ambient", pointLights[i].getAmbient());
            this->setUniform3f("u_pointLights[" + std::to_string(i) + "].diffuse", pointLights[i].getDiffuse());
            this->setUniform3f("u_pointLights[" + std::to_string(i) + "].specular", pointLights[i].getSpecular());
        }
    }

    void StandardShader::setSpotLights(std::vector<SpotLight> spotLights) {
        this->setUniform1i("u_numSpotLights", spotLights.size());

        for (int i = 0; i < spotLights.size(); i++) {
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

    void StandardShader::setViewPosition(const glm::vec3 &position) {
        this->setUniform3f("u_viewPos", position);
    }
}
