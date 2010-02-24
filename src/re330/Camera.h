#ifndef __Camera_h__
#define __Camera_h__

#include "RE330_global.h"
#include "Frustum.h"
#include "Matrix4.h"
#include "Vector3.h"

namespace RE330 
{
	/** Camera specification.
	@remarks
		This class specifies a camera. The default camera is located at
		(0,0,10) in world coordinates and looks towards (0,0,0).
	*/
	class RE330_EXPORT Camera : public Frustum
	{
	public:
	        Camera() : viewMatrix(1,0,0,0, 0,1,0,0, 0,0,1,-10, 0,0,0,1) {};
	  
	        inline Camera(Vector3 cOfP, Vector3 lAtP, Vector3 uV)
	        {
		  centerOfProjection = cOfP;
		  lookAtPoint = lAtP;
		  upVector = uV;

		  Vector3 w = lookAtPoint->normalize(lookAtPoint->magnitude());
		  
		  Vector3 u = upVector->crossProduct(w);
		  u = u->normalize(u->magnitude());
		  
		  Vector3 v = w->crossProduct(u);

		  viewMatrix = {u.getX(), v.getX(), w.getX(), centerOfProjection.getX(),
		       u.getY(), v.getY(), w.getY(), centerOfProjection.getY(),
		       u.getZ(), v.getZ(), w.getZ(), centerOfProjection.getZ(),
		       0, 0, 0, 1};
		}
		
		Vector4 getCenterOfProjection() { return centerOfProjection; }
		Vector4 getlookAtPoint() { return lookAtPoint; }
		Vector4 getupVector() { return upVector; }

		void setCenterOfProjection(Vector3 cOfP) { centerOfProjection = cOfP;}
		void setlookAtPoin(Vector3 lAtP) { lookAtPoin = lAtP;}
		void setupVector(Vector3 uV) { upVector = uV;}
		
		const Matrix4 &getViewMatrix() const { return v; }

	private:
		Matrix4 viewMatrix;
		Vector3 centerOfProjection;
		Vector3 lookAtPoint;
		Vector3 upVector;
	};
	
}

#endif

