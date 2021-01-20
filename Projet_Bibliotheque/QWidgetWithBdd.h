#pragma once

#include <QWidget>
#include <QtSql/QtSql>
#include <QLabel>
#include <vector>
#include <qlineedit.h>
#include "Tags.h"
#include "CLivre.h"


class QWidgetWithBdd : public QWidget
{
	Q_OBJECT

		static const int NBR_LIVRE_MAX_PAR_TAG = 10; //d�termine combien de livres seront affich�s au maximum dans l'onglet d�couverte
public:
	QWidgetWithBdd(QWidget *parent);
	~QWidgetWithBdd();

	/*\brief vreifie que la r�f�rence ne soit pas vide et qu'elle ne contienne que des caracteres numeriques
	\param QLineEdit* : objet sur lequel se fait la verification
	\return bool : vrai si la r�f�rence est correcte*/
	static bool VerifierReference(QLineEdit* ref);

	/*\brief verifie si le livre est libre ou emprunt�
	\param int : r�f�rence du livre sur lequel porte la verification
	\return QString : la date de restitution ou une chaine vide si le livre est libre*/
	static QString EstEmprunte(int reference);

	/*\brief recupere tous les livres poss�dants un tag
	\param enum Tags : le tag recherch�
	\return vector de CLivre* : vecteur de tous les livres trouv�s, sous forme d'objets*/
	static std::vector<CLivre*> RecupererLivresWithTag(enum Tags Tag);

	/*\brief recupere tous les livres poss�dant une chaine dans le titre ou dans le nom de l'auteur
	\param bool IsWithTitle : vrai pour une recherche par titre / faux pour une recherche par auteur
	\param QString Recherche : chaine � rechercher
	\return vector de CLivre * : vecteur de tous les livres trouv�s, sous forme d'objets*/
	static std::vector<CLivre*> RecupererLivresWithString(bool IsWithTitle, QString Recherche);


private:
	/*
	\brief v�rifie si une chaine ne comporte que des nombres
	\param QString& str : r�f�rence vers la chaine � tester
	\return bool : true si la chaine n'a que des nombres, sinon false*/
	static bool StringOnlyHaveNumbers(QString& str);

	/*
	\brief ajoute en base de donn�e un tag � un livre
	\param int LivreId : id du livre auquel ajouter le tag
	\param enum Tags tag : tag � ajouter au livre */
	void AjouterTag(int LivreID, enum Tags tag);

public:
	/*
	\brief Ajoute un nouveau livre � la base de donn�e
	\param QString Titre : titre du livre
	\param QString Auteur : auteur du livre
	\param QString Resume : r�sum� du livre
	\param std::vector<enum Tags> CheckedBoxesList : vecteur contenant tous les tags � ajouter pour ce livre*/
	virtual void AjouterLivre(QString Titre, QString Auteur, QString Resume, std::vector<enum Tags> CheckedBoxesList);

	/*
	\brief supprime un livre de la base de donn�e ainsi que tous ses tags
	\param int Reference : r�f�rence (id) du livre � supprimer*/
	virtual void SupprimerLivre(int Reference);

	/*\brief met � jour la date de retour du livre
	\param int Reference : r�f�rence du livre emprunt�
	\param int NbrDeJours : nombre de jours � ajouter � la date courrante avant le retour du livre*/
	virtual void EmprunterLivre(int Reference, int NbrDeJours);

	/*\brief place NULL dans la colonne date de retour d'un livre de la base de donn�e
	\param int Reference : r�f�rence du livre rendu*/
	virtual void RestituerLivre(int Reference);

};
