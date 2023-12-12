#include <bits/stdc++.h>
#include <vector>
#include <graphics.h>
using namespace std;

struct Point
{
    int x, y;
};

bool is_above_boundary(Point point, int boundary_y)
{
    return point.y < boundary_y;
}

bool is_below_boundary(Point point, int boundary_y)
{
    return point.y >= boundary_y;
}

bool is_left_of_boundary(Point point, int boundary_x)
{
    return point.x <= boundary_x;
}

bool is_right_of_boundary(Point point, int boundary_x)
{
    return point.x > boundary_x;
}

void clip_top(vector<Point> &polygon, int top_boundary)
{
    vector<Point> clipped_polygon;

    for (size_t i = 0; i < polygon.size(); ++i)
    {
        Point current_point = polygon[i];
        Point next_point = polygon[(i + 1) % polygon.size()];

        if (is_below_boundary(current_point, top_boundary) && is_below_boundary(next_point, top_boundary))
        {
            clipped_polygon.push_back(current_point);
            clipped_polygon.push_back(next_point);
        }
        else if (is_above_boundary(current_point, top_boundary) && is_above_boundary(next_point, top_boundary))
        {
        }
        else
        {
            int intersection_x = current_point.x + (next_point.x - current_point.x) * (top_boundary - current_point.y) / (next_point.y - current_point.y);
            int intersection_y = top_boundary;

            if (is_below_boundary(current_point, top_boundary))
            {
                clipped_polygon.push_back(current_point);
                clipped_polygon.push_back({intersection_x, intersection_y});
            }
            else
            {
                clipped_polygon.push_back({intersection_x, intersection_y});
                clipped_polygon.push_back(next_point);
            }
        }
    }

    polygon = clipped_polygon;
}

void clip_bottom(vector<Point> &polygon, int bottom_boundary)
{
    vector<Point> clipped_polygon;

    for (size_t i = 0; i < polygon.size(); ++i)
    {
        Point current_point = polygon[i];
        Point next_point = polygon[(i + 1) % polygon.size()];

        if (is_above_boundary(current_point, bottom_boundary) && is_above_boundary(next_point, bottom_boundary))
        {
            clipped_polygon.push_back(current_point);
            clipped_polygon.push_back(next_point);
        }
        else if (is_below_boundary(current_point, bottom_boundary) && is_below_boundary(next_point, bottom_boundary))
        {
        }
        else
        {
            int intersection_y = bottom_boundary;
            int intersection_x = current_point.x + (next_point.x - current_point.x) * (bottom_boundary - current_point.y) / (next_point.y - current_point.y);

            if (is_above_boundary(current_point, bottom_boundary))
            {
                clipped_polygon.push_back(current_point);
                clipped_polygon.push_back({intersection_x, intersection_y});
            }
            else
            {
                clipped_polygon.push_back({intersection_x, intersection_y});
                clipped_polygon.push_back(next_point);
            }
        }
    }

    polygon = clipped_polygon;
}

void clip_left(vector<Point> &polygon, int left_boundary)
{
    vector<Point> clipped_polygon;

    for (size_t i = 0; i < polygon.size(); ++i)
    {
        Point current_point = polygon[i];
        Point next_point = polygon[(i + 1) % polygon.size()];

        if (is_right_of_boundary(current_point, left_boundary) && is_right_of_boundary(next_point, left_boundary))
        {
            clipped_polygon.push_back(current_point);
            clipped_polygon.push_back(next_point);
        }
        else if (is_left_of_boundary(current_point, left_boundary) && is_left_of_boundary(next_point, left_boundary))
        {
        }
        else
        {
            int intersection_x = left_boundary;
            int intersection_y = current_point.y + (next_point.y - current_point.y) * (left_boundary - current_point.x) / (next_point.x - current_point.x);

            if (is_right_of_boundary(current_point, left_boundary))
            {
                clipped_polygon.push_back(current_point);
                clipped_polygon.push_back({intersection_x, intersection_y});
            }
            else
            {
                clipped_polygon.push_back({intersection_x, intersection_y});
                clipped_polygon.push_back(next_point);
            }
        }
    }

    polygon = clipped_polygon;
}

void clip_right(vector<Point> &polygon, int right_boundary)
{
    vector<Point> clipped_polygon;

    for (size_t i = 0; i < polygon.size(); ++i)
    {
        Point current_point = polygon[i];
        Point next_point = polygon[(i + 1) % polygon.size()];

        if (is_left_of_boundary(current_point, right_boundary) && is_left_of_boundary(next_point, right_boundary))
        {
            clipped_polygon.push_back(current_point);
            clipped_polygon.push_back(next_point);
        }
        else if (is_right_of_boundary(current_point, right_boundary) && is_right_of_boundary(next_point, right_boundary))
        {
        }
        else
        {
            int intersection_x = right_boundary;
            int intersection_y = current_point.y + (next_point.y - current_point.y) * (right_boundary - current_point.x) / (next_point.x - current_point.x);

            if (is_left_of_boundary(current_point, right_boundary))
            {
                clipped_polygon.push_back(current_point);
                clipped_polygon.push_back({intersection_x, intersection_y});
            }
            else
            {
                clipped_polygon.push_back({intersection_x, intersection_y});
                clipped_polygon.push_back(next_point);
            }
        }
    }

    polygon = clipped_polygon;
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    vector<vector<Point>> polygons;
    char choice;
    int top_boundary, bottom_boundary, left_boundary, right_boundary;
    cout << "Enter top boundary: ";
    cin >> top_boundary;
    cout << "Enter bottom boundary: ";
    cin >> bottom_boundary;
    cout << "Enter left boundary: ";
    cin >> left_boundary;
    cout << "Enter right boundary: ";
    cin >> right_boundary;
    setcolor(WHITE);
    line(left_boundary, 0, left_boundary, getmaxy());
    line(right_boundary, 0, right_boundary, getmaxy());
    line(0, top_boundary, getmaxx(), top_boundary);
    line(0, bottom_boundary, getmaxx(), bottom_boundary);

    while (true)
    {
        vector<Point> polygon;
        int num_points;
        cout << "Enter the number of polygon points: ";
        cin >> num_points;
        for (int i = 0; i < num_points; ++i)
        {
            int x, y;
            cout << "Enter coordinate for point " << i + 1 << ": ";
            cin >> x >> y;
            polygon.push_back({x, y});
        }

        for (int i = 0; i < polygon.size(); i++)
        {
            int next = (i + 1) % polygon.size();
            setcolor(WHITE);
            line(polygon[i].x, polygon[i].y, polygon[next].x, polygon[next].y);
        }

        auto sutherland_hodgeman = [&](vector<Point> &polygon)
        {
            clip_left(polygon, left_boundary);
            clip_top(polygon, top_boundary);
            clip_right(polygon, right_boundary);
            clip_bottom(polygon, bottom_boundary);
        };

        sutherland_hodgeman(polygon);
        delay(5000);
        cleardevice();
        setcolor(WHITE);
        line(left_boundary, 0, left_boundary, getmaxy());
        line(right_boundary, 0, right_boundary, getmaxy());
        line(0, top_boundary, getmaxx(), top_boundary);
        line(0, bottom_boundary, getmaxx(), bottom_boundary);
        polygons.push_back(polygon);

        for (int j = 0; j < polygons.size(); j++)
        {
            vector<Point> pt_polygon;
            pt_polygon = polygons[j];
            for (int i = 0; i < pt_polygon.size(); i++)
            {
                int next = (i + 1) % pt_polygon.size();
                setcolor(YELLOW);
                line(pt_polygon[i].x, pt_polygon[i].y, pt_polygon[next].x, pt_polygon[next].y);
            }
        }
        cout << "Do you want to exit: ";
        cin >> choice;
        if (choice == 'Y' || choice == 'y')
        {
            break;
        }
    }

    getch();
    closegraph();

    return 0;
}

