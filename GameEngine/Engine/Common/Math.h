#pragma once

#include "DirectXMath.h"

using namespace DirectX;

struct Transform {
	XMFLOAT3 position = {0.0f, 0.0f, 0.0f};
	XMFLOAT3 rotation = {0.0f, 0.0f, 0.0f};
	XMFLOAT3 scale = {1.0f, 1.0f, 1.0f};
};

