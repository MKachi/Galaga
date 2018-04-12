#include "Cache.h"
#include "CacheManager.h"

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
		CacheManager::getInstance()->remove(_key);
		delete this;
	}
}