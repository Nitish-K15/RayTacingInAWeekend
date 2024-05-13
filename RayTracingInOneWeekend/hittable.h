#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

class hit_record 
{
public:
	point3 p;
	vec3 normal;
	double t;
	bool front_face;

	//bool front_face;
	//if (dot(ray_direction, outward_normal) > 0.0) {
	//	// ray is inside the sphere
	//	normal = -outward_normal;
	//	front_face = false;
	//}
	//else {
	//	// ray is outside the sphere
	//	normal = outward_normal;
	//	front_face = true;
	//}

	void set_face_normal(const ray& r, const vec3& outward_normal)
	{
		//Sets the hit record normal

		front_face = dot(r.direction(), outward_normal) < 0;
		normal = front_face ? outward_normal : -outward_normal;
	}
};

class hittable 
{
public:
	virtual ~hittable() = default;

	virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& h) const = 0;
};
#endif // !HITTABLE_H
