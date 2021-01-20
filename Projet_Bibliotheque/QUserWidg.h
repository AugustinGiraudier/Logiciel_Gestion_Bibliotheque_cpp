#pragma once

#include "QWidgetWithBdd.h"
#include "ui_QUserWidg.h"

class QUserWidg : public QWidgetWithBdd
{
	Q_OBJECT

public:
	/*\brief masque l'onglet recherche et laisse l'onglet decouverte apparent par défaut*/
	QUserWidg(QWidget *parent = Q_NULLPTR);
	~QUserWidg();

	/*\brief getter de l'ui
	\return Ui::QUserWidg**/
	Ui::QUserWidg* GetUi() { return &ui; }


private:
	Ui::QUserWidg ui;

public slots:

	/*\brief switch entre les widgets de decouverte et de recherche*/
	void Decouverte(bool a);
};
