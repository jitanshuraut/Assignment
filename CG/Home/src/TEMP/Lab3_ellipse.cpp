#include <graphics.h>
#include <bits\stdc++.h>

using namespace std;

int halfx, halfy, color;

void MidPoint(int xc, int yc, int rx, int ry)
{
    putpixel(round(xc + halfx), round(halfy - yc), color);
    int x0 = 0;
    int y0 = ry;
    float pk, xk, yk;
    xk = halfx + xc;
    yk = halfy - yc;
    pk = ry * ry - rx * rx * ry + 1 / 4 * rx * rx;
    putpixel(round(x0 + halfx), round(halfy - y0), color);
    while (ry * ry * x0 <= rx * rx * y0)
    {
        if (pk < 0)
        {
            x0++;
            pk = pk + 2 * ry * ry * x0 + ry * ry;
            putpixel(round(x0 + xk), round(yk - y0), color);
            putpixel(round(x0 + xk), round(yk + y0), color);
            putpixel(round(-x0 + xk), round(yk - y0), color);
            putpixel(round(-x0 + xk), round(yk + y0), color);
            delay(50);
        }
        else
        {
            x0++;
            y0--;
            pk = pk + 2 * ry * ry * x0 - 2 * rx * rx * y0 + ry * ry;
            putpixel(round(x0 + xk), round(yk - y0), color);
            putpixel(round(x0 + xk), round(yk + y0), color);
            putpixel(round(-x0 + xk), round(yk - y0), color);
            putpixel(round(-x0 + xk), round(yk + y0), color);
            delay(50);
        }
    }
    pk = ry * ry * (x0 - 1 / 2) * (x0 - 1 / 2) + rx * rx * (y0 - 1) * (y0 - 1) - ry * ry * rx * rx;

    while (y0 > 0)
    {
        if (pk > 0)
        {
            y0--;
            pk = pk - 2 * rx * rx * y0 + ry * ry;
            putpixel(round(x0 + xk), round(yk - y0), color);
            putpixel(round(x0 + xk), round(yk + y0), color);
            putpixel(round(-x0 + xk), round(yk - y0), color);
            putpixel(round(-x0 + xk), round(yk + y0), color);
            delay(50);
        }
        else
        {
            x0++;
            y0--;
            pk = pk + 2 * ry * ry * x0 - 2 * rx * rx * y0 + ry * ry;
            putpixel(round(x0 + xk), round(yk - y0), color);
            putpixel(round(x0 + xk), round(yk + y0), color);
            putpixel(round(-x0 + xk), round(yk - y0), color);
            putpixel(round(-x0 + xk), round(yk + y0), color);
            delay(50);
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
    int xc, yc, rx, ry, algo;
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
    while (true)
    {
        cout << "1.Midpoint\t2.Exit\nWhich ? : ";
        cin >> algo;
        switch (algo)
        {
        case 1:
            cout << "Enter Center: ";
            cin >> xc >> yc;
            cout << "Enter Radious (X): ";
            cin >> rx;
            cout << "Enter Radious (Y): ";
            cin >> ry;
            rx = abs(rx);
            ry = abs(ry);
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
                cout << "So default White Color taken" << endl;
                color = colorMap["white"];
            }
            MidPoint(xc, yc, rx, ry);
            break;
        case 2:
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
