#include "biblio.h"
#include "map.h"



#define CACHE_SIZE 5000

void ChargerMap_tileset(FILE* F, Map* m)
{
	int numtile, i, j;
	char buf[CACHE_SIZE];												// un buffer, petite mémoire cache
	char buf2[CACHE_SIZE];												// un buffer, petite mémoire cache
	fscanf_s(F, "%s", buf);												// #tileset
	fscanf_s(F, "%s", buf);												// nom du fichier

	m->tileset = IMG_Load("../Resources/Graphics/tilesets/ground.png");	// chargement de l'image dans le tileset

	fscanf_s(F, "%s", buf);												// #Largeur (w) et hauteur (h) du tileset en nombre de tiles
	fscanf_s(F, "%d %d", &m->nbtilesX, &m->nbtilesY);

	m->LARGEUR_TILE = m->tileset->w / m->nbtilesX;
	m->HAUTEUR_TILE = m->tileset->h / m->nbtilesY;
	m->props = (TileProp*) malloc(m->nbtilesX * m->nbtilesY * sizeof(TileProp));

	//Découpage du tileset
	for (j = 0, numtile = 0; j < m->nbtilesY; j++)
	{
		for (i = 0; i < m->nbtilesX; i++, numtile++)
		{
			m->props[numtile].R.w = m->LARGEUR_TILE;
			m->props[numtile].R.h = m->HAUTEUR_TILE;
			m->props[numtile].R.x = i * m->LARGEUR_TILE;
			m->props[numtile].R.y = j * m->HAUTEUR_TILE;

			fscanf_s(F, "%s %s", buf, buf2);							// Lecture caractéristique (sol, mur, mov) pour chaque tile
			m->props[numtile].mur = 0;
			if (strcmp(buf2, "mur") == 0)
				m->props[numtile].mur = 1;
			if (strcmp(buf2, "mov") == 0)
				m->props[numtile].mur = 2;
		}
	}
}

void ChargerMap_level(FILE* F, Map* m)
{
	int i, j;
	char buf[CACHE_SIZE];												// un buffer, petite mémoire cache
	fscanf_s(F, "%s", buf);												// #level
	fscanf_s(F, "%s", buf);												// #Largeur (w) et hauteur (h) de la map en nombre de tiles
	fscanf_s(F, "%d %d", &m->nbtiles_largeur_monde, &m->nbtiles_hauteur_monde);

	//Allocation mémoire pour chaque largeur
	m->schema = (Uint16**) malloc(m->nbtiles_largeur_monde * sizeof(Uint16));

	//Allocation mémoire pour chaque hauteur de chaque largeur
	for (i = 0; i < m->nbtiles_largeur_monde; i++)
		m->schema[i] = (Uint16*) malloc(m->nbtiles_hauteur_monde * sizeof(Uint16));

	for (j = 0; j < m->nbtiles_hauteur_monde; j++)
	{
		for (i = 0; i < m->nbtiles_largeur_monde; i++)
		{
			int tmp;
			fscanf_s(F, "%d", &tmp);									// Lecture du numéro de chaque tile de la map
			if (tmp >= m->nbtilesX * m->nbtilesY)
			{
				printf("level tile hors limite\n");						// Vérifie si la tuile se trouve dans le tileset
				SDL_Quit();
				system("pause");
				exit(-1);
			}
			m->schema[i][j] = tmp;
		}
	}
}

Map* ChargerMap(const char* level)
{
	Map* m;
	FILE* fTile1 = NULL;
	err = fopen_s(&fTile1, level, "r");
	if (!err)
	{
		printf("fichier %s introuvable !! \n", level);
		SDL_Quit();
		system("pause");
		exit(-1);
	}
	
	m = (Map*) malloc(sizeof(Map));
	ChargerMap_tileset(fTile1, m);
	ChargerMap_level(fTile1, m);
	return m;

	if (fTile1) {
		fclose(fTile1);
	}
}

int AfficherMap(Map* m, SDL_Window* screen)
{
	int i, j;
	SDL_Rect Rect_dest;
	int numero_tile;
	for (i = 0; i < m->nbtiles_largeur_monde; i++)
	{
		for (j = 0; j < m->nbtiles_hauteur_monde; j++)
		{
			Rect_dest.x = i * m->LARGEUR_TILE;
			Rect_dest.y = j * m->HAUTEUR_TILE;
			numero_tile = m->schema[i][j];
			SDL_RenderCopy(renderer, &(m->props[numero_tile].R), screen, &Rect_dest);
		}
	}
	return 0;
}

int LibererMap(Map* m)
{
	int i;
	//SDL_FreeWindow(m->tileset); ?
	for (i = 0; i < m->nbtiles_hauteur_monde; i++)
		free(m->schema[i]);
	free(m->schema);
	free(m->props);
	free(m);
	return 0;
}
