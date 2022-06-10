#include "objets.h"
#include <stdio.h>
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

Joueur J;
Position Pos;

void mouvement(Joueur *j){

	SDL_Event event;
	while (SDL_PollEvent(&event)) {

		switch (event.type) {

		case SDL_PRESSED:
			switch (event.key.keysym.sym) {
			case (SDLK_LEFT): 
				j->JoueurEtat = Left;
				
				break;

			case (SDLK_RIGHT):
				j->JoueurEtat = Right;
				
				break;

			case (SDLK_UP): 
				j->JoueurEtat = Up;
				
				break;

			case (SDLK_DOWN): 
				j->JoueurEtat = Down;
			
				break;
			}

		case SDL_RELEASED:
			switch (event.key.keysym.sym) {
			case (SDLK_LEFT):
				j->JoueurEtat = Idle;
				
				break;

			case (SDLK_RIGHT): 
				j->JoueurEtat = Idle;
				
				break;

			case (SDLK_UP): 
				j->JoueurEtat = Idle;
				
				break;

			case (SDLK_DOWN): 
				j->JoueurEtat = Idle;
				
				break;

			}
		}
	}
};

	void afficheEtat() {

		printf("x : %d\n", J.x);
		printf("y : %d\n", J.y);
	}

	void update(Joueur *j) {
		//GAUCHE
		if (j->JoueurEtat == Left) { //Si on appuie sur la flèche de gauche
			j->x = j->x - 32; //On retire 32 à l'abscisse du Joueur
			printf("x : %d\n", j->x);
			
			
		}
		
		/*if (J.JoueurEtat == Idle) {
			J.x = J.x; //Si on est en état Idle, donc si la touche est relâchée, on garde l'abscisse actuelle
			printf("x : %d\n", J.x);
		}*/

		//DROITE
		if (j->JoueurEtat == Right) { //Si on appuie sur la flèche de droite
			j->x = j->x + 32; //On ajoute 32 à l'abscisse du Joueur
			printf("x : %d\n", j->x);
		}
		/*if (J.JoueurEtat == Idle) {
			J.x = J.x; //Si on est en état Idle, donc si la touche est relâchée, on garde l'abscisse actuelle
			printf("x : %d\n", J.x);
		}*/

		//HAUT
		if (j->JoueurEtat == Up) { //Si on appuie sur la flèche du haut
			j->y = j->y + 32; //On ajoute 32 à l'ordonnée du Joueur
			printf("y : %d\n", j->y);
		}
		/*else if (J.JoueurEtat == Idle) {
			J.y = J.y; //Si on est en état Idle, donc si la touche est relâchée, on garde l'ordonnée actuelle
			printf("y : %d\n", J.y);
		}*/

		//BAS
		if (j->JoueurEtat == Down) { //Si on appuie sur la flèche du bas
			j->y = j->y - 32; //On retire 32 à l'ordonnée du Joueur
			printf("y : %d\n", j->y);
		}
		/*else if (J.JoueurEtat == Idle) {
			J.y = J.y; //Si on est en état Idle, donc si la touche est relâchée, on garde l'ordonnée actuelle
			printf("y : %d\n", J.y);
		}*/


	}

