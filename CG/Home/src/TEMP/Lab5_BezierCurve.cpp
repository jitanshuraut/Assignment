#include <iostream>
#include <cmath>
#include <graphics.h>

using namespace std;

int halfx, halfy;

struct Point
{
    float x, y;
};

Point QuadraticBezier(Point p0, Point p1, Point p2, float t)
{
    float u = 1.0 - t;
    float tt = t * t;
    float uu = u * u;
    float ut = u * t;

    Point result;
    result.x = uu * p0.x + 2 * ut * p1.x + tt * p2.x;
    result.y = uu * p0.y + 2 * ut * p1.y + tt * p2.y;

    return result;
}

Point CubicBezier(Point p0, Point p1, Point p2, Point p3, float t)
{
    float u = 1.0 - t;

    Point result;
    result.x = pow(u, 3) * p0.x + 3 * pow(u, 2) * t * p1.x + 3 * u * pow(t, 2) * p2.x + pow(t, 3) * p3.x;
    result.y = pow(u, 3) * p0.y + 3 * pow(u, 2) * t * p1.y + 3 * u * pow(t, 2) * p2.y + pow(t, 3) * p3.y;

    return result;
}

int main()
{
    char choice;
    float num, space;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    halfx = getmaxx() / 2;
    halfy = getmaxy() / 2;
    line(halfx, 0, halfx, getmaxy());
    line(0, halfy, getmaxx(), halfy);
    cout << "Quadratic: RED, Cubic: WHITE" << endl;

    do
    {
        int bezierChoice;
        cout << "Menu:\n";
        cout << "1. Quadratic Bezier Curve\n";
        cout << "2. Cubic Bezier Curve\n";
        cout << "Enter your choice (1 or 2): ";
        cin >> bezierChoice;

        if (bezierChoice == 1)
        {
            Point p0, p1, p2;
            cout << "Enter control points for Quadratic Bezier Curve:\n";
            cout << "P0 (x y): ";
            cin >> p0.x >> p0.y;
            cout << "P1 (x y): ";
            cin >> p1.x >> p1.y;
            cout << "P2 (x y): ";
            cin >> p2.x >> p2.y;
            cout << "Number of Points: ";
            cin >> num;
            space = 1 / num;

            for (float t = 0; t <= 1; t += space)
            {
                Point pointOnCurve = QuadraticBezier(p0, p1, p2, t);
                cout << "Point on curve at t = " << t << ": (" << pointOnCurve.x << ", " << pointOnCurve.y << ")\n";
            }
            for (float t = 0; t <= 1; t += 0.0001)
            {
                Point pointOnCurve = QuadraticBezier(p0, p1, p2, t);
                putpixel(halfx + pointOnCurve.x, halfy - pointOnCurve.y, RED);
            }
        }
        else if (bezierChoice == 2)
        {
            Point p0, p1, p2, p3;
            cout << "Enter control points for Cubic Bezier Curve:\n";
            cout << "P0 (x y): ";
            cin >> p0.x >> p0.y;
            cout << "P1 (x y): ";
            cin >> p1.x >> p1.y;
            cout << "P2 (x y): ";
            cin >> p2.x >> p2.y;
            cout << "P3 (x y): ";
            cin >> p3.x >> p3.y;
            cout << "Number of Points: ";
            cin >> num;
            space = 1 / num;

            for (float t = 0; t <= 1; t += space)
            {
                Point pointOnCurve = CubicBezier(p0, p1, p2, p3, t);
                cout << "Point on curve at t = " << t << ": (" << pointOnCurve.x << ", " << pointOnCurve.y << ")\n";
            }
            for (float t = 0; t <= 1; t += 0.0001)
            {
                Point pointOnCurve = CubicBezier(p0, p1, p2, p3, t);
                putpixel(halfx + pointOnCurve.x, halfy - pointOnCurve.y, WHITE);
            }
        }
        else
        {
            cout << "Invalid choice. Please select 1 or 2.\n";
        }

        cout << "Do you want to continue (y/n)? ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
