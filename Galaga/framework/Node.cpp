#include "Node.h"

Node::Node()
	: _tag("")
	, _active(true)
	, _depth(0)
	, _position(Vector2::zero)
	, _rotate(0.0f)
	, _scale(Vector2::one)
	, _parent(nullptr)
{	}

Node::~Node()
{	}

void Node::setTag(const string& tag)
{	}

void Node::setActive(bool active)
{	
	_active = active;
}

void Node::setDepth(int depth)
{	
	_depth = depth;
}

void Node::setPosition(const Vector2& position)
{
	_position = position;
}

void Node::setRotate(float rotate)
{
	_rotate = rotate;
}

void Node::setScale(const Vector2& scale)
{
	_scale = scale;
}

void Node::removeParent()
{
	_parent->removeChild(this);
	_parent = nullptr;
}

void Node::setParent(Node* parent)
{
	_parent = parent;
}

void Node::removeChild(Node* child)
{
	_children.erase(std::find(_children.begin(), _children.end(), child));
}

void Node::removeChildByTag(const string& tag)
{
	Node* target = nullptr;
	for (auto& child : _children)
	{
		if (child->getTag() == tag)
		{
			target = child;
		}
	}
	_children.erase(std::find(_children.begin(), _children.end(), target));
}

Node* Node::getChildByTag(const string& tag)
{
	for (auto& child : _children)
	{
		if (child->getTag() == tag)
		{
			return child;
		}
	}
}