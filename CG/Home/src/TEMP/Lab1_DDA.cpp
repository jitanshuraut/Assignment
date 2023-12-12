#include <graphics.h>
#include <bits\stdc++.h>

using namespace std;

int halfx, halfy;

void dda(int x1, int y1, int x2, int y2)
{
    float m, x, y, dx, dy, steps;
    dx = x2 - x1;
    dy = y2 - y1;
    m = dy / dx;
    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    x = x1;
    y = y1;
    putpixel(round(x + halfx), round(halfy - y), YELLOW);
    for (int i = 0; i <= steps; i++)
    {
        if (x1 < x2)
        {
            if (m > 1)
            {
                x = x + (1 / m);
                y = y + 1;
                putpixel(round(x + halfx), round(halfy - y), YELLOW);
                delay(50);
            }
            else if (m < -1)
            {
                x = x + (1 / abs(m));
                y = y - 1;
                putpixel(round(x + halfx), round(halfy - y), YELLOW);
                delay(50);
            }
            else if (abs(m) == 1)
            {
                x = x + abs(m);
                y = y + m;
                putpixel(round(x + halfx), round(halfy - y), YELLOW);
                delay(50);
            }
            else
            {
                x = x + 1;
                y = y + m;
                putpixel(round(x + halfx), round(halfy - y), YELLOW);
                delay(50);
            }
        }
        else
        {
            if (m > 1)
            {
                x = x - (1 / m);
                y = y - 1;
                putpixel(round(x + halfx), round(halfy - y), YELLOW);
                delay(50);
            }
            else if (m < -1)
            {
                x = x - (1 / abs(m));
                y = y + 1;
                putpixel(round(x + halfx), round(halfy - y), YELLOW);
                delay(50);
            }
            else if (abs(m) == 1)
            {
                x = x - abs(m);
                y = y - m;
                putpixel(round(x + halfx), round(halfy - y), YELLOW);
                delay(50);
            }
            else
            {
                x = x - 1;
                y = y - m;
                putpixel(round(x + halfx), round(halfy - y), YELLOW);
                delay(50);
            }
        }
    }
}

void Bresenhem(int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int p = 2 * dy - dx;
    int x = x0, y = y0;

    putpixel(round(x + halfx), round(halfy - y), WHITE);

    while (x != x1 || y != y1)
    {
        if (p >= 0)
        {
            p = p + 2 * (dy - dx);
            if (y1 > y0)
            {
                y = y + 1;
            }
            else
            {
                y = y - 1;
            }
        }
        else
        {
            p = p + 2 * dy;
        }
        if (x1 > x0)
        {
            x = x + 1;
        }
        else
        {
            x = x - 1;
        }
        putpixel(round(x + halfx), round(halfy - y), WHITE);
    }
}

void Midpoint(int x0, int y0, int x1, int y1)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int x = x0, y = y0;

    putpixel(round(x + halfx), round(halfy - y), CYAN);

    if (abs(dx) >= abs(dy))
    {
        int d = abs(dy) - abs(dx) / 2;
        while (x != x1)
        {
            if (x1 > x0)
            {
                x = x + 1;
            }
            else
            {
                x = x - 1;
            }
            if (d < 0)
            {
                d = d + abs(dy);
            }
            else
            {
                d = d + abs(dy) - abs(dx);
                if (y1 > y0)
                {
                    y = y + 1;
                }
                else
                {
                    y = y - 1;
                }
            }
            putpixel(round(x + halfx), round(halfy - y), CYAN);
        }
    }
    else
    {
        int d = abs(dx) - abs(dy) / 2;
        while (y != y1)
        {
            if (y1 > y0)
            {
                y = y + 1;
            }
            else
            {
                y = y - 1;
            }
            if (d < 0)
            {
                d = d + abs(dx);
            }
            else
            {
                d = d + abs(dx) - abs(dy);
                if (x1 > x0)
                {
                    x = x + 1;
                }
                else
                {
                    x = x - 1;
                }
            }
            putpixel(round(x + halfx), round(halfy - y), CYAN);
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
    int x1, x2, y1, y2, algo;
    while (true)
    {
        cout << "Enter Coordinates: ";
        cin >> x1 >> y1 >> x2 >> y2;
        cout << "1.DDA\t2.Bresenhem\t3.Midpoint\t4.Break\nWhich Algorithm: ";
        cin >> algo;

        switch (algo)
        {
        case 1:
            dda(x1, y1, x2, y2);
            break;

        case 2:
            Bresenhem(x1, y1, x2, y2);
            break;

        case 3:
            Midpoint(x1, y1, x2, y2);
            break;
        case 4:
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
