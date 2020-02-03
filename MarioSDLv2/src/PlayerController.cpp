#include "Global.h"
#include "PlayerController.h"
#include <iostream>

PlayerController::PlayerController(EntityManager* entityManager, double& deltaTime) {

	m_gravity = 2.f;
	m_speed = 0.01f;
	m_speedCap = 1.f;
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

	pressState.UP		= false;
	pressState.DOWN		= false;
	pressState.LEFT		= false;
	pressState.RIGHT	= false;
	pressState.SHIFT	= false;


	if (state[SDL_SCANCODE_W] || state[SDL_SCANCODE_UP]		&& event.type == SDL_KEYDOWN) {
		pressState.UP = true;
	}

	if (state[SDL_SCANCODE_S] || state[SDL_SCANCODE_DOWN]	&& event.type == SDL_KEYDOWN) {
		pressState.DOWN = true;
	}

	if (state[SDL_SCANCODE_A] || state[SDL_SCANCODE_LEFT]	&& event.type == SDL_KEYDOWN) {
		pressState.LEFT = true;
	}

	if (state[SDL_SCANCODE_D] || state[SDL_SCANCODE_RIGHT]	&& event.type == SDL_KEYDOWN) {
		pressState.RIGHT = true;
	}

	if (state[SDL_SCANCODE_LSHIFT] || state[SDL_SCANCODE_RSHIFT]	&& event.type == SDL_KEYDOWN) {
		pressState.SHIFT = true;
	}
}

void PlayerController::Update() {

	if(pressState.UP)		m_velocity->y -= m_speed * (*m_deltaTime) / 10;
	if(pressState.DOWN)		m_velocity->y += m_speed * (*m_deltaTime) / 10;
	if(pressState.LEFT)		m_velocity->x -= m_speed * (*m_deltaTime) / 10;
	if(pressState.RIGHT)	m_velocity->x += m_speed * (*m_deltaTime) / 10;
	if (pressState.SHIFT) { m_speedCap += 0.5f; } else { m_speedCap = 1.f; };
	

	m_position->x += m_velocity->x * (*m_deltaTime);
	m_position->y += m_velocity->y * (*m_deltaTime);

	m_player->MoveBody(*m_position);

	m_velocity->x = m_velocity->x * m_slowDown;
	m_velocity->y = m_velocity->y * m_slowDown;

	if (m_velocity->x > m_speedCap)	m_velocity->x = m_speedCap;
	if (m_velocity->y > m_speedCap)	m_velocity->y = m_speedCap;

	//std::cout << "deltaTime: " << *m_deltaTime << std::endl;
	
}

