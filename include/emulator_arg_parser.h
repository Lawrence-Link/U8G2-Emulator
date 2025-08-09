#pragma once

namespace ArgParser {
    struct Args {
    char pixel_off = '□';
    char pixel_on = '■';
};

Args parse(int argc, char* argv[]);
}