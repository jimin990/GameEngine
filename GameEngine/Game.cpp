#include "Game.h"
#include "Engine/Core/Engine.h"

#include <iostream>

class Player : public GameObject
{
public:
	virtual ~Player()
	{
		std::cout << "Player Delete";
	}

	virtual void Update(float deltaTime) override
	{

	};

private:

	bool printed = false;
};

int main()
{
	Engine engine;

	HINSTANCE instance = GetModuleHandleW(nullptr);

	if (engine.Initialize(instance, 1) == -1)
	{
		std::cout << "failed show window";
	}

	auto scene = std::make_unique<Scene>();

	scene->AddObject(std::make_unique<Player>());

	engine.SetScene(std::move(scene));

	engine.Run();

	return 0;
}