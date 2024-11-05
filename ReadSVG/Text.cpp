#include "Text.h"

Text::Text(int x, int y, int font_size, const std::string& content, const std::string& fill)
    : x(x), y(y), font_size(font_size), content(content), fill(fill) {}

void Text::render(HDC hdc) const {

}