#pragma once

#include "OpenGL.h"
#include "Rule.h"

enum KeyCode
    : uint
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
    
    Input();
    
public:
    ~Input();
    static void init();
    
    static void keyFunc(KeyCode key);
    static void keyUpFunc(KeyCode key);
    
    static bool isKeyState(KeyCode key) { return _keys[key]; }
    
};
