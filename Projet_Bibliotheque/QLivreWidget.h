#pragma once

#include <QWidget>
#include <string>
#include "ui_QLivreWidget.h"

class QLivreWidget : public QWidget
{
	Q_OBJECT

public:
	QLivreWidget(QWidget *parent = Q_NULLPTR);
	/*\brief constructeur avec tous les parametres du livre
	\param QString Titre : Titre du livre
	\param QString Auteur : Auteur du livre
	\param QString Resume : Résumé du livre
	\param int Ref : Référence du livre
	\param QString Dispo = NULL : Date de retour du ivre (NULL si non emprunté)
	\param QWidget* parent : widget parent à affilier*/
	QLivreWidget(QString Titre, QString Auteur, QString Resume, int Ref, QString Dispo = NULL, QWidget *parent = Q_NULLPTR);
	~QLivreWidget();

private:
	Ui::QLivreWidget ui;

public slots:
	/*\brief rend visible ou invisible le résumé de l'ouevre
	\param bool a : true -> le résumé sera rendu visible / false -> il sera rendu invisible*/
	void MontrerResume(bool a);
};
