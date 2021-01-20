#pragma once

#include <QWidget>
#include "ui_QEmpruntWidget.h"
#include "QWidgetWithBdd.h"

class QEmpruntWidget : public QWidget
{
	Q_OBJECT

public:
	QEmpruntWidget(QWidget *parent = Q_NULLPTR);
	~QEmpruntWidget();

private:
	Ui::QEmpruntWidget ui;

public slots:
	/*
	\brief lance la procédure d'emprunt du livre (vérification des champs et changement de la date de retour dans la base de donnée)*/
	void Emprunter();
};
