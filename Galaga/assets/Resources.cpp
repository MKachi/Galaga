#include "Resources.h"
#include "../framework/Texture.h"

Resources::Resources()
	: _manager(CacheManager::getInstance())
{	}

Resources::~Resources()
{	}

bool Resources::load()
{
	Texture* player = new (std::nothrow) Texture("Player");
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

	return true;
}