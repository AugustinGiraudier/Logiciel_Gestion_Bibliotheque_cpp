#include "QWidgetWithBdd.h"


QWidgetWithBdd::QWidgetWithBdd(QWidget *parent)
	: QWidget(parent)
{
}

QWidgetWithBdd::~QWidgetWithBdd()
{
}

bool QWidgetWithBdd::VerifierReference(QLineEdit* ref)
{
	if (ref->text().isEmpty())
	{
		return false;
	}
	QString reference = ref->text();
	if (!QWidgetWithBdd::StringOnlyHaveNumbers(reference))
	{
		return false;
	}
	return true;
}

QString QWidgetWithBdd::EstEmprunte(int reference)
{
	QString date;
	QSqlQuery query;
	//requete :
	query.prepare("SELECT date_restitution FROM Livres WHERE id = :id");
	query.bindValue(":id", reference);
	query.exec();
	//récupération des données :
	while (query.next())
	{
		date = query.value(0).toString();
	}
	
	return date;
}

bool QWidgetWithBdd::StringOnlyHaveNumbers(QString& str)
{
	for (QChar a : str)
	{
		if (a < '0' || a > '9')
		{
			return false;
		}
	}
	return true;
}

void QWidgetWithBdd::AjouterTag(int LivreID, enum Tags tag)
{
	QSqlQuery query;
	query.prepare("INSERT INTO Livre_Tag (livre_id, tag_id) VALUES (:lid, :tid)");
	query.bindValue(":lid", LivreID);
	query.bindValue(":tid", ((int)tag)+1);
	query.exec();
}

void QWidgetWithBdd::AjouterLivre(QString Titre, QString Auteur, QString Resume, std::vector<enum Tags> CheckedBoxesList)
{
	//ajout du livre :
	QSqlQuery query;
	query.prepare("INSERT INTO Livres (titre, auteur, resume) "
		"VALUES (:titre, :auteur, :resume)");
	query.bindValue(":titre", Titre);
	query.bindValue(":auteur", Auteur);
	query.bindValue(":resume", Resume);
	query.exec();

	//ID du livre
	int ID = query.lastInsertId().toInt();

	//ajout des tags pour ce livre :
	for (auto i : CheckedBoxesList)
	{
		AjouterTag(ID, i);
	}
}

void QWidgetWithBdd::SupprimerLivre(int Reference)
{
	QSqlQuery query;

	//suppression du livre :
	query.prepare("DELETE FROM Livres WHERE id = :ref");
	query.bindValue(":ref", Reference);
	query.exec();

	//suppression de ses tags :
	query.prepare("DELETE FROM Livre_Tag WHERE livre_id = :ref");
	query.bindValue(":ref", Reference);
	query.exec();
}

void QWidgetWithBdd::EmprunterLivre(int Reference, int NbrDeJours)
{
	QSqlQuery query;
	query.prepare("UPDATE Livres SET date_restitution = :date WHERE id = :id");
	query.bindValue(":date", (QDate::currentDate().addDays(NbrDeJours)).toString("dd.MM.yyyy"));
	query.bindValue(":id", Reference);
	query.exec();
}

void QWidgetWithBdd::RestituerLivre(int Reference)
{
	QSqlQuery query;
	query.prepare("UPDATE Livres SET date_restitution = NULL WHERE id = :id");
	query.bindValue(":id", Reference);
	query.exec();
}

std::vector<CLivre*> QWidgetWithBdd::RecupererLivresWithTag(enum Tags Tag)
{
	std::vector<CLivre*> vecLivres;
	QSqlQuery query;
	//requête : 
	query.prepare("SELECT * FROM Livres INNER JOIN Livre_Tag as t2 ON Livres.id = t2.livre_id WHERE t2.tag_id = :tagid ORDER BY id DESC LIMIT :limit");
	query.bindValue(":tagid", ((int)Tag) + 1);
	query.bindValue(":limit", NBR_LIVRE_MAX_PAR_TAG);
	query.exec();
	//récupération des données :
	while (query.next())
	{
		CLivre* li = new CLivre(query.value(1).toString(), 
								query.value(2).toString(), 
								query.value(3).toString(), 
								query.value(0).toInt(), 
								query.value(4).toString());
		vecLivres.push_back(li);
	}
	return vecLivres;
}

std::vector<CLivre*> QWidgetWithBdd::RecupererLivresWithString(bool IsWithTitle, QString Recherche)
{
	QString Colonne;
	QString Add = "%";
	std::vector<CLivre*> vecLivres;
	QSqlQuery query;

	if (IsWithTitle)
		Colonne = "titre";
	else
		Colonne = "auteur";

	//requête : 
	query.prepare(QString("SELECT * FROM Livres WHERE %1 LIKE :recherche ORDER BY id DESC").arg(Colonne));
	query.bindValue(":recherche", Add + Recherche + Add);
	query.exec();
	//récupération des données :
	while (query.next())
	{
		//créations de pointeur dynamique de CLivre :
		CLivre* li = new CLivre(query.value(1).toString(),
								query.value(2).toString(),
								query.value(3).toString(),
								query.value(0).toInt(),
								query.value(4).toString());
		vecLivres.push_back(li);
	}
	return vecLivres;
}
