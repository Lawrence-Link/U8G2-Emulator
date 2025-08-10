#pragma once

#include <iostream>
#include "u8g2_wrapper.h"
#include "emulator_arg_parser.h"

void refreshTerminal(U8G2Wrapper &display, const ArgParser::Args& args);