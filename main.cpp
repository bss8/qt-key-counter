/**
* @author Borislav S. Sabotinov
* Main driver for the lower case key press counter program.
*
*/
#include "mainwindow.h"

#include <QApplication>

/**
 * @brief qMain
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
