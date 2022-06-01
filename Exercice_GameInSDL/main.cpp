//Bibliothèque C/C++
#include <stdio.h>
#include <iostream>

//Bibliothèque SDL :
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

//Début programme main
int main(int argc, char** argv)
{

    //Initialisation simple
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stdout, "Échec de l'initialisation de la SDL (%s)\n", SDL_GetError());
        return -1;
    }

    {
        //Vie de la fenêtre
        SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            640,
            480,
            SDL_WINDOW_SHOWN);

        //Tant que la fenêtre est vivante
        if (pWindow)
        {
            SDL_Event event;
            bool isOpen{ true };

            //Gestion FPS
            unsigned int n_tactual = SDL_GetTicks();
            unsigned int n_tframe = SDL_GetTicks();
            double deltatime = 0;
            int fps = 0;

            while (isOpen)
            {
                n_tactual = SDL_GetTicks();                                     //actualise le tick actuel
                deltatime = n_tactual - n_tframe;                               //calcul le delta entre le tick actuel et tick de la frame                                        

                if (deltatime >= (1000/60)) {                                   //Vérifie frame 60

                    n_tframe = SDL_GetTicks();                                  //sauvegarde du tick de la dernière frame

                    fps = 1000/deltatime;                                       //Calcul FPS

                    if (fps!=62)
                    {
                        printf_s("fps : %d \n", fps);                           //Affichage FPS console anomalie
                    }
                    /*else
                    {
                        printf_s("fps : %d \n", fps);                            //Affichage FPS console habitude
                    }*/
                    deltatime = 0;

                    //meca()
                    //Update()
                    //Render()
                }


                //Mort de la fenêtre
                SDL_PollEvent(&event);
                switch (event.type)
                {
                case SDL_QUIT:                                                  //Evènement fermeture de la fenêtre
                    isOpen = false;
                    break;

                default:                                                        //Evènement par défaut
                    break;
                }
            }

            SDL_DestroyWindow(pWindow);                                         //Fermeture de la fenêtre
        }
        else
        {
            fprintf(stderr, "Erreur de création de la fenêtre: %s\n", SDL_GetError());
        }

    }

    //Fin programme main

    SDL_SetRenderDrawColor;
    SDL_Quit();

    return 0;
}