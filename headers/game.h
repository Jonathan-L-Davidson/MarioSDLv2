#include "SDL.h"
#include <stdio.h>

class Game {
	public: 

		Game();
		~Game();

		bool m_running = true;

	private: 
		SDL_Window* m_window;

		struct Resolution {
			int x = 640;
			int y = 480;
		};

		Resolution m_res;

		void Start();
		void Update();
		void Draw();
		void End();

};