#include <bits\stdc++.h>
#include <graphics.h>

using namespace std;
int halfx, halfy;

void boundaryFill4(int x, int y, int fillColor, int borderColor)
{
    if (getpixel(round(x + halfx), round(halfy - y)) != borderColor && getpixel(round(x + halfx), round(halfy - y)) != fillColor)
    {
        putpixel(round(x + halfx), round(halfy - y), fillColor);
        boundaryFill4(x + 1, y, fillColor, borderColor);
        boundaryFill4(x - 1, y, fillColor, borderColor);
        boundaryFill4(x, y + 1, fillColor, borderColor);
        boundaryFill4(x, y - 1, fillColor, borderColor);
    }
}

void boundaryFill8(int x, int y, int fillColor, int borderColor)
{
    if (getpixel(round(x + halfx), round(halfy - y)) != borderColor && getpixel(round(x + halfx), round(halfy - y)) != fillColor)
    {
        putpixel(round(x + halfx), round(halfy - y), fillColor);
        boundaryFill8(x + 1, y, fillColor, borderColor);
        boundaryFill8(x - 1, y, fillColor, borderColor);
        boundaryFill8(x, y + 1, fillColor, borderColor);
        boundaryFill8(x, y - 1, fillColor, borderColor);
        boundaryFill8(x + 1, y + 1, fillColor, borderColor);
        boundaryFill8(x - 1, y + 1, fillColor, borderColor);
        boundaryFill8(x + 1, y - 1, fillColor, borderColor);
        boundaryFill8(x - 1, y - 1, fillColor, borderColor);
    }
}

void floodFill4(int x, int y, int fillColor, int oldColor)
{
    if (getpixel(round(x + halfx), round(halfy - y)) == oldColor)
    {
        putpixel(round(x + halfx), round(halfy - y), fillColor);
        floodFill4(x + 1, y, fillColor, oldColor);
        floodFill4(x - 1, y, fillColor, oldColor);
        floodFill4(x, y + 1, fillColor, oldColor);
        floodFill4(x, y - 1, fillColor, oldColor);
    }
}

void floodFill8(int x, int y, int fillColor, int oldColor)
{
    if (getpixel(round(x + halfx), round(halfy - y)) == oldColor)
    {
        putpixel(round(x + halfx), round(halfy - y), fillColor);
        floodFill8(x + 1, y, fillColor, oldColor);
        floodFill8(x - 1, y, fillColor, oldColor);
        floodFill8(x, y + 1, fillColor, oldColor);
        floodFill8(x, y - 1, fillColor, oldColor);
        floodFill8(x + 1, y + 1, fillColor, oldColor);
        floodFill8(x - 1, y + 1, fillColor, oldColor);
        floodFill8(x + 1, y - 1, fillColor, oldColor);
        floodFill8(x - 1, y - 1, fillColor, oldColor);
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

    int choice;
    int x, y;
    int fillColor, borderColor, oldColor;
    while (true)
    {
        cout << "0. Black\t1. Blue\t2. Green\t3. Cyan\t4. Red\t5. Magenta\t6. Brown\t7. Light Gray" << endl;
        cout << "8. Dark Gray\t9. Light Blue\t10. Light Green\t11. Light Cyan\t12. Light Red\t13. Light Magenta\t14. Yellow\t15. White" << endl;
        int choice, col;
        cout << "Enter 1 for circle or 2 for rectangle: ";
        cin >> choice;
        cout << "Color: ";
        cin >> col;
        setcolor(col);
        if (choice == 1)
        {
            int centerX, centerY, radius;
            cout << "Enter center coordinates (x y): ";
            cin >> centerX >> centerY;
            cout << "Enter radius: ";
            cin >> radius;
            circle(halfx + centerX, halfy - centerY, radius);
        }
        else if (choice == 2)
        {
            int x1, y1, x2, y2;
            cout << "Enter top-left and bottom-right coordinates (x1 y1 x2 y2): ";
            cin >> x1 >> y1 >> x2 >> y2;
            rectangle(halfx + x1, halfy - y1, halfx + x2, halfy - y2);
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
        cout << "Menu: \n";
        cout << "1. Boundary Fill (4-connected)\n";
        cout << "2. Boundary Fill (8-connected)\n";
        cout << "3. Flood Fill (4-connected)\n";
        cout << "4. Flood Fill (8-connected)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter starting point (x y): ";
            cin >> x >> y;
            cout << "Enter fill color: ";
            cin >> fillColor;
            cout << "Enter border color: ";
            cin >> borderColor;
            boundaryFill4(x, y, fillColor, borderColor);
            break;
        case 2:
            cout << "Enter starting point (x y): ";
            cin >> x >> y;
            cout << "Enter fill color: ";
            cin >> fillColor;
            cout << "Enter border color: ";
            cin >> borderColor;
            boundaryFill8(x, y, fillColor, borderColor);
            break;
        case 3:
            cout << "Enter starting point (x y): ";
            cin >> x >> y;
            cout << "Enter fill color: ";
            cin >> fillColor;
            cout << "Enter old color: ";
            cin >> oldColor;
            floodFill4(x, y, fillColor, oldColor);
            break;
        case 4:
            cout << "Enter starting point (x y): ";
            cin >> x >> y;
            cout << "Enter fill color: ";
            cin >> fillColor;
            cout << "Enter old color: ";
            cin >> oldColor;
            floodFill8(x, y, fillColor, oldColor);
            break;
        case 5:
            return 0;
            break;
        default:
            cout << "Invalid choice\n";
        }
    }

    delay(5000);
    closegraph();

    return 0;
}
