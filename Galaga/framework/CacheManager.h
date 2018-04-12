#pragma once

#include "Cache.h"
#include <unordered_map>

class CacheManager final
{
private:
	std::unordered_map<string, Cache*> _caches;

	CacheManager();
public:
	~CacheManager();

	void add(Cache* cache);
	bool isHave(const string& key);
	void remove(const string& key);

	static CacheManager* getInstance();
	static void destroy();

};