// Ex4.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include"GetVolumeSurface.h"

using namespace std;

int main()
{
    double x, y, z;
    double volume, surface;

    cout << "幅を入力してください。:";
    cin >> x;
    cout << "高さを入力してください。:";
    cin >> y;
    cout << "奥行を入力してください。:";
    cin >> z;
    volume = GetVolumeSurface(x, y, z, &surface);
    cout << "体積は" << volume << endl << "表面積は" << surface << endl;
    return 0;
}