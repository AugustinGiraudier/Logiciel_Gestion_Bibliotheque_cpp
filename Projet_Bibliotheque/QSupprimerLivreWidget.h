#pragma once

#include <QWidget>
#include "ui_QSupprimerLivreWidget.h"
#include "QWidgetWithBdd.h"

class QSupprimerLivreWidget : public QWidget
{
	Q_OBJECT

public:
	QSupprimerLivreWidget(QWidget *parent = Q_NULLPTR);
	~QSupprimerLivreWidget();

private:
	Ui::QSupprimerLivreWidget ui;

public slots:
	/*\brief v�rifie les champs utilisateurs et supprime le livre de la base de donn�es*/
	void Supprimer();
};
