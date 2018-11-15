#include <string>

namespace rexicon
{

	class Texture
	{
	public:
		unsigned int LoadTexture(std::string _filename);
	private:
		unsigned int texID;

	};

}
