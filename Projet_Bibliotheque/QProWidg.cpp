#include "QProWidg.h"

QProWidg::QProWidg(QWidget *parent)
	: QWidgetWithBdd(parent)
{
	ui.setupUi(this);
}

QProWidg::~QProWidg()
{
}


void QProWidg::BtnNouveauLivre()
{
	//ouverture du pop-up :
	QAjoutLivreWidget* a = new QAjoutLivreWidget(this);
	a->show();
}

void QProWidg::BtnSupprLivre()
{
	//ouverture du pop-up :
	QSupprimerLivreWidget* a = new QSupprimerLivreWidget(this);
	a->show();
}

void QProWidg::BtnEmprunt()
{
	//ouverture du pop-up :
	QEmpruntWidget* a = new QEmpruntWidget(this);
	a->show();
}

void QProWidg::BtnRestitution()
{
	//ouverture du pop-up :
	QRestitutionWidget* a = new QRestitutionWidget(this);
	a->show();
}
