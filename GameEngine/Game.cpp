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
		//std::cout << "Player is update :" << deltaTime << "\n";

		elapsedTime += deltaTime;

		/*if (elapsedTime >= 1 && !printed)
		{
			std::cout << "1 time passed!\n";

			printed = true;
		}*/
	};

private:
	float elapsedTime = 0.0f;

	bool printed = false;
};

int main()
{
	Engine engine;

	auto scene = std::make_unique<Scene>();

	scene->AddObject(std::make_unique<Player>());

	engine.SetScene(std::move(scene));

	engine.Run();

	return 0;
}