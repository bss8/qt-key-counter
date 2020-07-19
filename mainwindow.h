#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QWidget>
#include <QtGui>

#include <QLCDNumber>

QT_BEGIN_NAMESPACE
class QGroupBox;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void keyPressEvent(QKeyEvent *keyevent);
    void keyReleaseEvent(QKeyEvent *);
private:
    QLCDNumber *lcd;
    QGroupBox *createLayout();
};
#endif // MAINWINDOW_H
