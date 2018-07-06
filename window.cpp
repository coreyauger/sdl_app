//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main( int argc, char* args[] ){
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
		cerr << "SDL could not initialize! SDL_Error: %s\n" << SDL_GetError();
	}
	else{
		//Create window
		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL ){
			cerr << "Window could not be created! SDL_Error: %s\n" << SDL_GetError();
		}
		else{
			screenSurface = SDL_GetWindowSurface( window );
			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
			SDL_UpdateWindowSurface( window );
			SDL_Delay( 2000 );
		}
	}
	SDL_DestroyWindow( window );
	SDL_Quit();
	return 0;
}