#pragma once

#define CREATE_SCENE(_SCENE_) \
public: \
void init() override; \
void update(Timer& timer) override

#define CREATE_OBJECT(_OBJECT_) \
protected: \
_OBJECT_(){} \
public: \
virtual ~_OBJECT_(){} \
static _OBJECT_* create() \
{ \
	_OBJECT_* result = new(std::nothrow) _OBJECT_(); \
	if (result != nullptr) \
	{ \
		return result; \
	} \
	return nullptr; \
} \
void render() override

#define GLUT_ASCII_SPACE 32

template <typename T>
inline void SAFE_DELETE(T*& obj)
{
	if (obj != nullptr)
	{
		delete obj;
		obj = nullptr;
	}
}

template <typename T>
inline void SAFE_DELETE_ARRAY(T*& obj)
{
	if (obj != nullptr)
	{
		delete[] obj;
		obj = nullptr;
	}
}
