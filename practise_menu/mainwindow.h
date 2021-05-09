#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void slot_nenfilechange();


private slots:
    void slot_trggledaction(QAction *atn);
    void slot_actionchoice(QAction* atn);
};

#endif // MAINWINDOW_H
