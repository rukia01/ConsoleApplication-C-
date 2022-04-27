#include <iostream>
using namespace std;
#include "getVolumeSurface.h"

int main()
{
	bool withinRange;
	const int BoxCount = 3;
	BOX boxes[BoxCount];
	for (int i = 0; i < BoxCount; i++) {
		cout << "幅を入力：";
		cin >> boxes[i].x;
		cout << "高さを入力：";
		cin >> boxes[i].y;
		cout << "奥行を入力：";
		cin >> boxes[i].z;
		getVolumeSurface(&boxes[i]);
		withinRange = isSendable(&boxes[i]);
		cout << "体積は" << boxes[i].volume << endl;
		cout << "表面積は" << boxes[i].surface << endl;
		
		if (withinRange)
		{
			cout << boxes[i].packSize << "サイズで送れます。" << endl;
		}
		else
		{
			cout << "宅急便では送れません。" << endl;
		}
	}
	return 0;
}