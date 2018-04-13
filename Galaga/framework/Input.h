#pragma once

#include "OpenGL.h"
#include "Rule.h"

enum KeyCode
    : int
{
    Up = 0,
    Down,
    Left,
    Right,
    Space,
    KEY_COUNT
};

class Input final
{
private:
    static bool _keys[KEY_COUNT];
    
public:
    Input();
    ~Input();
    
    static void init();
    
    static void keyFunc(KeyCode key);
    static void keyUpFunc(KeyCode key);
    
    static bool isKeyState(KeyCode key) { return _keys[key]; }
    
};
