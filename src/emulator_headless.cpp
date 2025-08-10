#include "emulator_headless.h"

void refreshTerminal(U8G2Wrapper &display, const ArgParser::Args& args) {
    auto pixels = display.getFramebufferPixels();
    for (const auto& row : pixels) {
        for (bool pixel : row) {
            std::cout << (pixel ? args.pixel_on : args.pixel_off);
        }
        std::cout << '\n';
    }
}