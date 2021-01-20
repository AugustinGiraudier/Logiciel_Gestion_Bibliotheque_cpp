#include "QEmpruntWidget.h"

QEmpruntWidget::QEmpruntWidget(QWidget *parent)
	: QWidget(parent)
{
	//suppression automatique à la fermeture
	setAttribute(Qt::WA_DeleteOnClose);
	setWindowFlags(Qt::Dialog | Qt::Popup);
	this->setWindowModality(Qt::WindowModality::WindowModal);

	ui.setupUi(this);
}

QEmpruntWidget::~QEmpruntWidget()
{
}

void QEmpruntWidget::Emprunter()
{
	//vérification de la référence :
	if (!QWidgetWithBdd::VerifierReference(ui.LineRef))
	{
		ui.LabelError->setText("Erreur : Reference invalide...");
		return;
	}

	//vérifie que le livre est libre :
	QString date = QWidgetWithBdd::EstEmprunte(ui.LineRef->text().toInt());
	if (!date.isEmpty())
	{
		QString erreur = "Erreur : Livre deja emprunte...\nRetour prevu le : ";
		ui.LabelError->setText(erreur + date);
		return;
	}

	QString reference = ui.LineRef->text();

	//envoi de la requête :
	((QWidgetWithBdd*)(parentWidget()))->EmprunterLivre(reference.toInt(), ui.SpinNbrJours->value());
	this->close();
}
