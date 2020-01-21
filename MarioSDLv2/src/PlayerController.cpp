#include "PlayerController.h"


PlayerController::PlayerController(EntityManager* entityManager) {

	m_gravity = 2.f;
	m_speed = 1.3f;
	m_speedCap = 3.f;
	m_jumpHeight = 5.f;
	m_slowDown = 1.f;

	m_srcRect = new Vector2D(0,0);

	m_stat = Stat::LIVING;

	m_entityManager = entityManager;

	int id = m_entityManager->CreateEntity("player", "mob", Vector2D(32, 32));

	m_player = m_entityManager->GetEntity(id);

}

PlayerController::~PlayerController() {

}

void PlayerController::Tick() {

}
void PlayerController::KeyDownCatch(SDL_Event& event) {
	switch (event.key.keysym.sym) {
	case SDLK_w:		pressState.UP		= true;		break;
	case SDLK_s:		pressState.DOWN		= true;		break;
	case SDLK_a:		pressState.LEFT		= true;		break;
	case SDLK_d:		pressState.RIGHT	= true;		break;
	case SDLK_SPACE:	pressState.SPACE	= true;		break;
	case SDLK_LSHIFT:	pressState.SHIFT	= true;		break;
	case SDLK_ESCAPE:	pressState.ESC		= true;		break;
	}
}

void PlayerController::KeyUpCatch(SDL_Event& event) {
	switch (event.key.keysym.sym) {
	case SDLK_w:		pressState.UP		= false;	break;
	case SDLK_s:		pressState.DOWN		= false;	break;
	case SDLK_a:		pressState.LEFT		= false;	break;
	case SDLK_d:		pressState.RIGHT	= false;	break;
	case SDLK_SPACE:	pressState.SPACE	= false;	break;
	case SDLK_LSHIFT:	pressState.SHIFT	= false;	break;
	case SDLK_ESCAPE:	pressState.ESC		= false;	break;
	}
}