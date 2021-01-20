#ifndef __TAGS_H__
#define __TAGS_H__

/*
\brief classe contenant les différents tags possibles pour un livre 
indexés de 0 à 9*/
enum class Tags
{
	Policier = 0,
	Aventure,
	Action,
	Enfants,
	Science_Fiction,
	Science,
	Politique,
	Histoire,
	Fantastique,
	Divers = 9
};
#endif // !__TAGS_H__