#pragma once

#include <memory>
#include <chrono>

class Scene;

class Engine
{
public:
	void SetScene(std::unique_ptr<Scene> scene);

	void Run();

	void Stop();

private:
	std::unique_ptr<Scene> currentScene;

	bool isRunning = false;

	/*
	* float 형으로 하니까. 작은 값의 경우는 반올림을 처리하는지 종료가 안됨
	*/
	double totalTime = 0.0f;
};

