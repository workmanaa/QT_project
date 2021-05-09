#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QDebug>
#include <QAction>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(600,400);
     qDebug()<<"create a menu\n";
    /* 菜单栏使用 */
    //创建菜单栏
    QMenuBar *bar = menuBar();
    setMenuBar(bar);
    //设置菜单名字，不加图标
    QMenu *fileMenu = bar->addMenu("文件");
    //菜单加选项 1
//    QAction *newfileAction = fileMenu->addAction("新建");
//    QAction *openfileActon = fileMenu->addAction("打开");
//    QAction *exitAction = fileMenu->addAction("关闭");
//    //信号与槽
//    connect(newfileAction,&QAction::triggered,this,&MainWindow::slot_nenfilechange);   //trigered 触发，点
    //菜单加选项 2
    QList <QAction *> actionList;
    actionList.append(new QAction("新建"));
    actionList.append(new QAction("打开"));
    actionList.append(new QAction("关闭"));
    actionList.append(new QAction("帮助"));
    fileMenu->addActions(actionList);
    //信号与槽
    connect(bar,SIGNAL(triggered(QAction*)),this,SLOT(slot_trggledaction(QAction*)));

    bar->addSeparator();//加分割线

    //设置菜单名字，加图标
    QIcon imageIcon(":/myImage/image/menu.png");
    QMenu *toolMenu = bar->addMenu(imageIcon,"工具");
    QAction *toolAction1 = toolMenu->addAction("编辑");
    /* 工具栏使用 */
    //创建工具栏
    QToolBar *toolbar=new QToolBar(this);
    addToolBar(Qt::BottomToolBarArea,toolbar);  //设置状态在底部显示
    // 添加工具栏项目

    toolbar->addAction("编辑");
    toolbar->addAction("打开的文档");
    connect(toolbar,SIGNAL(actionTriggered(QAction*)),this,SLOT(slot_actionchoice(QAction*)));
    /*状态栏使用*/
    //创建状态栏
    QStatusBar *mystatubar = new QStatusBar();
    setStatusBar(mystatubar);

    //添加状态栏项目
    QLabel *label_1=new QLabel("seting",this); //在左边开始添加
    mystatubar->addWidget(label_1);
    QLabel *label_2 = new QLabel("question",this); //在右边开始添加
    mystatubar->addPermanentWidget(label_2);

    /* 浮动窗口使用 */
    //创建浮动窗口
    QDockWidget *mydockwidget=new QDockWidget("浮动窗口",this);
    addDockWidget(Qt::RightDockWidgetArea,mydockwidget);
    //设置中心部件
    QTextEdit *mytextedit=new QTextEdit(this);
    setCentralWidget(mytextedit);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::slot_nenfilechange()
{
    qDebug()<< "new file change\n";

}

 void MainWindow::slot_trggledaction(QAction *atn)
 {

     qDebug()<<"who is action? is "<<atn->text();
    //QString atntext = atn->text();

 }

 void MainWindow::slot_actionchoice(QAction* atn)
 {

     qDebug()<<"who is action? is "<<atn->text();
 }
