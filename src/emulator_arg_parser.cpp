#include "emulator_arg_parser.h"
#include <iostream>
#include <cstring>


namespace ArgParser {
    Args parse(int argc, char* argv[]) {
    Args args;

    for (int i = 1; i < argc; ++i) {
        const char* arg = argv[i];
        if (strncmp(arg, "-B=", 3) == 0 && strlen(arg) > 4) {
            args.pixel_off = arg[3];
        } else if (strncmp(arg, "-W=", 3) == 0 && strlen(arg) > 4) {
            args.pixel_on = arg[3];
        } else {
            std::cerr << "Unknown argument: " << arg << std::endl;
        }
    }

    return args;
}
}