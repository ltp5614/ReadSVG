#include "Line.h"

Line::Line(int x1, int y1, int x2, int y2, const std::string& stroke, int stroke_width, double stroke_opacity)
    : x1(x1), y1(y1), x2(x2), y2(y2), stroke(stroke), stroke_width(stroke_width), stroke_opacity(stroke_opacity) {}

void Line::render(HDC hdc) const {
}
