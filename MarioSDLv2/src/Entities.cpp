#include "Global.h"
#include "Entities.h"
#include <iostream>

Entity::Entity(std::string name, std::string type, Vector2D size, int id) {
	m_name = new std::string(name);
	m_id = id;
	
	if (type == "mob") {
		m_type = MOB;
	}
	else if (type == "pickup") {
		m_type = PICKUP;
	}
	else if (type == "static") {
		m_type = STATIC;
	}
	else {
		std::cout << "Entity: Cannot identify type: " << type << std::endl;
		m_type = MOB;
	}

	m_size = new Vector2D(size.x, size.y);

	m_body = new SDL_Rect;
	m_body->x = 0;	m_body->y = 0;	m_body->w = m_size->x * sizeOffset;	m_body->h = m_size->y * sizeOffset;

	m_srcRect = new SDL_Rect;
	m_srcRect->x = 0;	m_srcRect->y = 0;	m_srcRect->w = m_size->x;	m_srcRect->h = m_size->y;

}

Entity::~Entity() {

}

void Entity::Update() {
	Process();
}

void Entity::MoveBody(Vector2D& vector) {
	if(vector.x)	m_body->x = vector.x;
	if(vector.y)	m_body->y = vector.y;
}

void Entity::SetTexture(Texture* texture) {
	m_texture = texture;
}

void Entity::Process() {
	//std::cout << "Entity Process()\n";
	return;
}
