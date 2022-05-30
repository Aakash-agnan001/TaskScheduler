// #include "mainwindow.h"
// #include <QApplication>

// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);
//     MainWindow w;
//     w.setWindowState(Qt::WindowFullScreen);
//     w.show();
//     return a.exec();
// }

#include "./Headers/User.h"

int main() {
    User user;
    user.writeCSV();
    return 0;
}