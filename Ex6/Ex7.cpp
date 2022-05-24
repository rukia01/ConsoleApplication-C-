
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

/// <summary>
/// 物体の定義
/// </summary>
class Solid {
public:
    virtual double GetVolume() = 0;
    virtual double GetSurface() = 0;
    virtual double GetPackageLength() = 0;
};

/// <summary>
/// 箱型
/// </summary>
class Box :public Solid {
private:
    double width;
    double height;
    double depth;

public:
    Box(
        double width,   //幅
        double height,  //高さ
        double depth) {//奥行
        this->width = width;
        this->height = height;
        this->depth = depth;
    }
    double GetVolume() {
        return width * height * depth;
    }
    double GetSurface() {
        return (width * height + height * depth + depth * width) * 2;
    }
    double GetPackageLength() {
        return this->width + this->height + this->depth;
    }


};

/// <summary>
/// 円柱
/// </summary>
class Cylinder :public Solid {
private:
    double radius;
    double height;
public:
    Cylinder(
        double radius,   //底面の半径
        double height) { //高さ
        this->radius = radius;
        this->height = height;
    }
    double GetVolume() {
        return radius * radius * M_PI * height;
    }
    double GetSurface() {
        return (radius * radius * M_PI * 2) + (radius * M_PI * height * 2);
    }
    double GetPackageLength() {
        return this->radius * 4 + this->height;
    }
};

/// <summary>
/// 円錐
/// </summary>
class Cone :public Solid {
private:
    double radius;
    double height;
public:
    Cone(
        double radius,   //底面の半径
        double height) { //高さ
        this->radius = radius;
        this->height = height;
    }
    double GetVolume() {
        return radius * radius * M_PI * height / 3;
    }
    double GetSurface() {
        return radius * M_PI * sqrtf(radius * radius + height * height) + radius * radius * M_PI;
    }
    double GetPackageLength() {
        return this->radius * 4 + this->height;
    }
};

/// <summary>
/// 球
/// </summary>
class Sphere :public Solid {
private:
    double radius;
public:
    Sphere(
        double radius) {  //球の半径
        this->radius = radius;
    }
    double GetVolume() {
        return radius * radius * radius * M_PI * 4 / 3;
    }
    double GetSurface() {
        return radius * radius * M_PI * 4;
    }
    double GetPackageLength() {
        return this->radius * 6;
    }
};

int GetKuronekoPackageSize(Solid& solid)
{
    int size[] = { 60,80,100,120,140,160,180,200 };
    int i;
    int packageSize = 0;
    double packageLength = solid.GetPackageLength();
    for (i = 0; i < _countof(size); i++)
    {
        if (packageLength <= size[i])
        {
            packageSize = size[i];
            break;
        }
        else
        {
            packageSize = 0;
        }
    }
    return packageSize;
}

int main()
{
    Box* box = new Box{ 10,30,10 };
    Cylinder* cylinder = new Cylinder{ 20,30 };
    Cone* cone = new Cone{ 30,40 };
    Sphere* sphere = new Sphere{ 40 };
    const int solidLength = 4;
    int i;
    int packageSize;
    Solid* solid[solidLength] = { box,cylinder,cone,sphere };
    for (i = 0; i < solidLength; i++)
    {
        packageSize = GetKuronekoPackageSize(*solid[i]);
        if (packageSize != 0)
        {
            cout << "クロネコ宅急便の宅急便サイズは" << packageSize << "サイズです。" << endl;
        }
        else
        {
            cout << "クロネコ宅急便では送れません。" << endl;
        }
    }
    return 0;
}