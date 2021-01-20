#include "Projet_Bibliotheque.h"



Projet_Bibliotheque::Projet_Bibliotheque(QWidget *parent)
    : QMainWindow(parent)
{
    //création de la base de donnée générale :
    static QSqlDatabase Db;
    Db = QSqlDatabase::addDatabase("QSQLITE");
    Db.setDatabaseName(CHEMIN_BASE_DE_DONNEES);
    m_Db = Db;
    m_Db.open();

    ui.setupUi(this);
    HideProWidget();//l'interface utilisateur est ouverte par defaut
}

void Projet_Bibliotheque::RefreshUser()
{
    ui.UserWidget->GetUi()->WidgetDecouverte->Refresh();
}

void Projet_Bibliotheque::HideProWidget()
{
    ui.ProWidget->hide();
}

void Projet_Bibliotheque::SwitchPro()
{
    ui.ProWidget->show();
    ui.UserWidget->hide();
}

void Projet_Bibliotheque::AProposDeQt()
{
    QMessageBox::aboutQt(this, "A propos de Qt...");
}

void Projet_Bibliotheque::SwitchUser()
{
    RefreshUser();
    ui.UserWidget->show();
    ui.ProWidget->hide();
}
