#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "ui_Projet_Bibliotheque.h"
#include "QProWidg.h"
#include "QUserWidg.h"

#define CHEMIN_BASE_DE_DONNEES "./BiblioDb.sqlite"

class Projet_Bibliotheque : public QMainWindow
{
    Q_OBJECT

public:
    /*
    \brief ouvre la base de donnée et conserve l'adresse du widget user*/
    Projet_Bibliotheque(QWidget *parent = Q_NULLPTR);

    /*
    \brief rafraichit la page "découverte" de l'interface user*/
    void RefreshUser();

private:
    /*
    \brief masque le widget de l'interface professionnelle*/
    void HideProWidget();

    Ui::Projet_BibliothequeClass ui;
    QUserWidg* m_UserWidget; //référence vers le widget d'interface utilisateur
    QSqlDatabase m_Db;  //database générale

public slots:
    /*
    \brief changer l'interface pour celle des utilisateurs*/
    void SwitchUser();
    /*
    \brief changer l'interface pour celle des professionnels*/
    void SwitchPro();
    /*\brief affiche le panneau d'informations sur Qt*/
    void AProposDeQt();
};

