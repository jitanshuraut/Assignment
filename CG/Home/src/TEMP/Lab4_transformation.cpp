#include <iostream>
#include <graphics.h>
#include <cmath>
#include <bits\stdc++.h>

using namespace std;

int halfx, halfy;

// Function to draw a square
void drawSquare(int x1, int y1, int x4, int y4)
{
    int x2 = x4;
    int y2 = y1;
    int x3 = x1;
    int y3 = y4;

    line(halfx + x1, halfy - y1, halfx + x2, halfy - y2);
    line(halfx + x2, halfy - y2, halfx + x4, halfy - y4);
    line(halfx + x3, halfy - y3, halfx + x1, halfy - y1);
    line(halfx + x4, halfy - y4, halfx + x3, halfy - y3);
}

// Function to multiply a 2x2 matrix with a 2x1 vector
void matrixMultiply(int matrix[2][2], int vector[2])
{
    int result[2] = {0};

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result[i] += matrix[i][j] * vector[j];
        }
    }

    vector[0] = result[0];
    vector[1] = result[1];
}

// Function to perform scaling using matrix multiplication
void scaleSquare(int &x1, int &y1,int &x4, int &y4, int scaleFactorX, int scaleFactorY)
{
    int matrix[2][2] = {{scaleFactorX, 0}, {0, scaleFactorY}};
    int vector[2] = {x1, y1};

    // Scale the vector
    matrixMultiply(matrix, vector);

    x1 = vector[0];
    y1 = vector[1];
    int vector2[2] = {x4, y4};

    // Scale the vector
    matrixMultiply(matrix, vector2);

    x4 = vector2[0];
    y4 = vector2[1];
    drawSquare(x1,y1,x4,y4);
}

void ShearSquare(int &x1, int &y1,int &x4, int &y4, int shx, int shy)
{
    int matrix[2][2];
    matrix[0][0] = 1;
    matrix[0][1] = shx;
    matrix[1][0] = shy;
    matrix[1][1] = 1;
    
    int x2 = x4;
    int y2 = y1;
    int x3 = x1;
    int y3 = y4;

    int vector[2] = {x1, y1};
    int vector1[2] = {x2, y2};
    int vector2[2] = {x3, y3};
    int vector3[2] = {x4, y4};

    // Scale the vector
    matrixMultiply(matrix, vector);
    matrixMultiply(matrix, vector1);
    matrixMultiply(matrix, vector2);
    matrixMultiply(matrix, vector3);

    x1 = vector[0];
    y1 = vector[1];
    x2 = vector1[0];
    y2 = vector1[1];
    x3 = vector2[0];
    y3 = vector2[1];
    x4 = vector3[0];
    y4 = vector3[1];

    line(halfx + x1, halfy - y1, halfx + x2, halfy - y2);
    line(halfx + x2, halfy - y2, halfx + x4, halfy - y4);
    line(halfx + x3, halfy - y3, halfx + x1, halfy - y1);
    line(halfx + x4, halfy - y4, halfx + x3, halfy - y3);
    
}

// Function to perform translation
void translateSquare(int &x1, int &y1,int &x4, int &y4, int deltaX, int deltaY)
{
    x1 += deltaX;
    y1 += deltaY;
    x4 += deltaX;
    y4 += deltaY;
    drawSquare(x1,y1,x4,y4);
}

// Function to perform rotation
void rotateSquare(int &x1, int &y1,int &x4, int &y4, double angle)
{
    int matrix[2][2];
    matrix[0][0] = round(cos(angle));
    matrix[0][1] = round(-sin(angle));
    matrix[1][0] = round(sin(angle));
    matrix[1][1] = round(cos(angle));

    cout << matrix[0][0]<<matrix[0][1]<<matrix[1][0]<<matrix[1][1];
    int vector[2] = {x1, y1};

    matrixMultiply(matrix, vector);

    x1 = vector[0];
    y1 = vector[1];
    int vector2[2] = {x4, y4};

    matrixMultiply(matrix, vector2);

    x4 = vector2[0];
    y4 = vector2[1];
    drawSquare(x1,y1,x4,y4);
}

// Function to perform reflection
void reflectSquare(int &x1, int &y1,int &x4, int &y4, char choice, double m, double c)
{
    switch (choice)
    {
    case 'x':
        y1 = -y1; // Reflect about x-axis
        y4 = -y4; // Reflect about x-axis
        break;
    case 'y':
        x1 = -x1; // Reflect about y-axis
        x4 = -x4; // Reflect about y-axis
        break;
    case 'd':
        swap(x1, y1); // Reflect about y = x
        swap(x4, y4); // Reflect about y = x
        break;
    case 'e':
        y1 = -y1; 
        y4 = -y4;
        x1 = -x1;
        x4 = -x4; 
        break;
    case 'o':
        // Reflect about y = mx + c (origin reflection)
        y1 = -y1 + 2 * m * x1 - 2 * c;
        y4 = -y4 + 2 * m * x4 - 2 * c;
        break;
    default:
        cout << "Invalid choice!" << endl;
    }
    drawSquare(x1,y1,x4,y4);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    halfx = getmaxx() / 2;
    halfy = getmaxy() / 2;
    line(halfx, 0, halfx, getmaxy());
    line(0, halfy, getmaxx(), halfy);

    int x1,x4,y1,y4;

    char choice;
    double m, c;
    int scaleFactorX, scaleFactorY, shx, shy;
    int deltaX, deltaY;
    double angle;

    do
    {

        cout << "Choose an operation:\n";
        cout << "1. Scale\n";
        cout << "2. Translate\n";
        cout << "3. Rotate\n";
        cout << "4. Reflect\n";
        cout << "5. Shearing\n";
        cout << "6. Draw Shape\n";
        cout << "7. Clear Device\n";
        cout << "8. Quit\n";
        cin >> choice;

        switch (choice)
        {
        case '1':
            cout << "Enter scale factors (X Y): ";
            cin >> scaleFactorX >> scaleFactorY;
            scaleSquare(x1,y1,x4,y4, scaleFactorX, scaleFactorY);
            break;
        case '2':
            cout << "Enter translation values (DeltaX DeltaY): ";
            cin >> deltaX >> deltaY;
            translateSquare(x1,y1,x4,y4, deltaX, deltaY);
            break;
        case '3':
            cout << "Enter rotation angle (degrees): ";
            cin >> angle;
            angle = angle * (3.14 / 180.0); // Convert to radians
            rotateSquare(x1,y1,x4,y4, angle);
            break;
        case '4':
            cout << "Choose reflection type:\n";
            cout << "x - Reflect about x-axis\n";
            cout << "y - Reflect about y-axis\n";
            cout << "d - Reflect about y = x\n";
            cout << "e - Reflect about origin\n";
            cout << "o - Reflect about y = mx + c\n";
            cin >> choice;
            if (choice == 'o')
            {
                cout << "Enter the value of m: ";
                cin >> m;
                cout << "Enter the value of c: ";
                cin >> c;
            }
            reflectSquare(x1,y1,x4,y4, choice, m, c);
            break;
        case '5':
            cout << "Enter shearing factors (X Y): ";
            cin >> shx >> shy;
            ShearSquare(x1,y1,x4,y4, shx, shy);
            break;
        case '6':
            cout << "Enter cordinates (Top Left, Bottom right): ";
            cin >> x1 >> y1 >> x4 >> y4;
            drawSquare(x1, y1, x4, y4);
            break;
        case '7':
            cleardevice();
            line(halfx, 0, halfx, getmaxy());
            line(0, halfy, getmaxx(), halfy);
            break;
        case '8':
            break;
        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != '8');

    closegraph();
    return 0;
}
