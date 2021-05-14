#include <iostream>
#include <SDL.h>

void loop1(bool& runningWindows) {

}

void loop2(bool& runningWindows) {

}


int main(int argc, char* argv[]) {
	/* Init SDL2 */
	SDL_Init(SDL_INIT_EVERYTHING);

	/* Create windows and renderers */
	SDL_Window* window1 = SDL_CreateWindow("Window 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_Renderer* renderer1 = SDL_CreateRenderer(window1, -1, SDL_RENDERER_PRESENTVSYNC);
	
	SDL_Window* window2 = SDL_CreateWindow("Window 2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_Renderer* renderer2 = SDL_CreateRenderer(window2, -1, SDL_RENDERER_PRESENTVSYNC);
	
	SDL_Event event;
	int runningWindows = 2;

	/* Main loop */
	while (runningWindows > 0) {
		while (SDL_PollEvent(&event) != 0) { //Event polling
			if (event.type == SDL_WINDOWEVENT) {
				if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
					if (event.window.windowID == SDL_GetWindowID(window1)) {
						SDL_DestroyRenderer(renderer1);
						SDL_DestroyWindow(window1);
						runningWindows--;
					}
					else if (event.window.windowID == SDL_GetWindowID(window2)) {
						SDL_DestroyRenderer(renderer2);
						SDL_DestroyWindow(window2);
						runningWindows--;
					}
				}
			}
		}

		
	}

	SDL_Quit();
	return 0;
}