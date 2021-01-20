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
	\brief lance la proc�dure d'emprunt du livre (v�rification des champs et changement de la date de retour dans la base de donn�e)*/
	void Emprunter();
};
