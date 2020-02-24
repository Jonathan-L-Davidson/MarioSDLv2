#pragma once
#include "Global.h"
#include "Textures.h"

class Entity {
	public:

		enum EntityType {
			MOB,
			PICKUP,
			STATIC
		};

		Entity(std::string name, std::string type, Vector2D size, int id);
		~Entity();

		void Update();
			   		
		SDL_Rect GetBody() const { return *(m_body); };
		void MoveBody(VectorF2D& vector);
		void MoveBody(Vector2D& vector);

		SDL_Rect GetSrcRect() const { return *(m_srcRect); };
		void SetTexture(Texture* texture);
		SDL_Texture* GetTexture() const { return m_texture->GetTexture(); };
		int GetID() const { return m_id; };
	private:
		Texture* m_texture;
		std::string* m_name;	// Name of the entity. Useful for logging.
		int m_id;				// ID of the entity to find the index.
		EntityType m_type;		// Type of entity used for behaviour logic.
		Vector2D* m_size;		// Size of the entity.
		SDL_Rect* m_body;		// Used for position & size.
		SDL_Rect* m_srcRect;	// Used to select parts of the sprite sheet.
		
		void virtual Process();
};