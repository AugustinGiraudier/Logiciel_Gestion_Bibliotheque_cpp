#include "QUserWidg.h"

QUserWidg::QUserWidg(QWidget *parent)
	: QWidgetWithBdd(parent)
{
	ui.setupUi(this);
	ui.WidgetRecherche->hide(); // le widget de decouverte est le widget affiché par defaut
}

QUserWidg::~QUserWidg()
{
}


/*\brief switch entre les widgets de decouverte et de recherche*/
void QUserWidg::Decouverte(bool a)
{
	if (a)
	{
		ui.WidgetDecouverte->show();
		ui.WidgetRecherche->hide();
		return;
	}
	ui.WidgetRecherche->show();
	ui.WidgetDecouverte->hide();
}
