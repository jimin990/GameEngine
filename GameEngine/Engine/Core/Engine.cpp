#include "Engine.h"
#include "Scene.h"
#include <utility>
#include <iostream>

void Engine::SetScene(std::unique_ptr<Scene> scene)
{
	currentScene = std::move(scene);
}

void Engine::Run()
{
	if (!currentScene) return;

	isRunning = true;

	auto prevTime = std::chrono::steady_clock::now();

	while (isRunning)
	{
		auto currentTime = std::chrono::steady_clock::now();

		float deltaTime = std::chrono::duration<float>(currentTime - prevTime).count();

		totalTime += deltaTime;

		prevTime = currentTime;

		currentScene->Update(deltaTime);

		//std::cout << "Time : " << totalTime << "\n";

		if (totalTime >= 5.0f)
		{
			Stop();
		}
	}
}

void Engine::Stop()
{
	isRunning = false;
}
