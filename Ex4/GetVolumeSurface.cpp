#include"GetVolumeSurface.h"
double GetVolumeSurface(double x, double y, double z, double* surface)
{
	double volume;
	volume = x * y * z;
	*surface = ((x * y) + (x * z) + (y * z)) * 2;
	return volume;
}