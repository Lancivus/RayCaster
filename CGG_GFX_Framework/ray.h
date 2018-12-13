#pragma once
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp> // This one lets us use matrix transformations


struct ray
{
	glm::vec3 origin;
	glm::vec3 direction;
};

struct IntersectResult
{
	bool hit;
	float DistanceToHit;
	glm::vec3 IntersectionPoint;
};
