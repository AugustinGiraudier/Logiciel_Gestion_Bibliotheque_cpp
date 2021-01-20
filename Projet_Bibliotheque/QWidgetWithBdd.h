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

		static const int NBR_LIVRE_MAX_PAR_TAG = 10; //détermine combien de livres seront affichés au maximum dans l'onglet découverte
public:
	QWidgetWithBdd(QWidget *parent);
	~QWidgetWithBdd();

	/*\brief vreifie que la référence ne soit pas vide et qu'elle ne contienne que des caracteres numeriques
	\param QLineEdit* : objet sur lequel se fait la verification
	\return bool : vrai si la référence est correcte*/
	static bool VerifierReference(QLineEdit* ref);

	/*\brief verifie si le livre est libre ou emprunté
	\param int : référence du livre sur lequel porte la verification
	\return QString : la date de restitution ou une chaine vide si le livre est libre*/
	static QString EstEmprunte(int reference);

	/*\brief recupere tous les livres possédants un tag
	\param enum Tags : le tag recherché
	\return vector de CLivre* : vecteur de tous les livres trouvés, sous forme d'objets*/
	static std::vector<CLivre*> RecupererLivresWithTag(enum Tags Tag);

	/*\brief recupere tous les livres possédant une chaine dans le titre ou dans le nom de l'auteur
	\param bool IsWithTitle : vrai pour une recherche par titre / faux pour une recherche par auteur
	\param QString Recherche : chaine à rechercher
	\return vector de CLivre * : vecteur de tous les livres trouvés, sous forme d'objets*/
	static std::vector<CLivre*> RecupererLivresWithString(bool IsWithTitle, QString Recherche);


private:
	/*
	\brief vérifie si une chaine ne comporte que des nombres
	\param QString& str : référence vers la chaine à tester
	\return bool : true si la chaine n'a que des nombres, sinon false*/
	static bool StringOnlyHaveNumbers(QString& str);

	/*
	\brief ajoute en base de donnée un tag à un livre
	\param int LivreId : id du livre auquel ajouter le tag
	\param enum Tags tag : tag à ajouter au livre */
	void AjouterTag(int LivreID, enum Tags tag);

public:
	/*
	\brief Ajoute un nouveau livre à la base de donnée
	\param QString Titre : titre du livre
	\param QString Auteur : auteur du livre
	\param QString Resume : résumé du livre
	\param std::vector<enum Tags> CheckedBoxesList : vecteur contenant tous les tags à ajouter pour ce livre*/
	virtual void AjouterLivre(QString Titre, QString Auteur, QString Resume, std::vector<enum Tags> CheckedBoxesList);

	/*
	\brief supprime un livre de la base de donnée ainsi que tous ses tags
	\param int Reference : référence (id) du livre à supprimer*/
	virtual void SupprimerLivre(int Reference);

	/*\brief met à jour la date de retour du livre
	\param int Reference : référence du livre emprunté
	\param int NbrDeJours : nombre de jours à ajouter à la date courrante avant le retour du livre*/
	virtual void EmprunterLivre(int Reference, int NbrDeJours);

	/*\brief place NULL dans la colonne date de retour d'un livre de la base de donnée
	\param int Reference : référence du livre rendu*/
	virtual void RestituerLivre(int Reference);

};
