#include <SDL.h>
#include <exception>
#include <iostream>
#include <string>

class SystemManager {
public:
	// Here we will just have a couple public members for example purposes.
	bool running;
	SDL_Event events;
	void inputManager(); // Handle input.
	void renderingManager(); // Handle drawing pretty pictures.
};

void SystemManager::inputManager() {
	while (SDL_PollEvent(&events)) {
		if (events.type == SDL_QUIT)
			running = false;
	}
}

void SystemManager::renderingManager() {
	// Draw pretty pictures...
}

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	// Make your screen here...
	SystemManager sysMgr;
	sysMgr.running = true;
	// Game Loop:
	while (sysMgr.running) {
		sysMgr.inputManager();
		sysMgr.renderingManager();
	}
	// Don't forget to quit SDL:
	SDL_Quit();
	return 0;
}