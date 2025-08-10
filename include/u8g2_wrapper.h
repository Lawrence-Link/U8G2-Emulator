#pragma once

#include "u8g2.h"
#include <vector>
#include "../third_party/u8g2/cppsrc/U8g2lib.h"

class U8G2Wrapper : public U8G2 {
public:
    U8G2Wrapper(){}
    U8G2Wrapper(int _width, int _height) : width(_width), height(_height) {};
    ~U8G2Wrapper() = default;

    void init();
    void drawTestString(const char* str);
    std::vector<std::vector<bool>> getFramebufferPixels();

private:
    int width = 128;
    int height = 64;
};
