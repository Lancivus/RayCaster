#pragma once
#include <stdio.h>
#include <math.h>
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp> // This one lets us use matrix transformations
#include "ray.h"

class Sphere
{

private:

public:
	float radius;
	glm::vec3 position;

	IntersectResult intersect(ray IncomingRay)
	{
		IntersectResult result;
		glm::vec3 a = IncomingRay.origin;
		glm::vec3 n = IncomingRay.direction;

		float d = glm::length(position - a - ((glm::dot((position - a), n))*n));

		float x = pow(((radius * radius) - (d * d)), 0.5);
		if (d > radius)
		{
			result.hit = false;
		}
		else
		{
			result.hit = true;
		}

		return result;
		 // a = ray origin n = ray direction p = sphere's centre point r = radius d = distance is closest point on centre to the centre of the sphere < radius = hit > radius = miss
	}

};