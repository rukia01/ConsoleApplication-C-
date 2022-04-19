// Ex3.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<iomanip>
#include"GetBmi.h"
#include"GetObesity.h"

using namespace std;

int main()
{
    double height;
    double weight;
    double bmi;
    int obesity;
    string degreeOfObesity;

    cout << "身長を入力してください(m) : ";
    cin >> height;
    cout << "体重を入力してください(kg) : ";
    cin >> weight;
    bmi = GetBmi(height, weight);
    cout << "あなたのBMIは、" << fixed << setprecision(1) << bmi << "です。" << endl;
    obesity = GetObesity(bmi);
    if (obesity == 4)
    {
        degreeOfObesity = "肥満(4度)";
    }
    else if (obesity == 3)
    {
        degreeOfObesity = "肥満(3度)";
    }
    else if (obesity == 2)
    {
        degreeOfObesity = "肥満(2度)";
    }
    else if (obesity == 1)
    {
        degreeOfObesity = "肥満(1度)";
    }
    else if (obesity == 0)
    {
        degreeOfObesity = "普通体重";
    }
    else
    {
        degreeOfObesity = "低体重";
    }
    cout << "あなたの肥満度は" << degreeOfObesity << "です。" << endl;
}