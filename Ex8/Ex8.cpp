#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

/// <summary>
/// 物体の定義
/// </summary>
template<class T> class Solid {
public:
    virtual T GetVolume() = 0;
    virtual T GetSurface() = 0;
};

/// <summary>
/// 箱型
/// </summary>
template<class T> class Box :Solid<T> {
private:
    T width;
    T height;
    T depth;

public:
    Box(
        T width,   //幅
        T height,  //高さ
        T depth) {//奥行
        this->width = width;
        this->height = height;
        this->depth = depth;
    }
    T GetVolume() {
        return width * height * depth;
    }
    T GetSurface() {
        return (width * height + height * depth + depth * width) * 2;
    }


};

/// <summary>
/// 円柱
/// </summary>
template<class T> class Cylinder :Solid<T> {
private:
    T radius;
    T height;
public:
    Cylinder(
        T radius,   //底面の半径
        T height) { //高さ
        this->radius = radius;
        this->height = height;
    }
    T GetVolume() {
        return radius * radius * M_PI * height;
    }
    T GetSurface() {
        return (radius * radius * M_PI * 2) + (radius * M_PI * height * 2);
    }
};

/// <summary>
/// 円錐
/// </summary>
template<class T> class Cone :Solid<T> {
private:
    T radius;
    T height;
public:
    Cone(
        T radius,   //底面の半径
        T height) { //高さ
        this->radius = radius;
        this->height = height;
    }
    T GetVolume() {
        return radius * radius * M_PI * height / 3;
    }
    T GetSurface() {
        return radius * M_PI * sqrtf(radius * radius + height * height) + radius * radius * M_PI;
    }
};

/// <summary>
/// 球
/// </summary>
template<class T> class Sphere :Solid<T> {
private:
    T radius;
public:
    Sphere(
        T radius) {  //球の半径
        this->radius = radius;
    }
    T GetVolume() {
        return radius * radius * radius * M_PI * 4 / 3;
    }
    T GetSurface() {
        return radius * radius * M_PI * 4;
    }
};

int main()
{
    Box<double> box{ 3,5,2.5 };
    cout << "boxの体積=" << box.GetVolume() << endl;
    cout << "boxの表面積=" << box.GetSurface() << endl;
    Cylinder<int> cylinder{ 5,12 };
    cout << "cylinderの体積=" << cylinder.GetVolume() << endl;
    cout << "cylinderの表面積=" << cylinder.GetSurface() << endl;
    Cone<float> cone{ 6,9 };
    cout << "coneの体積=" << cone.GetVolume() << endl;
    cout << "coneの表面積=" << cone.GetSurface() << endl;
    Sphere<int> sphere{ 7 };
    cout << "sphereの体積=" << sphere.GetVolume() << endl;
    cout << "sphereの表面積=" << sphere.GetSurface() << endl;
}