#include "SDL.h"
#include "TextureManager.h"

class Game {
	public: 

		Game();
		~Game();

		bool m_running = true;

	private: 
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;

		SDL_Texture* m_texTarget;

		TextureManager* m_texManager;
		SDL_Texture* m_texture;

		SDL_Rect m_texRect;
		SDL_Rect m_srcRect;

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