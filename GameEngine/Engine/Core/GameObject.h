#pragma once

/*
* 실제 게임내 객체
*/
class GameObject
{
public:
	virtual ~GameObject() = default;

	virtual void Update(float deltaTime) {};
};

