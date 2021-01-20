#include "QRestitutionWidget.h"

QRestitutionWidget::QRestitutionWidget(QWidget *parent)
	: QWidget(parent)
{
	//supressio automatique � la fermeture :
	setAttribute(Qt::WA_DeleteOnClose);
	setWindowFlags(Qt::Dialog | Qt::Popup);
	this->setWindowModality(Qt::WindowModality::WindowModal);

	ui.setupUi(this);
}

QRestitutionWidget::~QRestitutionWidget()
{
}

void QRestitutionWidget::Restituer()
{
	//v�rification de la r�f�rence :
	if (!QWidgetWithBdd::VerifierReference(ui.LineRef))
	{
		ui.LabelError->setText("Erreur : Reference invalide...");
		return;
	}
	QString reference = ui.LineRef->text();

	//envoi de la requete
	((QWidgetWithBdd*)(parentWidget()))->RestituerLivre(reference.toInt());

	//fermeture du popup
	this->close();
}
