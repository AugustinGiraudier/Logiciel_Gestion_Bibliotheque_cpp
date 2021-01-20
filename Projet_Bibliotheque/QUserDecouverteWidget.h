#pragma once

#include <QWidget>
#include <vector>
#include "ui_QUserDecouverteWidget.h"
#include "QLivreWidget.h"
#include "Tags.h"
#include "QWidgetWithBdd.h"

class QUserDecouverteWidget : public QWidget
{
	Q_OBJECT

public:
	/*
	\brief Prépare le scroll area à recevoir des widgets et lui ajoute les livres liés au tag policier (par défaut)*/
	QUserDecouverteWidget(QWidget *parent = Q_NULLPTR);
	~QUserDecouverteWidget();

	/*\brief rafraichit la derniere recherche*/
	void Refresh();

private:
	Ui::QUserDecouverteWidget ui;

	enum Tags m_CurrentTag;	//conserve le tag sur lequel porte la recherche en cours
	std::vector<QLivreWidget*> m_ElementsScrolables;	//vecteur de pointeurs vers les éléments affichés dans le scroll area
	QVBoxLayout* m_ScrollLayout;	//référence vers le layout du scroll area


	/*\brief delete les elements de m_ElementsScrolables et le vide*/
	void ViderScrollArea();
	/*\brief recherche et affiche dans la scroll area les livres de la bdd correspondants
	\param enum Tags : Tag détermine le tag des livres affichés*/
	void AfficherLivres(enum Tags Tag);
	/*\brief ajoute un item au scroll area*/
	void AjouterItem(QString Titre, QString Auteur, QString Resume, int Ref, QString Dispo = NULL);
	/*\brief ajoute plusieurs livres a la scroll area
	\param vector de CLivre* : définit les livres allant etre affichés */
	void AjouterItems(std::vector<CLivre*> vecLivres);

public slots:
	/*\brief Affiche les livres liés à ce tag*/
	void Policier(bool a);
	/*\brief Affiche les livres liés à ce tag*/
	void Action(bool a);
	/*\brief Affiche les livres liés à ce tag*/
	void Aventure(bool a);
	/*\brief Affiche les livres liés à ce tag*/
	void Politique(bool a);
	/*\brief Affiche les livres liés à ce tag*/
	void Histoire(bool a);
	/*\brief Affiche les livres liés à ce tag*/
	void Enfants(bool a);
	/*\brief Affiche les livres liés à ce tag*/
	void SciFi(bool a);
	/*\brief Affiche les livres liés à ce tag*/
	void Science(bool a);
	/*\brief Affiche les livres liés à ce tag*/
	void Fantastique(bool a);
	/*\brief Affiche les livres liés à ce tag*/
	void Divers(bool a);
};
