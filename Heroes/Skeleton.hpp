#pragma once
#include "Enemy.hpp"
#include "Player.hpp"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			class Skeleton : public Enemy
			{
			private:
				Player* pPlayer;

			public:
				Skeleton(Math::CoordinateF position);
				~Skeleton();
				void addAnimations();
				void update(const float dt);
				void updateSprite(const float dt);
			};
		}
	}
}