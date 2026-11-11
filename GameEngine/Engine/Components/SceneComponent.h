#pragma once

#include "Component.h"
#include "GameEngine/Engine/Common/Math.h"

class SceneComponent : public Component
{
public:
	/*
	* Component의 World Transform을 반환하는 함수
	*/
	const Transform getWorldTransform();

private:
	Transform localTransform;
};

