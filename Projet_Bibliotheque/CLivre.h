#pragma once
#include <QString>
class CLivre
{
private :
	QString m_Titre; //titre du livre
	QString m_Auteur;	//auteur du livre
	QString m_Resume;	//résumé du livre
	QString m_Date;	//date de retour prévue ou chaine vide si libre
	int m_Ref;	//référence (id) du livre

public:
	/*
	\brief assignation des données du livre
	\param QString Titre : titre du livre
	\param QString Auteur : Auteur du livre
	\param int Ref : référence (id) du livre
	\param QString Date : date de retour du livre prévue ou chaine vide si libre*/
	CLivre(QString Titre, QString Auteur, QString Resume, int Ref, QString Date);

	/*
	\brief renvoit le titre du livre
	\return QString : titre*/
	const QString GetTitre() const { return m_Titre; }
	/*
	\brief renvoit l'Auteur du livre
	\return QString : Auteur*/
	const QString GetAuteur() const { return m_Auteur; }
	/*
	\brief renvoit le résumé du livre
	\return QString : résumé*/
	const QString GetResume() const { return m_Resume; }
	/*
	\brief renvoit la date prévue pour le retour du livre (ou chaine vide si livre libre) 
	\return QString : date prévue pour le retour (ou chaine vide si livre libre)*/
	const QString GetDate() const { return m_Date; }
	/*
	\brief renvoit la référence du livre
	\return int : référence*/
	const int GetRef() const { return m_Ref; }

};

