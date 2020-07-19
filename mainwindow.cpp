/**
* @author Borislav S. Sabotinov
* Implementation for mainwindow.h definitions
* This program implements the keyPressEvent and keyReleaseEvent functions
* to handle a key press event (we handle events and get notified of signal emissions).
*/
#include "mainwindow.h"

#include <QGroupBox>
#include <QVBoxLayout>
#include <QKeyEvent>

/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setCentralWidget(MainWindow::createLayout());
    setWindowTitle(tr("Key Counter Program"));
    resize(424, 500);
}

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{

}

/**
 * We get the QString of the event, convert it to a QByteArray so we can finally convert it to a char*
 * We can then use built-in islower() to check for lower case
 * To be safe and for practice, I check Qt modifiers to make sure Shift key is not being pressed
 *
 * We do not use magic numbers for key character values, instead we use A-Z as we are interested in
 * letter key presses.
 *
 * "GetAsyncKeyState: Determines whether a key is up or down at the time the function is called, and whether the key was
 * pressed after a previous call."
 *
 * @brief MainWindow::keyPressEvent
 * @param event
 */
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    QString qString = event->text();
    QByteArray byteArray = qString.toLocal8Bit();
    const char *c_str_val = byteArray.data();
    printf("str2: %s", c_str_val);

    for (int i = 'A'; i <= 'Z'; i++) {
        if(GetAsyncKeyState(i) &&
                std::islower(c_str_val[0]) &&
                !(event->modifiers() & Qt::SHIFT))
        {
            int lcdVal = lcd->value();  // get current lcd value
            lcdVal++;                   // increment the value
            lcd->display(lcdVal);       // set the lcd display to the new value
        }
    }
}

/**
 * @brief MainWindow::keyReleaseEvent
 * @param event
 */
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    // Leaving empty as we do not need to do anything when a key is released
}

/**
 * @brief MainWindow::createLayout
 * @return
 */
QGroupBox *MainWindow::createLayout()
{
    QGroupBox *groupBox = new QGroupBox("Lower k&ey presses (Shift cannot be pressed, CAPS cannot be on): ");
    lcd = new QLCDNumber;
    lcd->setPalette(QColor(155,185,40,255));  // a splash of color for fun
    lcd->display(0);
    QVBoxLayout *vbox = new QVBoxLayout;

    vbox->addWidget(lcd);
    groupBox->setLayout(vbox);
    return groupBox;
}
