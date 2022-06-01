//Biblioth�que C/C++
#include <stdio.h>
#include <iostream>

//Biblioth�que SDL :
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

//D�but programme main
int main(int argc, char** argv)
{

    //Initialisation simple
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stdout, "�chec de l'initialisation de la SDL (%s)\n", SDL_GetError());
        return -1;
    }

    {
        //Vie de la fen�tre
        SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            640,
            480,
            SDL_WINDOW_SHOWN);

        //Tant que la fen�tre est vivante
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

                if (deltatime >= (1000/60)) {                                   //V�rifie frame 60

                    n_tframe = SDL_GetTicks();                                  //sauvegarde du tick de la derni�re frame

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


                //Mort de la fen�tre
                SDL_PollEvent(&event);
                switch (event.type)
                {
                case SDL_QUIT:                                                  //Ev�nement fermeture de la fen�tre
                    isOpen = false;
                    break;

                default:                                                        //Ev�nement par d�faut
                    break;
                }
            }

            SDL_DestroyWindow(pWindow);                                         //Fermeture de la fen�tre
        }
        else
        {
            fprintf(stderr, "Erreur de cr�ation de la fen�tre: %s\n", SDL_GetError());
        }

    }

    //Fin programme main

    SDL_SetRenderDrawColor;
    SDL_Quit();

    return 0;
}