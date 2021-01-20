#pragma once

#include <QWidget>
#include "ui_QRestitutionWidget.h"
#include "QWidgetWithBdd.h"

class QRestitutionWidget : public QWidget
{
	Q_OBJECT

public:
	QRestitutionWidget(QWidget *parent = Q_NULLPTR);
	~QRestitutionWidget();

private:
	Ui::QRestitutionWidget ui;

public slots:
	/*
	\brief v�rifie les champs utilisateur et envoie les inforamtions � la base de donn�es*/
	void Restituer();
};
