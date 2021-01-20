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
	\brief vérifie les champs utilisateur et envoie les inforamtions à la base de données*/
	void Restituer();
};
