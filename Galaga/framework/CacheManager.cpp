#include "CacheManager.h"

static CacheManager* _instance = nullptr;

CacheManager::CacheManager()
{	}

CacheManager::~CacheManager()
{	}

bool CacheManager::isHave(const string& key)
{
	return _caches.find(key) != _caches.cend();
}

void CacheManager::add(Cache* cache)
{
	if (!isHave(cache->getKey()))
	{
		_caches.emplace(std::make_pair(cache->getKey(), cache));
	}
}

void CacheManager::remove(const string& key)
{
	auto target = _caches.find(key);
	if (target != _caches.end())
	{
		_caches.erase(target);
	}
}

CacheManager* CacheManager::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new CacheManager();
	}
	return _instance;
}

void CacheManager::destroy()
{
	SAFE_DELETE(_instance);
}