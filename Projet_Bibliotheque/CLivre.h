#pragma once
#include <QString>
class CLivre
{
private :
	QString m_Titre; //titre du livre
	QString m_Auteur;	//auteur du livre
	QString m_Resume;	//r�sum� du livre
	QString m_Date;	//date de retour pr�vue ou chaine vide si libre
	int m_Ref;	//r�f�rence (id) du livre

public:
	/*
	\brief assignation des donn�es du livre
	\param QString Titre : titre du livre
	\param QString Auteur : Auteur du livre
	\param int Ref : r�f�rence (id) du livre
	\param QString Date : date de retour du livre pr�vue ou chaine vide si libre*/
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
	\brief renvoit le r�sum� du livre
	\return QString : r�sum�*/
	const QString GetResume() const { return m_Resume; }
	/*
	\brief renvoit la date pr�vue pour le retour du livre (ou chaine vide si livre libre) 
	\return QString : date pr�vue pour le retour (ou chaine vide si livre libre)*/
	const QString GetDate() const { return m_Date; }
	/*
	\brief renvoit la r�f�rence du livre
	\return int : r�f�rence*/
	const int GetRef() const { return m_Ref; }

};

