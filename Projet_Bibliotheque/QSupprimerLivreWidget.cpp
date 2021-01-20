#include "QSupprimerLivreWidget.h"

QSupprimerLivreWidget::QSupprimerLivreWidget(QWidget *parent)
	: QWidget(parent)
{
	//destruction automatique lors de la fermeture :
	setAttribute(Qt::WA_DeleteOnClose); 
	setWindowFlags(Qt::Dialog | Qt::Popup);
	this->setWindowModality(Qt::WindowModality::WindowModal);

	ui.setupUi(this);
}

QSupprimerLivreWidget::~QSupprimerLivreWidget()
{
}

void QSupprimerLivreWidget::Supprimer()
{
	//vérification de la référence :
	if (!QWidgetWithBdd::VerifierReference(ui.LineRef))
	{
		ui.LabelError->setText("Erreur : Reference invalide...");
		return;
	}
	QString reference = ui.LineRef->text();

	//envoie de la requete :
	((QWidgetWithBdd*)(parentWidget()))->SupprimerLivre(reference.toInt());

	//fermeture du widget (qui se detruit automatiquement) 
	this->close();
}
