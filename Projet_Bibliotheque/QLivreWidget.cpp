#include "QLivreWidget.h"

QLivreWidget::QLivreWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.LblResume->hide(); //cache le résumé par defaut
}

QLivreWidget::QLivreWidget(QString Titre, QString Auteur, QString Resume, int Ref, QString Dispo, QWidget* parent)
	:QWidget(parent)
{
	ui.setupUi(this);
	//affichage manuel des infos de l'oeuvre
	ui.LblAuteur->setText(Auteur);
	ui.LblTitre->setText(Titre);
	ui.LblResume->setText(Resume);
	ui.LblRef->setText(QString::number(Ref));
	if (Dispo != NULL)
	{
		QString prefix = "Retour prevu  le : ";
		ui.LblDispo->setText(prefix + Dispo);
		ui.LblDispo->setStyleSheet("QLabel {color: red}");
	}
	else
		ui.LblDispo->setText("Libre");

	ui.LblResume->hide();//cache le résumé par defaut
}

QLivreWidget::~QLivreWidget()
{
}

void QLivreWidget::MontrerResume(bool a)
{
	if (a)
	{
		ui.LblResume->show();
		ui.BtnVoir->setText("Cacher");
		return;
	}
	ui.LblResume->hide();
	ui.BtnVoir->setText("Voir");
}
