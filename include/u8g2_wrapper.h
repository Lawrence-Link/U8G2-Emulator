#pragma once

#include "u8g2.h"
#include <vector>

class U8G2Wrapper {
public:
    U8G2Wrapper(){}
    U8G2Wrapper(int _width, int _height) : width(_width), height(_height) {};
    ~U8G2Wrapper() = default;

    void init();
    void drawTestString(const char* str);
    std::vector<std::vector<bool>> getFramebufferPixels();

private:
    u8g2_t u8g2;
    int width = 128;
    int height = 64;
};
