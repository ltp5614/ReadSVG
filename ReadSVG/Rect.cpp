#include "Rect.h"

Rect::Rect(int x, int y, int width, int height, const std::string& fill, double fill_opacity, const std::string& stroke, int stroke_width)
    : x(x), y(y), width(width), height(height), fill(fill), fill_opacity(fill_opacity), stroke(stroke), stroke_width(stroke_width) {}

void Rect::render(HDC hdc) const 
{
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);

	HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);

	Rectangle(hdc, x, y, x + width, y + height);

	SelectObject(hdc, hOldBrush);
	DeleteObject(hBrush);

	SelectObject(hdc, hOldPen);
	DeleteObject(hPen);
}