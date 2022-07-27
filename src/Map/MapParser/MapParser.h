#ifndef __MAP_PARSER_H__
#define __MAP_PARSER_H__

#include <map>
#include "../GameMap/GameMap.h"
#include "../../thirdparty/TinyXML2/tinyxml2.h"

using namespace tinyxml2;

class MapParser
{
private:
    MapParser();
    static MapParser *s_Instance;

    std::map<const char *, GameMap *> m_DictMaps;

public:
    bool loadMap(const char *p_MapID, const char *p_Source);
    void parse(const char *p_MapID);
    static MapParser *GetInstance() { return s_Instance = (s_Instance == nullptr) ? new MapParser() : s_Instance; }
};
#endif // __MAP_PARSER_H__