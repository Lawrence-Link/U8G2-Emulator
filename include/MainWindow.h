#pragma once

#include <QMainWindow>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setPixels(const std::vector<std::vector<bool>>& pixels);

protected:
    void paintEvent(QPaintEvent *event) override;
    
private:
    std::vector<std::vector<bool>> pixels;

    // Height and width for each pixel block.
    int pixelWidth = 10; 
    int pixelHeight = 10; 

};
