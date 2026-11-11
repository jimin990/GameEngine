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

		const float backgroundColor[4] =
		{
			0.1f, 0.2f, 0.5f, 1.0f
		};

		/*
		* 백 버퍼를 배경색으로 채움
		* 지정한 Render Target을 한 가지 색으로 초기화
		*/
		renderer.context->ClearRenderTargetView(
			renderer.renderTargetView.Get(),
			backgroundColor
		);

		renderer.swapChain->Present(1, 0);

		currentScene->Update(deltaTime);
	}
}

void Engine::Stop()
{
	isRunning = false;
}
