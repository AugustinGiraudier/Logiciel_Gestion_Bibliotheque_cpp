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
	\brief v�rifie les informations entr�s et lance la requete d'ajout d'un livre � la base de donn�es*/
	void Valider();
};
