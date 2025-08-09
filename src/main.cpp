#include <iostream>
#include "emulator_arg_parser.h"
#include "u8g2_wrapper.h"

int main(int argc, char *argv[]) {
#ifndef USE_QT_GUI
    std::cout << "U8G2 Emulator - Headless Mode" << std::endl;

    auto args = ArgParser::parse(argc, argv);

    U8G2Wrapper display(128,64);

    display.init();
    display.drawTestString("Hello emu!");

    auto pixels = display.getFramebufferPixels();
    for (const auto& row : pixels) {
        for (bool pixel : row) {
            std::cout << (pixel ? args.pixel_on : args.pixel_off);
        }
        std::cout << '\n';
    }

#else
    

#endif
    return 0;
}