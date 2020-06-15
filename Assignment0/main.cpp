#include<cmath>
#include<eigen3/Eigen/Core>
#include<eigen3/Eigen/Dense>
#include<iostream>

using namespace std;
using namespace Eigen;

int main(){
    // Input 2D Point
    Vector2f P(2.f, 1.f);

    // Rotation Angle to Rad conversion
    float angle = 45;
    const float a2r = acos(-1) / 180.0f;
    float rad = angle * a2r;

    // Affine Matrix M
    Matrix3f M;
    M << cos(rad),-sin(rad),1,
          sin(rad),cos(rad),2,
          0,0,1;

    /* 
    M = [
        cos(θ), -sin(θ), X,
        sin(θ), cos(θ), Y,
        0, 0, 1
    ] */
    
    // Temp 3D Point
    Vector3f tmp;
    tmp << P.x(), P.y(), 1.f;

    tmp = M * tmp;
    Vector2f result(tmp.x(), tmp.y());

    cout << result << endl;
    
    return 0;
} 
