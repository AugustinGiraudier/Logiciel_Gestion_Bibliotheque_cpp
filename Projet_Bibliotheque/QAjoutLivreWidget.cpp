#include "QAjoutLivreWidget.h"


QAjoutLivreWidget::QAjoutLivreWidget(QWidget *parent)
	: QWidget(parent)
{
	//suppression automatique � la fermeture :
	setAttribute(Qt::WA_DeleteOnClose);
	setWindowFlags(Qt::Dialog | Qt::Popup);
	this->setWindowModality(Qt::WindowModality::WindowModal);

	ui.setupUi(this);

	m_setCheckboxes = { ui.BoxPolicier,ui.BoxAventure,ui.BoxAction,ui.BoxEnfants,
						ui.BoxSciFi,ui.BoxScience,ui.BoxPolitique,ui.BoxHistoire,ui.BoxFantastique, ui.BoxDivers };
}

QAjoutLivreWidget::~QAjoutLivreWidget()
{
}

void QAjoutLivreWidget::Valider()
{
	bool NoCheckedBox = true;
	std::vector<enum Tags> CheckedBoxesList;//vecteur destin� � contenir les tags qui ont �t� choisis

	//si au moins un champ vide :
	if (ui.TextResume->toPlainText().isEmpty() | 
		ui.LineAuteur->text().isEmpty() | 
		ui.LineTitre->text().isEmpty())
	{
		ui.TextError->setText("Erreur : champ(s) vide(s)...");
		return;
	}
	
	//on remplisle vecteur avec les tags coch�s par l'utilisateur :
	for (int i = 0; i < m_setCheckboxes.size() ; i++)
	{
		if (m_setCheckboxes[i]->isChecked())
		{
			CheckedBoxesList.push_back((enum Tags)i);
			NoCheckedBox = false;
		}
	}
	if (NoCheckedBox) //si aucun tag n'est coch� :
	{
		ui.TextError->setText("Erreur : Aucun Tag Selectionne...");
		return;
	}

	//sinon :
	//envoi de la requ�te au widget parent et fermeture du pop-up
	((QWidgetWithBdd*)(parentWidget()))->AjouterLivre(ui.LineTitre->text(), ui.LineAuteur->text(), ui.TextResume->toPlainText(),CheckedBoxesList);
	this->close();
}
