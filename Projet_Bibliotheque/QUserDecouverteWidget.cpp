#include "QUserDecouverteWidget.h"

QUserDecouverteWidget::QUserDecouverteWidget(QWidget* parent)
	: QWidget(parent)
	,m_CurrentTag(Tags::Policier) // onglet par defaut
{
	ui.setupUi(this);

	//préparation du scroll area :
	ui.scrollArea->setWidgetResizable(true);
	QWidget* scrollAreaWidget = new QWidget();
	ui.scrollArea->setWidget(scrollAreaWidget);
	QVBoxLayout* scrollAreaLayout = new QVBoxLayout(scrollAreaWidget);
	m_ScrollLayout = scrollAreaLayout;

	//Ajout d'items :
	Policier(true);

}
QUserDecouverteWidget::~QUserDecouverteWidget()
{
}

void QUserDecouverteWidget::Refresh()
{
	AfficherLivres(m_CurrentTag);
}

void QUserDecouverteWidget::ViderScrollArea()
{
	//je n'ai pas reussi à tout supprimer correctement, il est possible que l'ui ne se delete pas...
	while (!m_ElementsScrolables.empty())
	{
		m_ScrollLayout->removeWidget(m_ElementsScrolables[0]);
		delete m_ElementsScrolables[m_ElementsScrolables.size()-1];
		m_ElementsScrolables.pop_back();
	}
}

void QUserDecouverteWidget::AfficherLivres(enum Tags Tag)
{
	m_CurrentTag = Tag;
	//recuperer les donnees : 
	auto tab = QWidgetWithBdd::RecupererLivresWithTag(Tag);
	//les afficher
	AjouterItems(tab);
}

void QUserDecouverteWidget::AjouterItem(QString Titre, QString Auteur, QString Resume, int Ref, QString Dispo)
{
	QLivreWidget* lw1 = new QLivreWidget(Titre, Auteur, Resume, Ref, Dispo);
	m_ElementsScrolables.push_back(lw1);
	m_ScrollLayout->addWidget(lw1);
}

void QUserDecouverteWidget::AjouterItems(std::vector<CLivre*> vecLivres)
{
	ViderScrollArea();
	for (auto ptrLivre : vecLivres)
	{
		AjouterItem(ptrLivre->GetTitre(), 
					ptrLivre->GetAuteur(), 
					ptrLivre->GetResume(), 
					ptrLivre->GetRef(), 
					ptrLivre->GetDate().isEmpty() ? NULL : ptrLivre->GetDate());
	}
}

/*--------------------------------Slots-----------------------------------*/

void QUserDecouverteWidget::Policier(bool a)
{
	if (a)
	{
		AfficherLivres(Tags::Policier);
	}
}
void QUserDecouverteWidget::Action(bool a)
{
	if (a)
	{
		AfficherLivres(Tags::Action);
	}
}

void QUserDecouverteWidget::Aventure(bool a)
{
	if (a)
	{
		AfficherLivres(Tags::Aventure);
	}
}

void QUserDecouverteWidget::Politique(bool a)
{
	if (a)
	{
		AfficherLivres(Tags::Politique);
	}
}

void QUserDecouverteWidget::Histoire(bool a)
{
	if (a)
	{
		AfficherLivres(Tags::Histoire);
	}
}

void QUserDecouverteWidget::Enfants(bool a)
{
	if (a)
	{
		AfficherLivres(Tags::Enfants);
	}
}

void QUserDecouverteWidget::SciFi(bool a)
{
	if (a)
	{
		AfficherLivres(Tags::Science_Fiction);
	}
}

void QUserDecouverteWidget::Science(bool a)
{
	if (a)
	{
		AfficherLivres(Tags::Science);
	}
}

void QUserDecouverteWidget::Fantastique(bool a)
{
	if (a)
	{
		AfficherLivres(Tags::Fantastique);
	}
}

void QUserDecouverteWidget::Divers(bool a)
{
	if (a)
	{
		AfficherLivres(Tags::Divers);
	}
}
