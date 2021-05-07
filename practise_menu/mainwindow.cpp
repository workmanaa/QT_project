#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    resize(600,400);

    /* 菜单栏使用 */
    //1
    QStringList strList;
    strList << "文件" << "工具" << "构建" <<"帮助";

    //创建菜单栏
    QMenuBar *bar = menuBar();
    setMenuBar(bar);
    //设置菜单名字，不加图标
    QMenu *fileMenu = bar->addMenu("文件");
    QAction *newfileAction = fileMenu->addAction("新建");
    QAction *openfileActon = fileMenu->addAction("打开");
    QAction *exitAction = fileMenu->addAction("关闭");
    //设置菜单名字，加图标
    QIcon imageIcon;
    QMenu *toolMenu = bar->addMenu()





}

MainWindow::~MainWindow()
{
    delete ui;
}
