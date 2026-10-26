#include "Engine.h"
#include "Scene.h"
#include <utility>
#include <iostream>

bool Engine::Initialize(HINSTANCE instance, int showCommand)
{
	if(!window.Create(instance, showCommand))
	{
		return false;
	}

	if (FAILED(renderer.Initialize(window.GetHandle())))
	{
		return false;
	}

	return true;
}

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

		prevTime = currentTime;

		if (!window.ProcessMessages())
		{
			Stop();
		}

		currentScene->Update(deltaTime);
	}
}

void Engine::Stop()
{
	isRunning = false;
}
