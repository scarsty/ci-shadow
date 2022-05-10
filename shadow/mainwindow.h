#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include "opencv2/opencv.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    void abc();

    void show_shadow();

    void select_str();

    cv::Mat m3,m1;
    std::string str;
    std::vector<std::string> strs;

protected:
    virtual bool eventFilter(QObject *object, QEvent *event);
};

#endif // MAINWINDOW_H
