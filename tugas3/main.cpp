#include <iostream>
#include <cmath>
using namespace std;

#define L1 10
#define L2 5
#define THETA1 30
#define THETA2 10

int main() {
    double radTheta1 = THETA1 * (M_PI / 180),
    radTheta2 = THETA2 * (M_PI / 180),
    x = L1 * cos(radTheta1) + L2 * cos(radTheta1 + radTheta2),
    y = L1 * sin(radTheta1) + L2 * sin(radTheta1 + radTheta2);

    cout << "Posisi end-effector adalah (" << x << ", " << y << ')';

    return 0;
}