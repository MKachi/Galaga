#include "Resources.h"
#include "../framework/Texture.h"

Resources::Resources()
	: _manager(CacheManager::getInstance())
{	}

Resources::~Resources()
{	}

bool Resources::load()
{
	#pragma region Player
	Texture* player = new (std::nothrow) Texture(ResPlayer);
	if (player == nullptr)
	{
		return false;
	}
	player->glListBegin();
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
		{
			glVertex3f(0.0f, 10.0f, 0.0f);
			glVertex3f(48.0f, 10.0f, 0.0f);
			glVertex3f(48.0f, 12.0f, 0.0f);
			glVertex3f(0.0f, 12.0f, 0.0f);

			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(5.0f, 0.0f, 0.0f);
			glVertex3f(5.0f, 40.0f, 0.0f);
			glVertex3f(0.0f, 40.0f, 0.0f);

			glVertex3f(20.0f, 0.0f, 0.0f);
			glVertex3f(28.0f, 0.0f, 0.0f);
			glVertex3f(28.0f, 40.0f, 0.0f);
			glVertex3f(20.0f, 40.0f, 0.0f);

			glVertex3f(43.0f, 0.0f, 0.0f);
			glVertex3f(48.0f, 0.0f, 0.0f);
			glVertex3f(48.0f, 40.0f, 0.0f);
			glVertex3f(43.0f, 40.0f, 0.0f);

			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(20.0f, 40.0f, 0.0f);
			glVertex3f(28.0f, 40.0f, 0.0f);
			glVertex3f(28.0f, 55.0f, 0.0f);
			glVertex3f(20.0f, 55.0f, 0.0f);
		}
		glEnd();
	}
	player->glListEnd();
	_manager->add(player);
	#pragma endregion

	#pragma region Enemy
	Texture* snatcher = new (std::nothrow) Texture(ResEnemy);
	if (snatcher == nullptr)
	{
		return false;
	}
	snatcher->glListBegin();
	{
		glBegin(GL_QUADS);
		{
			glVertex3f(0.0f, 15.0f, 0.0f);
			glVertex3f(30.0f, 15.0f, 0.0f);
			glVertex3f(30.0f, 35.0f, 0.0f);
			glVertex3f(0.0f, 35.0f, 0.0f);

			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(5.0f, 0.0f, 0.0f);
			glVertex3f(5.0f, 15.0f, 0.0f);
			glVertex3f(0.0f, 15.0f, 0.0f);

			glVertex3f(25.0f, 0.0f, 0.0f);
			glVertex3f(30.0f, 0.0f, 0.0f);
			glVertex3f(30.0f, 15.0f, 0.0f);
			glVertex3f(25.0f, 15.0f, 0.0f);
		}
		glEnd();
	}
	snatcher->glListEnd();
	_manager->add(snatcher);
	#pragma endregion

	#pragma region Bullet
	Texture* bullet = new (std::nothrow) Texture(ResBullet);
	if (bullet == nullptr)
	{
		return false;
	}
	bullet->glListBegin();
	{
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
		{
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(3.0f, 0.0f, 0.0f);
			glVertex3f(3.0f, 20.0f, 0.0f);
			glVertex3f(0.0f, 20.0f, 0.0f);
		}
		glEnd();
	}
	bullet->glListEnd();
	_manager->add(bullet);
	#pragma endregion

	return true;
}