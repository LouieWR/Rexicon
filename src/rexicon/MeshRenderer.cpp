#include "MeshRenderer.h"
#include "Module.h"
#include "Object.h"
#include "Scene.h"
#include "Camera.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"

#include <iostream>
#include <glm/ext.hpp>

namespace rexicon
{

void MeshRenderer::OnInit()
{
	std::shared_ptr<VertexBuffer> positions = std::make_shared<VertexBuffer>();
	positions->add(glm::vec3(0.0f, 0.5f, 0.0f));
	positions->add(glm::vec3(-0.5f, -0.5f, 0.0f));
	positions->add(glm::vec3(0.5f, -0.5f, 0.0f));

	std::shared_ptr<VertexBuffer> colors = std::make_shared<VertexBuffer>();
	colors->add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	colors->add(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
	colors->add(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	shape = std::make_shared<VertexArray>();
	shape->setBuffer("in_Position", positions);
	shape->setBuffer("in_Color", colors);

	shader = std::make_shared<ShaderProgram>("../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
}

void MeshRenderer::OnDisplay()
{
	if (GetObject())
	{
		if (GetObject()->GetTransformModule())
		{

		}
	}
	std::shared_ptr<Camera> camera = GetObject()->GetScene()->GetCamera();
	shader->setUniform("in_Model", glm::mat4(1.0f));
	glm::mat4 projMat = glm::perspective(camera->GetFOV(), camera->GetAspect(), camera->GetNear(), camera->GetFar()); 
	shader->setUniform("in_Projection", projMat);
	glm::mat4 viewMat = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -15.0f));
	viewMat = glm::rotate(viewMat, 3.0f, glm::vec3(0, 1, 0));
	shader->setUniform("in_View", viewMat);
	shader->draw(*shape);
}

}
