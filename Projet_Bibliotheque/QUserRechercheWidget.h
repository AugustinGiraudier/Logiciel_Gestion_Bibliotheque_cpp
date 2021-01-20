#pragma once

#include <QWidget>
#include "ui_QUserRechercheWidget.h"
#include "QLivreWidget.h"
#include <vector>
#include "Tags.h"
#include "QWidgetWithBdd.h"

class QUserRechercheWidget : public QWidget
{
	Q_OBJECT

public:
	/*
	\brief prépare le scroll area à recevoir des widgets*/
	QUserRechercheWidget(QWidget *parent = Q_NULLPTR);
	~QUserRechercheWidget();

private:
	Ui::QUserRechercheWidget ui;
	std::vector<QLivreWidget*> m_ElementsScrolables; //vecteur de pointeurs vers les éléments du scroll area
	QVBoxLayout* m_ScrollLayout;	//référence vers le layout du scroll area
	bool m_RechercheEstSurTitre;	//conserve l'etat du type de recherche

	/*\brief delete tous les elements à l'ecran et de m_ElementsScrolables*/
	void ViderScrollArea();
	/*\brief recherche et affiche tous les livres correspondants à la recherche*/
	void AfficherLivres();
	/*\brief ajoute un element au scroll area
	\param recupere tous les elements d'un livre -> si dispo null, il est considéré comme disponible*/
	void AjouterItem(QString Titre, QString Auteur, QString Resume, int Ref, QString Dispo = NULL);
	/*\brief ajoute plusieurs elements au scroll area
	\param vector de CLivre* : défifnit les livres à ajouter*/
	void AjouterItems(std::vector<CLivre*> vecLivres);

public slots:


	/*\brief switch la donne membre m_RechercheEstSurTitre*/
	void RechercheParTitre(bool a);
	/*\brief recherche en fonction du parametre stocké dans m_RechercheEstSurTitre*/
	void Rechercher();
};
