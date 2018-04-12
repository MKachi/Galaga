#include "Scene.h"
#if _WINDOWS
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif
#include <algorithm>

Scene::Scene()
{
    _objects.reserve(10);
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
    _objects.push_back(object);
}

void Scene::render()
{
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	std::sort(_objects.begin(), _objects.end()
		, [](Node* a, Node* b)-> bool
	{
		return a->getDepth() < b->getDepth();
	});

	for (auto& object : _objects)
	{
		object->render();
	}
}
