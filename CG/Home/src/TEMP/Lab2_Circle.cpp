#include <graphics.h>
#include <bits\stdc++.h>

using namespace std;

int halfx, halfy;
int color;

void Bresenhem(int xc, int yc, int r)
{
    putpixel(round(xc + halfx), round(halfy - yc), color);
    int x0 = 0;
    int y0 = r;

    float pk, xk, yk;
    xk = halfx + xc;
    yk = halfy - yc;
    pk = 3 - 2 * r;
    putpixel(round(x0 + halfx), round(halfy - y0), color);
    while (x0 <= y0)
    {
        if (pk < 0)
        {
            x0++;
            pk = pk + 4 * x0 + 6;
            putpixel(round(x0 + xk), round(yk - y0), color);
            putpixel(round(y0 + xk), round(yk - x0), color);
            putpixel(round(x0 + xk), round(yk + y0), color);
            putpixel(round(y0 + xk), round(yk + x0), color);
            putpixel(round(-x0 + xk), round(yk - y0), color);
            putpixel(round(-y0 + xk), round(yk - x0), color);
            putpixel(round(-x0 + xk), round(yk + y0), color);
            putpixel(round(-y0 + xk), round(yk + x0), color);
            delay(100);
        }

        else
        {
            x0++;
            y0--;
            pk = pk + 4 * (x0 - y0) + 10;
            putpixel(round(x0 + xk), round(yk - y0), color);
            putpixel(round(y0 + xk), round(yk - x0), color);
            putpixel(round(x0 + xk), round(yk + y0), color);
            putpixel(round(y0 + xk), round(yk + x0), color);
            putpixel(round(-x0 + xk), round(yk - y0), color);
            putpixel(round(-y0 + xk), round(yk - x0), color);
            putpixel(round(-x0 + xk), round(yk + y0), color);
            putpixel(round(-y0 + xk), round(yk + x0), color);
            delay(100);
        }
    }
}

void Midpoint(int xc, int yc, int r)
{
    putpixel(round(xc + halfx), round(halfy - yc), color);
    int x0 = 0;
    int y0 = r;

    float pk, xk, yk;
    xk = halfx + xc;
    yk = halfy - yc;
    pk = 1 - r;
    putpixel(round(x0 + halfx), round(halfy - y0), color);
    while (x0 <= y0)
    {
        if (pk < 0)
        {
            x0++;
            pk = pk + 2 * x0 + 1;
            putpixel(round(x0 + xk), round(yk - y0), color);
            putpixel(round(y0 + xk), round(yk - x0), color);
            putpixel(round(x0 + xk), round(yk + y0), color);
            putpixel(round(y0 + xk), round(yk + x0), color);
            putpixel(round(-x0 + xk), round(yk - y0), color);
            putpixel(round(-y0 + xk), round(yk - x0), color);
            putpixel(round(-x0 + xk), round(yk + y0), color);
            putpixel(round(-y0 + xk), round(yk + x0), color);
            delay(100);
        }

        else
        {
            x0++;
            y0--;
            pk = pk + 2 * (x0 - y0) + 1;
            putpixel(round(x0 + xk), round(yk - y0), color);
            putpixel(round(y0 + xk), round(yk - x0), color);
            putpixel(round(x0 + xk), round(yk + y0), color);
            putpixel(round(y0 + xk), round(yk + x0), color);
            putpixel(round(-x0 + xk), round(yk - y0), color);
            putpixel(round(-y0 + xk), round(yk - x0), color);
            putpixel(round(-x0 + xk), round(yk + y0), color);
            putpixel(round(-y0 + xk), round(yk + x0), color);
            delay(100);
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    halfx = getmaxx() / 2;
    halfy = getmaxy() / 2;
    line(halfx, 0, halfx, getmaxy());
    line(0, halfy, getmaxx(), halfy);
    string name;
    map<string, int> colorMap = {
        {"red", COLOR(255, 0, 0)},
        {"green", COLOR(0, 255, 0)},
        {"blue", COLOR(0, 0, 255)},
        {"yellow", COLOR(255, 255, 0)},
        {"cyan", COLOR(0, 255, 255)},
        {"white", COLOR(255, 255, 255)},
        {"orange", COLOR(255, 165, 0)},
        {"pink", COLOR(255, 192, 203)},
        {"purple", COLOR(128, 0, 128)}};
    int xc, yc, r, algo;

    while (true)
    {
        cout << "Enter Center: ";
        cin >> xc >> yc;
        cout << "Enter Radious: ";
        cin >> r;
        cout << "Colour: ";
        cin >> name;
        transform(name.begin(), name.end(), name.begin(), ::tolower);

        if (colorMap.find(name) != colorMap.end())
        {
            color = colorMap[name];
        }
        else
        {
            cout << "Color not found!" << endl;
            color = colorMap["white"];
        }

        cout << "1.Bresenhem\t2.Midpoint\t3.Break\nWhich Algorithm: ";
        cin >> algo;

        switch (algo)
        {

        case 1:
            Bresenhem(xc, yc, r);
            break;

        case 2:
            Midpoint(xc, yc, r);
            break;
        case 3:
            return 0;
            break;
        default:
            cout << "Invalid Input:" << endl;
            break;
        }
    }
    getch();
    closegraph();
    return 0;
}

