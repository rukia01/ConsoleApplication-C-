#include "getVolumeSurface.h"

void getVolumeSurface(BOX* box)
{
	box->volume = box->x * box->y * box->z;
	box->surface = 2 * (box->x * box->y + box->x * box->z + box->y * box->z);
	return;
}

bool isSendable(BOX* box)
{
	bool withinRange = false;
	const int sizeLength = 8;
	double luggageSize = box->x + box->y + box->z;
	int size[] = { 60,80,100,120,140,160,180,200 };

	for (int i = 0; i < sizeLength; i++)
	{
		if (luggageSize <= size[i])
		{
			box->packSize = size[i];
			withinRange = true;
			break;
		}
	}
	return withinRange;
}