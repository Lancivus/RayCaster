#pragma once
#include "ray.h"
#include "Sphere.h"
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp> // This one lets us use matrix transformations

class Tracer
{
public:
	Sphere* sphere;
	Tracer()
	{
		sphere = new Sphere;
		sphere->position = glm::vec3(100, 100, -100);
		sphere->radius = 50.0f;
	}
	glm::vec3 TraceRay(ray incomingRay)
	{
		IntersectResult result =  sphere->intersect(incomingRay);
		if (result.hit == true)
		{
			return glm::vec3(1, 0, 0);
		}
		return glm::vec3(0, 0, 0);
	}
};