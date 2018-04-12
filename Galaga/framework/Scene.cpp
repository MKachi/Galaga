#include "Scene.h"
#if _WINDOWS
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

Scene::Scene()
{
}

Scene::~Scene()
{
	for (auto child : _objects)
	{
		SAFE_DELETE(child);
	}
}

void Scene::addObject(Node* object)
{
}

void Scene::render()
{
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);

	for (auto& object : _objects)
	{
		object->render();
	}
}