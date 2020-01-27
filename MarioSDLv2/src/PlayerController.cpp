#include "Global.h"
#include "PlayerController.h"
#include <iostream>

PlayerController::PlayerController(EntityManager* entityManager, double& deltaTime) {

	m_gravity = 2.f;
	m_speed = 0.6f;
	m_speedCap = 3.f;
	m_jumpHeight = 5.f;
	m_slowDown = .99f;

	m_srcRect = new Vector2D(0,0);

	m_stat = Stat::LIVING;

	m_entityManager = entityManager;

	int id = m_entityManager->CreateEntity("player", "mob", Vector2D(32, 32));

	m_player = m_entityManager->GetEntity(id);

	m_velocity = new VectorF2D(0,0);
	m_position = new VectorF2D(0, 0);

	m_deltaTime = &deltaTime;

}

PlayerController::~PlayerController() {

}

void PlayerController::Tick() {
	Update();
}
void PlayerController::KeyboardEvent(SDL_Event& event, const Uint8* state) {

	if (event.type == SDL_KEYDOWN) {
		if (state[SDL_SCANCODE_W] || state[SDL_SCANCODE_UP]) {
			m_velocity->y -= m_speed * (*m_deltaTime);
		}

		if (state[SDL_SCANCODE_S] || state[SDL_SCANCODE_DOWN]) {
			m_velocity->y += m_speed * (*m_deltaTime);
		}

		if (state[SDL_SCANCODE_A] || state[SDL_SCANCODE_LEFT]) {
			m_velocity->x -= m_speed * (*m_deltaTime);
		}

		if (state[SDL_SCANCODE_D] || state[SDL_SCANCODE_RIGHT]) {
			m_velocity->x += m_speed * (*m_deltaTime);
		}
	}
}

void PlayerController::Update() {
	m_position->x += m_velocity->x * (*m_deltaTime);
	m_position->y += m_velocity->y * (*m_deltaTime);

	m_player->MoveBody(*m_position);

	m_velocity->x = m_velocity->x * m_slowDown;
	m_velocity->y = m_velocity->y * m_slowDown;

	//std::cout << "deltaTime: " << *m_deltaTime << std::endl;
	
}

