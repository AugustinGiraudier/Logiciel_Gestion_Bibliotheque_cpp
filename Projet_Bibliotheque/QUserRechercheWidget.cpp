#include "QUserRechercheWidget.h"

QUserRechercheWidget::QUserRechercheWidget(QWidget *parent)
	: QWidget(parent)
	,m_RechercheEstSurTitre(true) //element par defaut
{
	ui.setupUi(this);

	//préparation du scroll area :
	ui.scrollArea->setWidgetResizable(true);
	QWidget* scrollAreaWidget = new QWidget();
	ui.scrollArea->setWidget(scrollAreaWidget);
	QVBoxLayout* scrollAreaLayout = new QVBoxLayout(scrollAreaWidget);
	m_ScrollLayout = scrollAreaLayout;

}

QUserRechercheWidget::~QUserRechercheWidget()
{
}
void QUserRechercheWidget::ViderScrollArea()
{
	//tous les elements ne sont pas supprimes parfaitement, ce sont je crois les ui qui peinent à se supprimer
	while (!m_ElementsScrolables.empty())
	{
		m_ScrollLayout->removeWidget(m_ElementsScrolables[0]);
		delete m_ElementsScrolables[m_ElementsScrolables.size() - 1];
		m_ElementsScrolables.pop_back();
	}
}

void QUserRechercheWidget::AfficherLivres()
{
	//recuperer les donnees : 
	auto tab = QWidgetWithBdd::RecupererLivresWithString(m_RechercheEstSurTitre, ui.LineRecherche->text());
	if(tab.empty())
	{
		ui.LblErreur->setStyleSheet("QLabel{color: white}");
		ui.LblErreur->setText("Aucun resultat...");
		return;
	}
	ui.LblErreur->setText("");
	//les afficher
	AjouterItems(tab);
}

void QUserRechercheWidget::AjouterItem(QString Titre, QString Auteur, QString Resume, int Ref, QString Dispo)
{
	QLivreWidget* lw1 = new QLivreWidget(Titre, Auteur, Resume, Ref, Dispo);
	m_ElementsScrolables.push_back(lw1);
	m_ScrollLayout->addWidget(lw1);
}

void QUserRechercheWidget::AjouterItems(std::vector<CLivre*> vecLivres)
{
	ViderScrollArea(); // réinitialisation du scroll area
	for (auto ptrLivre : vecLivres)
	{
		AjouterItem(ptrLivre->GetTitre(),
			ptrLivre->GetAuteur(),
			ptrLivre->GetResume(),
			ptrLivre->GetRef(),
			ptrLivre->GetDate().isEmpty() ? NULL : ptrLivre->GetDate());
	}
}

/*-----------------------------Slots----------------------------*/

void QUserRechercheWidget::RechercheParTitre(bool a)
{
	m_RechercheEstSurTitre = a;
}

void QUserRechercheWidget::Rechercher()
{
	if (ui.LineRecherche->text().isEmpty())
	{
		ui.LblErreur->setStyleSheet("QLabel{color: rgb(255, 65, 68)}");
		ui.LblErreur->setText("Erreur : Champ vide...");
		return;
	}
	ui.LblErreur->setText("");
	AfficherLivres();
}

