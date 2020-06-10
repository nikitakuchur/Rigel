#ifndef RIGEL_H
#define RIGEL_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

// Render
#include "render/IndexBuffer.h"
#include "render/VertexArray.h"
#include "render/VertexBuffer.h"
#include "render/Shader.h"
#include "render/OrthographicCamera.h"
#include "render/PerspectiveCamera.h"
#include "render/Mesh.h"
#include "render/Renderer.h"
#include "render/TextureRectangle.h"
#include "render/Texture.h"
#include "render/Sprite.h"
#include "render/Rect.h"
#include "render/Circle.h"
#include "render/Triangle.h"

// Window
#include "window/Window.h"
#include "window/Keyboard.h"

#endif //RIGEL_H
