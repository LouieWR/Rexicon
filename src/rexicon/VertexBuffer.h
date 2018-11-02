#include <GL/glew.h>
#include <glm/glm.hpp>

#include <vector>

namespace rexicon
{

class VertexBuffer
{
  GLuint id;
  int modules;
  std::vector<GLfloat> data;
  bool dirty;

public:
  VertexBuffer();
  void add(glm::vec3 value);
  void add(glm::vec4 value);
  int getmodules();
  int getDataSize();
  GLuint getId();

};

}
