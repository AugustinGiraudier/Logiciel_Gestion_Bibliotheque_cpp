#include "Projet_Bibliotheque.h"
#include <QtWidgets/QApplication>
#include <QtSql/QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Projet_Bibliotheque w;

    w.show();
    return a.exec();
}
