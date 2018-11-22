#include "MeshRenderer.h"
#include "Module.h"
#include "Object.h"
#include "Scene.h"
#include "Camera.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"
#include "Transform.h"
#include "Texture.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <glm/ext.hpp>
#include <GL/glew.h>
#include <cmath>
#include <SDL2/SDL.h>

namespace rexicon
{
MeshRenderer::MeshRenderer() { }

MeshRenderer::~MeshRenderer() { }

void MeshRenderer::OnInit()
{
	shader = std::make_shared<ShaderProgram>("../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
}

void MeshRenderer::OnInit(std::string _modelPath)
{
	shader = std::make_shared<ShaderProgram>("../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
	shape = std::make_shared<VertexArray>(_modelPath);
}

void MeshRenderer::OnInit(std::string _modelPath, std::string _texturePath)
{
	shader = std::make_shared<ShaderProgram>("../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
	shape = std::make_shared<VertexArray>(_modelPath);
	texture = std::make_shared<Texture>(_texturePath);
}

void MeshRenderer::OnDisplay()
{
	if (GetObject() && GetObject()->GetTransformModule()) // First we check to see if there even is a transform on the object, if not we can't render the object.
	{
		glm::mat4 projMat = glm::mat4(1.0f); // Initialise the values to basic values so we don't get an error if it isn't set
		glm::mat4 viewMat = glm::mat4(1.0f);
		glm::vec3 viewPos = glm::vec3(0);
		glm::vec3 viewRot = glm::vec3(0);
		std::shared_ptr<Camera> camera = GetObject()->GetScene()->GetCamera(); // Get the camera from the scene, since there is only 1 active camera per scene. Subject to change in future.

		if (camera) // If there is a camera (There probably should be but you never know what the user wants, maybe the default viewing matrix is enough)
		{
			projMat = camera->GetProjection(); // We grab the projection matrix from the camera object.
			viewMat = camera->GetViewMat();
		}
		else
		{
			projMat = glm::perspective(45.0f, 2.0f, 0.1f, 100.0f);
		}
		shader->setUniform("in_Projection", projMat);

		shader->setUniform("in_View", glm::inverse(viewMat));

		glm::mat4 modelMat = GetObject()->GetTransformModule()->GetTransformMat();
		shader->setUniform("in_Model", modelMat); // Now we are ready to pass items into the vertex shader. First we get the matrix from the model, the model matrix.		

		shader->setUniform("in_Texture", texture.get());

		shader->setUniform("in_Light.pos", glm::vec4(0.0f, 10.0f, 0.0f, 1.0f)); // TEMP
		shader->setUniform("in_Light.col", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
		shader->setUniform("in_Ambience", glm::vec4(0.2f, 0.2f, 0.2f, 1.0f));

		if (!shape)
		{
			shape = std::make_shared<VertexArray>("../resources/objects/Error/Error.obj");
		}
		if (!texture)
		{
			texture = std::make_shared<Texture>("../resources/objects/Error/ErrorTex.png");
		}

		shader->draw(shape.get());
	}
}
}