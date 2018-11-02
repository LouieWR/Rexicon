#include "VertexBuffer.h"

namespace rexicon
{

VertexBuffer::VertexBuffer() : modules(0), dirty(false)
{
  glGenBuffers(1, &id);

  if(!id)
  {
    throw std::exception();
  }
}

void VertexBuffer::add(glm::vec3 value)
{
  if(!modules)
  {
    modules = 3;
  }

  if(modules != 3)
  {
    throw std::exception();
  }

  data.push_back(value.x);
  data.push_back(value.y);
  data.push_back(value.z);
  dirty = true;
}

void VertexBuffer::add(glm::vec4 value)
{
  if(!modules)
  {
    modules = 4;
  }

  if(modules != 4)
  {
    throw std::exception();
  }

  data.push_back(value.x);
  data.push_back(value.y);
  data.push_back(value.z);
  data.push_back(value.w);
  dirty = true;
}

int VertexBuffer::getDataSize()
{
  return data.size();
}

int VertexBuffer::getmodules()
{
  if(!modules)
  {
    throw std::exception();
  }

  return modules;
}

GLuint VertexBuffer::getId()
{
  if(dirty)
  {
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * data.size(), &data.at(0), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    dirty = false;
  }

  return id;
}

}
