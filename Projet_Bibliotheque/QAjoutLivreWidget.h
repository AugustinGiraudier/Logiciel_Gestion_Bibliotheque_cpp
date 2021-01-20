#pragma once

#include <QWidget>
#include <vector>
#include "ui_QAjoutLivreWidget.h"
#include "QWidgetWithBdd.h"
#include "Tags.h"

class QAjoutLivreWidget : public QWidget
{
	Q_OBJECT

public:
	QAjoutLivreWidget(QWidget *parent = Q_NULLPTR);
	~QAjoutLivreWidget();

private:
	Ui::QAjoutLivreWidget ui;
	std::vector<QCheckBox*> m_setCheckboxes; //liste des checkboxes de Tags de l'ui

public slots:
	/*
	\brief vérifie les informations entrés et lance la requete d'ajout d'un livre à la base de données*/
	void Valider();
};
