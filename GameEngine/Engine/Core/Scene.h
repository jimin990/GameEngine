#pragma once

#include <vector>
#include <memory>

#include "GameObject.h"

/*
* Scene은 GameObject를 소유하고, 업데이트를 관리한다.
*/
class Scene
{
public:
	void AddObject(std::unique_ptr<GameObject> object);

	void Update(float deltaTime);

private:
	std::vector<std::unique_ptr<GameObject>> objects;
};

