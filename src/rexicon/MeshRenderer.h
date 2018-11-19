#include "Module.h"

#include <memory>
#include <string>
#include <vector>
#include <glm/glm.hpp>
#include "GL/glew.h"

namespace rexicon
{
class VertexArray;
class VertexBuffer;
class ShaderProgram;
class Texture;

class MeshRenderer : public Module
{
public:
	MeshRenderer();
	~MeshRenderer();

	void OnInit();
	void OnInit(std::string _modelPath);
	void OnInit(std::string _modelPath, std::string _texturePath);

	void OnDisplay();

private:
	std::shared_ptr<VertexArray> shape;

	std::shared_ptr<Texture> texture;
	unsigned int texID;

	unsigned int VAO;

	unsigned int numVtxs = 0;

	std::shared_ptr<ShaderProgram> shader;	
};

}
