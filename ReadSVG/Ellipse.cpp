#include "Ellipse.h"

Ellipse::Ellipse(int cx, int cy, int rx, int ry, const std::string& fill, double fill_opacity, const std::string& stroke, int stroke_width, double stroke_opacity)
    : cx(cx), cy(cy), rx(rx), ry(ry), fill(fill), fill_opacity(fill_opacity), stroke(stroke), stroke_width(stroke_width), stroke_opacity(stroke_opacity) {}

void Ellipse::render(HDC hdc) const 
{
    Gdiplus::Graphics graphics(hdc);
	Gdiplus::Pen pen(Gdiplus::Color(255 * stroke_opacity, 0, 0, 0), stroke_width);
	Gdiplus::SolidBrush brush(Gdiplus::Color(255 * fill_opacity, 0, 0, 0));

	graphics.FillEllipse(&brush, cx - rx, cy - ry, 2 * rx, 2 * ry);
	graphics.DrawEllipse(&pen, cx - rx, cy - ry, 2 * rx, 2 * ry);	
}
     