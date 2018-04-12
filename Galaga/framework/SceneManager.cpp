#include "SceneManager.h"

static SceneManager* _instance = nullptr;

SceneManager::SceneManager()
{   }

SceneManager::~SceneManager()
{   }

SceneManager* SceneManager::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new SceneManager();
    }
    return _instance;
}

void SceneManager::destroy()
{
    SAFE_DELETE(_instance);
}


void SceneManager::replaceScene(Scene* scene)
{
    if (!_scenes.empty())
    {
        _scenes.pop();
    }
    _scenes.push(scene);
    _scenes.top()->init();
}

void SceneManager::popScene()
{
	if (!_scenes.empty())
	{
		_scenes.pop();
	}
}

void SceneManager::pushScene(Scene* scene)
{
	_scenes.push(scene);
	_scenes.top()->init();
}
