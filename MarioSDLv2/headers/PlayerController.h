#pragma once
#include "Global.h"
#include "EntityManager.h"

class PlayerController {
	public:
		PlayerController(EntityManager* entityManager, double& deltaTime);
		~PlayerController();

		void Tick();
		void KeyboardEvent(SDL_Event& event, const Uint8* state);

	private:
		float m_gravity;
		float m_speed;
		float m_speedCap;
		float m_jumpHeight;
		float m_slowDown;

		double* m_deltaTime;

		bool m_grounded;
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

		VectorF2D* m_velocity;
		VectorF2D* m_position;

		void Update();

		void Jump();
		void Crouch();

};