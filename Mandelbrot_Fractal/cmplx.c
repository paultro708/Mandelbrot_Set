#include "def.h"
#include "cmplx.h"

//function z[n+1] = z[n]^2 + c
cmplx z_next(cmplx z, cmplx c)
{
	cmplx result;
	float tmp = z.r;
	result.r = z.r * z.r - z.i * z.i + c.r;
	result.i = 2 * z.i * tmp + c.i;
	return result;
}

//calculate square of module of complex number c
float cmplxModSq(cmplx c)
{	

	return c.r*c.r + c.i*c.i;
}


//chcecking number of iterations
int levelSet(cmplx c)
{
	
	cmplx z;
	z.i = 0;
	z.r = 0;
	int i = 0;
	do
	{
		z = z_next(z, c);
		i++;
	} while (cmplxModSq(z) < 4 && i < MAX_ITER);
	//is in the set or exceed the value of max iterations

	return i; //number of iterations 
}