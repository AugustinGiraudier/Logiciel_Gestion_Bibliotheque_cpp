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
	\brief pr�pare le scroll area � recevoir des widgets*/
	QUserRechercheWidget(QWidget *parent = Q_NULLPTR);
	~QUserRechercheWidget();

private:
	Ui::QUserRechercheWidget ui;
	std::vector<QLivreWidget*> m_ElementsScrolables; //vecteur de pointeurs vers les �l�ments du scroll area
	QVBoxLayout* m_ScrollLayout;	//r�f�rence vers le layout du scroll area
	bool m_RechercheEstSurTitre;	//conserve l'etat du type de recherche

	/*\brief delete tous les elements � l'ecran et de m_ElementsScrolables*/
	void ViderScrollArea();
	/*\brief recherche et affiche tous les livres correspondants � la recherche*/
	void AfficherLivres();
	/*\brief ajoute un element au scroll area
	\param recupere tous les elements d'un livre -> si dispo null, il est consid�r� comme disponible*/
	void AjouterItem(QString Titre, QString Auteur, QString Resume, int Ref, QString Dispo = NULL);
	/*\brief ajoute plusieurs elements au scroll area
	\param vector de CLivre* : d�fifnit les livres � ajouter*/
	void AjouterItems(std::vector<CLivre*> vecLivres);

public slots:


	/*\brief switch la donne membre m_RechercheEstSurTitre*/
	void RechercheParTitre(bool a);
	/*\brief recherche en fonction du parametre stock� dans m_RechercheEstSurTitre*/
	void Rechercher();
};
