#include "MainWindow.h"
#include <QPainter>
#include "u8g2_wrapper.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setFixedSize(1280, 640);  // 比如按像素*10放大
}

MainWindow::~MainWindow() {}

void MainWindow::setPixels(const std::vector<std::vector<bool>>& newPixels) {
    pixels = newPixels;
    // 计算像素块大小，保持和窗口宽高对应
    pixelWidth = width() / (pixels.empty() ? 1 : static_cast<int>(pixels[0].size()));
    pixelHeight = height() / (pixels.empty() ? 1 : static_cast<int>(pixels.size()));
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.fillRect(rect(), Qt::black);

    if (pixels.empty()) return;

    for (int y = 0; y < static_cast<int>(pixels.size()); ++y) {
        for (int x = 0; x < static_cast<int>(pixels[y].size()); ++x) {
            if (pixels[y][x]) {
                painter.fillRect(x * pixelWidth, y * pixelHeight, pixelWidth, pixelHeight, Qt::white);
            }
        }
    }
}
