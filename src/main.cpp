#include "iostream"
#include "emulator_arg_parser.h"

#ifdef USE_QT_GUI
#include <QApplication>
#include <QMainWindow>
#endif

int main(int argc, char *argv[])
{
    #ifndef USE_QT_GUI
    std::cout << "U8G2 Emulator - Headless Mode" << std:endl;

    auto args = ArgParser::parse(argc, argv);

    return 0;
    #endif
}