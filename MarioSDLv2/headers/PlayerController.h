#pragma once
#include "Global.h"
#include "EntityManager.h"

class PlayerController {
	public:
		PlayerController(EntityManager* entityManager);
		~PlayerController();

		void Tick();
		void KeyDownCatch(SDL_Event& event);
		void KeyUpCatch(SDL_Event& event);

	private:
		float m_gravity;
		float m_speed;
		float m_speedCap;
		float m_jumpHeight;
		float m_slowDown;

		double* m_deltaTime;

		bool m_isGrounded();

		Vector2D* m_srcRect;

		enum class Stat { LIVING, DEAD, DYING, INVUN };

		Stat m_stat;

		struct KeyPressStates {
			bool UP, DOWN, LEFT, RIGHT, SPACE, SHIFT, ESC = false;
		};

		KeyPressStates pressState;

		Entity* m_player;
		
		EntityManager* m_entityManager;

		Vector2D* m_velocity;
		Vector2D* m_position;

		void Update();

};