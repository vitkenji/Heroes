#include "Goblin.hpp"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			Goblin::Goblin(Math::CoordinateF position) : Enemy(position, Math::CoordinateF(GOBLIN_SIZE_X, GOBLIN_SIZE_Y), goblin)
			{
				swordDistance = 5;
				addAnimations();
			}

			Goblin::~Goblin()
			{

			}

			void Goblin::addAnimations()
			{
				sprite.addNewAnimation(GraphicalElements::idle, GOBLIN_IDLE_PATH, 4, 1.3);
				sprite.addNewAnimation(GraphicalElements::run, GOBLIN_RUN_PATH, 8, 1);
				sprite.addNewAnimation(GraphicalElements::takeHit, GOBLIN_TAKEHIT_PATH, 4, 1.2);
				sprite.addNewAnimation(GraphicalElements::attack, GOBLIN_ATTACK_PATH, 8, 1);
				sprite.addNewAnimation(GraphicalElements::death, GOBLIN_DEATH_PATH, 4, 1.7);
			}

			//maybe in enemy class
			void Goblin::update(const float dt)
			{
				if (isTakingHit == true)
				{
					cooldown += dt;
					if (cooldown >= 10)
					{
						cooldown = 0;
						isTakingHit = false;

					}
				}

				position.y += velocity.y + (acceleration.y * dt * dt) / 2.0f;
				velocity.y += acceleration.y  * dt;

				updateSprite(dt);
			}


		}
	}
}