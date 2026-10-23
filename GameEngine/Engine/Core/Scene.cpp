#include "Scene.h"

void Scene::AddObject(std::unique_ptr<GameObject> object)
{
	objects.push_back(std::move(object));
}

void Scene::Update(float deltaTime)
{
	for (auto& object : objects)
	{
		object->Update(deltaTime);
	}
}