#ifndef __Frustum_h__
#define __Frustum_h__

#include "RE330_global.h"
#include "Matrix4.h"

namespace RE330 
{
	/** This class defines a view frustum.
	@remarks
		The default view frustum has an aspect ratio of one and a field
		of view of about 45 degrees. The near and far clip planes are
		at 1 and 101 respectively.
	*/
	class RE330_EXPORT Frustum
	{
		friend class Camera;

	public:
		Frustum() :	p(2, 0, 0, 0, 0, 2, 0, 0, 0, 0, -1.02, -2.02, 0, 0, -1.f, 0.f) {};

		inline Frustum(float nP, float fP, float aP, float vFOV) 
		{
		  nearPlane = nP;
		  farPlane = fP;
		  aspectRatio = aP;
		  verticalFieldOfView = vFOV;

		  float farMinusNear = farPlane - nearPlane;
		  
		  p = {1/(aspectRatio*tan(verticalFieldOfView/2)), 0, 0, 0,
		       0, 1/tan(verticalFieldOfView/2), 0, 0,
		       0, 0, (farPlane+nearPlane)/farMinusNear, (2*farPlane*nearPlane)/farMinusNear,
		       0, 0, -1, 0
		  };
		}
		const Matrix4 &getProjectionMatrix() const { return p; }

	private:
		Matrix4 p;
		float nearPlane;
		float farPlane;
		float aspectRatio;
		float verticalFieldOfView;
	};

}

#endif

