#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

typedef enum Etat {

	Idle, Left, Right, Up, Down


} Etat;




typedef struct Joueur {


	int x;
	int y;											//Les coordonn�es du joueur : J.x et J.y dans le main

	Etat JoueurEtat;

};

typedef struct Joueur Joueur;


void mouvement(Joueur*);
void afficheEtat();
void update(Joueur*);

typedef struct Position {
	int n_x; //Abscisse
	int n_y; //Ordonn�e
};










/*
typedef struct Caillou {

	private:
		int x, y; //Les coordonn�es de l'objet
};

typedef struct Ennemi {

	private:
		int x, y; //Les coordonn�es de l'ennemi

};

typedef struct Objectif {

	private:
		int x, y; //Les coordonn�es de l'objectif � atteindre

};
*/