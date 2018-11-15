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

namespace rexicon
{

void MeshRenderer::OnInit()
{
	shader = std::make_shared<ShaderProgram>("../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
	LoadOBJ("../resources/objects/Typhoon/eurofighter.obj");
	shape = std::make_shared<VertexArray>();
	shape->setBuffer("in_Position", modelPosData);
	shape->setBuffer("in_UVCoord", modelUVData);

	texture = std::make_shared<Texture>();
	texID = texture->LoadTexture("../resources/objects/Typhoon/EurofighterDiffuse.bmp");
}

void MeshRenderer::OnDisplay()
{
	if (GetObject() && GetObject()->GetTransformModule()) // First we check to see if there even is a transform on the object, if not we can't render the object.
	{
		std::shared_ptr<Transform> trans = GetObject()->GetTransformModule(); // Get the transform module from the object we are parented to, and create the model matrix.
		
		std::shared_ptr<Camera> camera = GetObject()->GetScene()->GetCamera(); // Get the camera from the scene, since there is only 1 active camera per scene. Subject to change in future.

		glm::mat4 modelMat = trans->GetTransformMat();
		//modelMat = glm::inverse(modelMat);
		shader->setUniform("in_Model", modelMat); // Now we are ready to pass items into the vertex shader. First we get the matrix from the model, the model matrix.

		glm::mat4 viewMat = camera->GetTransformModule()->GetTransformMat(); // Finally we grab the view matrix from the camera's transform and pass it, the view matrix.
		//viewMat = glm::inverse(viewMat);
		shader->setUniform("in_View", viewMat);

		glm::mat4 projMat = camera->GetProjection(); // Then we grab the projection matrix from the camera and pass it.
		shader->setUniform("in_Projection", projMat);

		shader->draw(*shape, texID);
	}
}

void MeshRenderer::LoadOBJ(const std::string _file)
{
	std::ifstream inFile;
	inFile.open(_file.c_str());

	std::string curLine;
	if (inFile.is_open())
	{
		while (std::getline(inFile, curLine))
		{
			std::cout << curLine << std::endl;

			std::stringstream strLine(curLine);

			switch (curLine[0])
			{
			case 'v':					// All possible vertex types (V#)
			{
				switch (curLine[1])
				{
				case 't':				// Texture coordinate (VT)
				{
					std::cout << "vt" << std::endl;
					rawUVData.push_back(ParseOBJ<glm::vec3>(curLine));
				}
				break;
				case 'n':				// Vertex normal (VN)
				{
					std::cout << "vn" << std::endl;
					rawNmlData.push_back(ParseOBJ<glm::vec3>(curLine));
				}
				break;
				default:				// Regular vertex (V)
				{
					std::cout << "v" << std::endl;
					rawPosData.push_back(ParseOBJ<glm::vec3>(curLine));
				}
				break;
				}
				break;
			}
			break;
			case 'f':					// Face (F)
			{
				std::cout << "F" << std::endl;
				MakeFaceOBJ(curLine);
			}
			break;
			default:
			{
				std::cout << "BREAK" << std::endl;
			}
			break;
			}
		}
		inFile.close();
		
		/*
		numVtxs = modelPosData.size();

		if (numVtxs > 0)
		{
			glBindVertexArray(VAO);

			unsigned int posBuf = 0;
			glGenBuffers(1, &posBuf);
			glBindBuffer(GL_ARRAY_BUFFER, posBuf);
			glBufferData(GL_ARRAY_BUFFER, sizeof(float) * numVtxs * 3, &modelPosData[0], GL_STATIC_DRAW);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
			glEnableVertexAttribArray(0);

			if (modelNmlData.size() > 0)
			{
				unsigned int nmlBuf = 0;
				glGenBuffers(1, &nmlBuf);
				glBindBuffer(GL_ARRAY_BUFFER, nmlBuf);
				glBufferData(GL_ARRAY_BUFFER, sizeof(float) * numVtxs * 3, &modelNmlData[0], GL_STATIC_DRAW);
				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
				glEnableVertexAttribArray(1);
			}

			if (modelUVData.size() > 0)
			{
				unsigned int UVBuf = 0;
				glGenBuffers(1, &UVBuf);
				glBindBuffer(GL_ARRAY_BUFFER, UVBuf);
				glBufferData(GL_ARRAY_BUFFER, sizeof(float) * numVtxs * 3, &modelUVData[0], GL_STATIC_DRAW);
				glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
				glEnableVertexAttribArray(2);
			}
		}
		*/
	}

}

template <typename T>
T MeshRenderer::ParseOBJ(std::string _line)
{
	std::stringstream stream(_line);
	glm::vec3 vec;
	std::string discard;
	T rtn;
	float x, y, z;
	stream >> discard >> x >> y >> z;
	vec.x = x;
	vec.y = y;
	vec.z = z;
	rtn = vec;
	return rtn;
}

void MeshRenderer::MakeFaceOBJ(std::string _line)
{
	std::stringstream stream(_line);
	std::string discard;
	std::string vtxs[4];

	stream >> discard >> vtxs[0] >> vtxs[1] >> vtxs[2] >> vtxs[3];

	if (vtxs[3].empty())
	{
		for (unsigned int i = 0; i < 3; i++)
		{
			std::stringstream curSection(vtxs[i]);

			unsigned int posID = 0;
			unsigned int UVID = 0;
			unsigned int nmlID = 0;

			if (vtxs[i].find("/") == std::string::npos)
			{
				// Position only
				curSection >> posID;
			}
			else if (vtxs[i].find("//") != std::string::npos)
			{
				// Position and Normals
				char discard;
				curSection >> posID >> discard >> discard >> nmlID;
			}
			else
			{
				// Positions, Normals, and Texture Map
				char discard;
				curSection >> posID >> discard >> UVID >> discard >> nmlID;
			}

			if (posID > 0)
			{
				std::cout << "adding pos data" << std::endl;
				modelPosData->add(rawPosData[posID - 1]);
				std::cout << "done" << std::endl;
			}
			if (UVID > 0)
			{
				std::cout << "adding uv data" << std::endl;
				modelUVData->add(rawUVData[UVID - 1]);
				std::cout << "done" << std::endl;
			}
			if (nmlID > 0)
			{
				std::cout << "adding nml data" << std::endl;
				modelNmlData->add(rawNmlData[nmlID - 1]);
				std::cout << "done" << std::endl;
			}
		}
	}
	else
	{
		throw std::exception();
		return;
	}
}

}