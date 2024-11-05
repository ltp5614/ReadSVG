#include "Polygon.h"

Polygon::Polygon(const std::vector<std::pair<int, int>>& points, const std::string& fill, double fill_opacity, const std::string& stroke, int stroke_width, double stroke_opacity) 
       : points(points), fill(fill), fill_opacity(fill_opacity), stroke(stroke), stroke_width(stroke_width), stroke_opacity(stroke_opacity) {}

void Polygon::render(HDC hdc) const
{
	HPEN hPen = CreatePen(PS_SOLID, stroke_width, RGB(0, 0, 0));
	SelectObject(hdc, hPen);
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, hBrush);

	POINT* p = new POINT[points.size()];
	for (int i = 0; i < points.size(); i++) {
		p[i].x = points[i].first;
		p[i].y = points[i].second;
	}

	Polygon(hdc, p, points.size());

	delete[] p;
	DeleteObject(hPen);
	DeleteObject(hBrush);
}
