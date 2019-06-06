#pragma once

#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Mesh.h"

namespace rigel
{
    class Model
    {
    private:
        std::vector<Mesh*> m_meshes;

    public:
        Model(std::string const& path);
        ~Model();

        std::vector<Mesh*> getMeshes() const;

    private:
        void loadModel(std::string const& path);
        void processNode(aiNode* node, const aiScene* scene);
        Mesh* processMesh(aiMesh* mesh, const aiScene* scene);
    };
}