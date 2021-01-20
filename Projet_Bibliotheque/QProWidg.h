#pragma once

#include "QWidgetWithBdd.h"
#include "QAjoutLivreWidget.h"
#include "QSupprimerLivreWidget.h"
#include "QEmpruntWidget.h"
#include "QRestitutionWidget.h"
#include "ui_QProWidg.h"

class QProWidg : public QWidgetWithBdd
{
	Q_OBJECT

public:
	QProWidg(QWidget *parent = Q_NULLPTR);
	~QProWidg();


private:
	Ui::QProWidg ui;

public slots:
	/*
	\brief ouvre le pop-up de formulaire pour ajouter un livre � la base de donn�e*/
	void BtnNouveauLivre();
	/*\brief ouvre le pop-up de formulaire pour supprimer un livre � la base de donn�e*/
	void BtnSupprLivre();
	/*\brief ouvre le pop-up de formulaire pour emrunter un livre de la base de donn�e*/
	void BtnEmprunt();
	/*\brief ouvre le pop-up de formulaire pour rendre un livre de la base de donn�e*/
	void BtnRestitution();
};
