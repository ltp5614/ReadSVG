#ifndef SVGELEMENTS_H
#define SVGELEMENTS_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <Windows.h>
#include <gdiplus.h>


class SVGElements {
public:
    virtual void render(HDC hdc) const = 0;
    virtual ~SVGElements() = default;
};

#endif // SVGELEMENTS_H