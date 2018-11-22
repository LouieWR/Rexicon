#ifndef REXICON_SCENE_H
#define REXICON_SCENE_H

#include <memory>
#include <vector>

namespace rexicon
{
	class Object;
	class Core;
	class Camera;
	class Input;
	class Collider;

	class Scene
	{
		friend class Core;

	protected:

		std::weak_ptr<Scene> self;
		std::weak_ptr<Core> core;
		std::shared_ptr<Input> input;
		std::vector<std::shared_ptr<Object> > objects;
		std::vector<std::shared_ptr<Collider> > colliders;
		std::shared_ptr<Camera> activeCamera;

	public:

		void Update();
		void Draw();

		std::shared_ptr<Object> AddObject();
		std::shared_ptr<Camera> AddCamera();
		std::shared_ptr<Camera> GetCamera();
		std::shared_ptr<Input> AddInput();
		std::shared_ptr<Input> GetInput() { return input; }
		void AddCollider(std::shared_ptr<Collider> _collider);
		std::vector<std::shared_ptr<Collider>> GetColliders() { return colliders; }

	};

}

#endif