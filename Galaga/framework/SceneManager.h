#pragma once

#include "Scene.h"
#include <stack>

class SceneManager final
{
private:
    std::stack<Scene*> _scenes;
    
    SceneManager();
public:
    ~SceneManager();
    
    static SceneManager* getInstance();
    static void destroy();
    
    Scene* topScene() { return _scenes.top(); }
    
    void replaceScene(Scene* scene);
    void popScene();
    void pushScene(Scene* scene);
    
};

