#pragma once
#include "ray.h"
class Camera
{
public:
	ray GenerateRay(int x, int y)
	{
		ray value;
		value.origin = glm::vec3(x, y, 0);
		value.direction = glm::vec3(0, 0, -1);
		return value;
	}
};