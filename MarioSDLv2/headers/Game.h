#include "SDL.h"
#include "Textures.h"

class Game {
	public: 

		Game();
		~Game();

		bool m_running = true;

	private: 
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		// Temp, TODO: move to renderer class.
		SDL_Texture* m_texTarget; // Used to render textures onto.
		
		SDL_Rect m_texRect;
		SDL_Rect m_srcRect;

		// Temp, TODO: make a texture manager class.
		Texture* tex;

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