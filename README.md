# Projet_Bibliotheque

Projet de c++ (Qt) concernant la création d'un logiciel de gestion d'une bibliothèque.

Le Projet est terminé !
Dans cette version, vous pouvez administrer une bibliothèque grâce à sa base de 
données SQLite.

La base de donnée contient une dizaine de livres afin de pouvoir tester les différentes fonctionnalités.
(Attention, la police d'écriture "Neometric Italic" fournie devra être installée sur le système)

fonctionnalités implémentées :

* La relation à une base de données SQLite
* La base de données des livres :
	
	- La table des livres (id, titre, auteur, résumé, date de retour (si emprunté))
	
	- La table des Tags utilisés pour les livres (id, intitulé)
	
	- La table jointure (id, livre_id, tag_id)

* Une interface coté bibliothécaire pouvant gérer :

	- l'emprunt / le retrait d’un livre
	
	- l’inscription / la suppression de livres dans la base de données
	
* Une interface coté utilisateur pouvant gérer :

	- Un système de recherche afin de trouver des livres par auteurs ou par titres
	
	- Une page « découverte » afin de permettre de trouver de nouveaux livres par Tag (policier, Aventure etc…)
	
-> le passage d'une interface à l'autre se fait via la barre de menu

* un design Qt designer afin de prendre soin de vos yeux ! (icones ressources / feuilles de style)
