#include "Input.h"

Input::Input()
{   }

Input::~Input()
{   }

void Input::init()
{
    for (int i = 0; i < KEY_COUNT; ++i)
    {
        _keys[i] = false;
    }
}

void Input::keyFunc(KeyCode key)
{
    _keys[key] = true;
}

void Input::keyUpFunc(KeyCode key)
{
    _keys[key] = false;
}
