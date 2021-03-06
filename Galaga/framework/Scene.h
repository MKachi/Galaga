#pragma once

#include "Node.h"
#include "Timer.h"
#include <vector>

class Scene
{
protected:
	std::vector<Node*> _objects;

public:
	Scene();
	virtual ~Scene();

	void addObject(Node* object);
	void render();

	virtual void init() = 0;
	virtual void update(Timer& timer) = 0;

};