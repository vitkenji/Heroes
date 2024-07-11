#pragma once
#include "MovingEntity.hpp"

namespace Entities
{
	namespace Characters
	{
		class Character : public MovingEntity
		{
		protected:
			int life;
			int damage;
			bool isTakingHit;
			bool isWalking;
			bool isAttacking;
			float swordDistance;

		public:
			Character(Math::CoordinateF position, Math::CoordinateF size, ID id);
			~Character();

			float getSwordDistance();

			void setIsAttacking(bool isAttacking);
			bool getIsAttacking();

			void restartSprite(const float dt, float animationTime);
			virtual void update(const float dt) = 0;
			virtual void collide(Entity* other, Math::CoordinateF intersection) = 0;
			
		};
	}
}