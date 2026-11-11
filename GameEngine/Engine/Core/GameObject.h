#pragma once

#include <DirectXMath.h>
#include "GameEngine/Engine/Common/Math.h"

/*
* 실제 게임내 객체
*/
class GameObject
{
public:
	virtual ~GameObject() = default;

	virtual void Update(float deltaTime) {};

    Transform& GetTransform() { return transform; }

private:
    Transform transform;
};

