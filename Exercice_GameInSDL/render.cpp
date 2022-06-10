#include "biblio.h"


/*void Afficher(SDL_Surface* screen, SDL_Surface* tileset, char** table, int nombre_blocs_largeur, int
	nombre_blocs_hauteur)
{
	int i, j;
	SDL_Rect Rect_dest;
	SDL_Rect Rect_source;
	Rect_source.w = 15;
	Rect_source.h = 20;
	for (i = 0; i < nombre_blocs_largeur; i++)
	{
		for (j = 0; j < nombre_blocs_hauteur; j++)
		{
			Rect_dest.x = i * 15;
			Rect_dest.y = j * 20;
			Rect_source.x = (table[j][i] - '0') * 15;
			Rect_source.y = 0;
			SDL_BlitSurface(tileset, &Rect_source, screen, &Rect_dest);
		}
	}*/