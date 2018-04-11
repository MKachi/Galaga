#include "Cache.h"

Cache::Cache()
	: _ref(1)
{	}

Cache::~Cache()
{	}

void Cache::retain()
{
	++_ref;
}

void Cache::release()
{
	--_ref;
	if (_ref < 1)
	{
		delete this;
	}
}