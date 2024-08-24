#include "loadingdlg.h"
#include "ui_loadingdlg.h"
#include <QLabel>
#include <QMovie>
#include <QGraphicsOpacityEffect>
#include <QGuiApplication>
#include <QScreen>
#include<QStyleOption>
LoadingDlg::LoadingDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoadingDlg)
{
    ui->setupUi(this);
    //加载用户列表出现闪屏的可以在设置窗口标志时将Qt::Dialog改成Qt::Tool
    setWindowFlags(Qt::Tool|Qt::FramelessWindowHint | Qt::WindowSystemMenuHint|Qt::WindowStaysOnTopHint);

    setAttribute(Qt::WA_TranslucentBackground); // 设置背景透明

    // 获取屏幕尺寸
    setFixedSize(parent->size()); // 设置对话框为全屏尺寸


    QMovie *movie = new QMovie(":/res/loading.gif"); // 加载动画的资源文件

    ui->loading_lb->setMovie(movie);
    movie->start();
}

LoadingDlg::~LoadingDlg()
{
    delete ui;
}
