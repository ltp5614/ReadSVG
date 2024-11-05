#include "Circle.h"

Circle::Circle(int cx, int cy, int r, const std::string& fill, double fill_opacity, const std::string& stroke, int stroke_width, double stroke_opacity)
    : cx(cx), cy(cy), r(r), fill(fill), fill_opacity(fill_opacity), stroke(stroke), stroke_width(stroke_width), stroke_opacity(stroke_opacity) {}

void Circle::render(HDC hdc) const 
{
	Gdiplus::Graphics graphics(hdc);
	Gdiplus::Pen pen(Gdiplus::Color(255 * stroke_opacity, 0, 0, 0), stroke_width);
	Gdiplus::SolidBrush brush(Gdiplus::Color(255 * fill_opacity, 0, 0, 0));


	graphics.FillEllipse(&brush, cx - r, cy - r, 2 * r, 2 * r);
	graphics.DrawEllipse(&pen, cx - r, cy - r, 2 * r, 2 * r);
    
}