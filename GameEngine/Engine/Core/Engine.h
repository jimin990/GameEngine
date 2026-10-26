#pragma once

#include <memory>
#include <chrono>
#include "Window.h"
#include "Renderer.h"

class Scene;

class Engine
{
public:
	bool Initialize(HINSTANCE instance, int showCommand);

public:
	void SetScene(std::unique_ptr<Scene> scene);

	void Run();

	void Stop();

private:
	std::unique_ptr<Scene> currentScene;

	bool isRunning = false;

private:
	Window window;

	Renderer renderer;
};

