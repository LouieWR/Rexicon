#include "Module.h"

#include <memory>

namespace rexicon
{

class VertexArray;
class ShaderProgram;

class MeshRenderer : public Module
{
public:
  void OnInit();

private:
  void OnDisplay();

  std::shared_ptr<VertexArray> shape;
  std::shared_ptr<ShaderProgram> shader;

};

}
