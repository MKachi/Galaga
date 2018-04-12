#pragma once

#include "Rule.h"
#include "Vector2.h"
#include <vector>

class Node
{
	using Children = std::vector<Node*>;
protected:
	string		_tag;
	bool		_active;
	int			_depth;
	Vector2		_position;
	float		_rotate;
	Vector2		_scale;

	Node*		_parent;
	Children	_children;

public:
	Node();
	virtual ~Node();

	void setTag(const string& tag);
	string getTag() { return _tag; }

	void setActive(bool active);
	bool isActive() const { return _active; }

	void setDepth(int depth);
	int getDepth() const { return _depth; }

	void setPosition(const Vector2& position);
	Vector2 getPosition() { return _position; }

	void setRotate(float rotate);
	float getRotate() { return _rotate; }

	void setScale(const Vector2& scale);
	Vector2 getScale() { return _scale; }

	void removeParent();
	void setParent(Node* parent);
	Node* getParent() { return _parent; }

	void addChild(Node* child);
	void removeChild(Node* child);
	void removeChildByTag(const string& tag);
	Node* getChildByTag(const string& tag);
	Children getChildren() { return _children; }

	virtual void render() = 0;

};