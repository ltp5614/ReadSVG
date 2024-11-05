#include "Path.h"

Path::Path(const std::vector<std::pair<int, int> >& points, const std::string& fill, double fill_opacity, const std::string& stroke, int stroke_width, double stroke_opacity) 
    : points(points), fill(fill), fill_opacity(fill_opacity), stroke(stroke), stroke_width(stroke_width), stroke_opacity(stroke_opacity) {}

void Path::render(HDC hdc) const  
{
	HPEN hPen = CreatePen(PS_SOLID, stroke_width, RGB(0, 0, 0));
	SelectObject(hdc, hPen);

	MoveToEx(hdc, points[0].first, points[0].second, NULL);

	for (size_t i = 1; i < points.size(); i++) {
		LineTo(hdc, points[i].first, points[i].second);
	}

	DeleteObject(hPen);
}

std::vector<std::pair<int, int>> parsePathData(const std::string& d) {
    std::vector<std::pair<int, int>> points;
    std::istringstream ss(d);
    char command;
    float x = 0, y = 0;

    while (ss >> command) {
        if (command == 'M' || command == 'L') {
            float newX, newY;
            ss >> newX >> newY;

            points.emplace_back(static_cast<int>(newX), static_cast<int>(newY));

            x = newX;
            y = newY;
        }
    }

    return points;
}
