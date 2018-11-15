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
		void OnInit();
		void OnDisplay();

		void LoadOBJ(const std::string _file);

	private:
		template <typename T>
		T ParseOBJ(std::string _line);
		void MakeFaceOBJ(std::string _line);

		std::vector<glm::vec3> rawUVData;
		std::vector<glm::vec3> rawPosData;
		std::vector<glm::vec3> rawNmlData;

		std::shared_ptr<VertexBuffer> modelUVData = std::make_shared<VertexBuffer>();
		std::shared_ptr<VertexBuffer> modelPosData = std::make_shared<VertexBuffer>();;
		std::shared_ptr<VertexBuffer> modelNmlData = std::make_shared<VertexBuffer>();;

		std::shared_ptr<VertexArray> shape;

		std::shared_ptr<Texture> texture;
		unsigned int texID;

		unsigned int VAO;

		unsigned int numVtxs = 0;

		std::shared_ptr<ShaderProgram> shader;	
	};

}
