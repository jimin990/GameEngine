#pragma once

class GameObject;

class Component
{
public:
	virtual ~Component() = default;

public:
	virtual void Update(float deltaTime) {};

	GameObject* GetOwner() const
	{
		return Owner;
	}

private:
	GameObject* Owner = nullptr;
};

