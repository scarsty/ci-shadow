#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "opencv2/opencv.hpp"
#include "DrawStringFT.h"
#include "convert.h"
#include "Random.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m3 = cv::Mat::zeros(200, 1000, CV_8UC1);

    auto str1 = convert::readStringFromFile("chengyu.txt");
    convert::replaceAllSubStringRef(str1,"\r","");
    strs = convert::splitString(str1,"\n");
    select_str();
    ui->textEdit->installEventFilter(this);//步骤一
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::abc()
{
    std::string str1 = ui->textEdit->toPlainText().toStdString();
    cv::Mat m2 = cv::Mat::zeros(200, 1000, CV_8UC1);

    DrawStringFT f1;
    f1.openFont("C:\\Windows\\Fonts\\simkai.ttf", 100);
    f1.drawString(str1, m2, 0, 50);

    RandomDouble r;
    m3.forEach<uint8_t>([&](uint8_t& f, const int* position)
    {
        if (m1.at<uint8_t>(position) > 0 && m2.at<uint8_t>(position) == 255 && r.rand()<0.2)
        {
            f = m1.at<uint8_t>(position);
        }

    });

    if (str==str1)
    {
        ui->textEdit->setPlainText(u8"正确！");
        m3=m1;
    }
    show_shadow();

}

void MainWindow::show_shadow()
{
    cv::Mat m;
    cv::cvtColor(m3, m, cv::COLOR_GRAY2BGR);
    cv::Mat srcImage =m;
    cv::cvtColor(srcImage,srcImage,cv::COLOR_BGR2RGB);

    QImage disImage=QImage((const unsigned char*)srcImage.data, srcImage.cols,srcImage.rows,QImage::Format_RGB888);//888是三通道

    ui->label->setPixmap(QPixmap::fromImage(disImage.scaled(ui->label->size(), Qt::KeepAspectRatio)));
}

void MainWindow::select_str()
{
    int n = strs.size();
    RandomDouble r;
    int i = r.rand() * n;
    str = strs[i];
    if (str.size()>12) {str = str.substr(0,12);}
    qDebug()<<str.c_str();
    m3 = cv::Mat::zeros(200, 1000, CV_8UC1);
    m1 = m3.clone();
    DrawStringFT f1;
    f1.openFont("C:\\Windows\\Fonts\\simkai.ttf", 100);
    f1.drawString(str, m1, 0, 50);

    m3.forEach<uint8_t>([&](uint8_t& f, const int* position)
    {
        if (r.rand()<0.03)
        {
            f = m1.at<uint8_t>(position);
        }

    });
    ui->textEdit->setPlainText(u8"");

    show_shadow();
}

bool MainWindow::eventFilter(QObject *object, QEvent *event)//步骤二
{
    if (object == ui->textEdit && event->type() == QEvent::KeyPress)
    {
        QKeyEvent *e = static_cast <QKeyEvent *> (event);
        if (e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return)//步骤三
        {
            abc();//步骤四
            return true;
        }
    }
    return QWidget::eventFilter(object, event);
}
void MainWindow::on_pushButton_clicked()
{
    abc();
}

void MainWindow::on_pushButton_2_clicked()
{
    select_str();
}
