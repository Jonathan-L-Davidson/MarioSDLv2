#include "SDL.h"
#include "Global.h"
#include "TextureManager.h"
#include "RenderManager.h"

#include "PlayerController.h"


class Game {
	public: 

		Game();
		~Game();

		bool m_running = true;

	private: 
		SDL_Window* m_window;

		Resolution* m_res;

		RenderManager* m_renderManager;
		TextureManager* m_texManager;
		EntityManager* m_entityManager;

		PlayerController* m_playerController;

		double m_deltaTime;
		uint64_t m_frameTime;
		uint64_t m_prevFrameTime;

		void Start();
		void Update();
		void Draw();
		void End();

};