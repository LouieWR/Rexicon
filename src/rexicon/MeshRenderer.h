#include "Module.h"

#include <memory>

namespace rexicon
{

class VertexArray;
class ShaderProgram;

class MeshRenderer : public Module
{
public:
  void onInit();

private:
  void onDisplay();

  std::shared_ptr<VertexArray> shape;
  std::shared_ptr<ShaderProgram> shader;

};

}
