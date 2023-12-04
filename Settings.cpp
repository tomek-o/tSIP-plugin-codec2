#include "Settings.h"
#include "Utils.h"
#include "codec2/codec2.h"
#include <fstream>
#include <json/json.h>

namespace {

bool settingsRead = false;
	
}

extern uint32_t codec2_mode;

extern "C" int GetSettings(void) {

    std::string path = Utils::GetDllPath();
    path = Utils::ReplaceFileExtension(path, ".cfg");
    if (path == "")
        return 0;

    Json::Value root;   // will contains the root value after parsing.
    Json::Reader reader;

    std::ifstream ifs(path.c_str());
    std::string strConfig((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    ifs.close();

    bool parsingSuccessful = reader.parse( strConfig, root );
    if ( !parsingSuccessful )
        return 0;

    //settings->ring = false;//root.get("ring", settings->ring).asInt();
    
    int tmpMode = root.get("codec2_mode", codec2_mode).asInt();
    if (tmpMode == CODEC2_MODE_3200 || tmpMode == CODEC2_MODE_2400 || tmpMode == CODEC2_MODE_1600 || tmpMode == CODEC2_MODE_1400 ||
		tmpMode == CODEC2_MODE_1300 || tmpMode == CODEC2_MODE_1200 || tmpMode == CODEC2_MODE_700C)
	{
		codec2_mode = tmpMode;
	}

	settingsRead = true;
	
    return 0;
}

extern "C" int SaveSettings(void) {
	if (settingsRead)
	{
		return 0;
	}
	
    Json::Value root;
    Json::StyledWriter writer;

    Json::Value &jE = root["_enums"];
    {
    	Json::Value &jv = jE["codec2_modes"];
    	jv["CODEC2_MODE_3200"] = CODEC2_MODE_3200;
    	jv["CODEC2_MODE_2400"] = CODEC2_MODE_2400;
    	jv["CODEC2_MODE_1600"] = CODEC2_MODE_1600;
    	jv["CODEC2_MODE_1400"] = CODEC2_MODE_1400;
    	jv["CODEC2_MODE_1300"] = CODEC2_MODE_1300;
    	jv["CODEC2_MODE_1200"] = CODEC2_MODE_1200;
    	jv["CODEC2_MODE_700C"] = CODEC2_MODE_700C;    	
    }
    
    root["codec2_mode"] = codec2_mode;

    std::string outputConfig = writer.write( root );

    std::string path = Utils::GetDllPath();
    path = Utils::ReplaceFileExtension(path, ".cfg");
    if (path == "")
        return -1;

    std::ofstream ofs(path.c_str());
    ofs << outputConfig;
    ofs.close();

    return 0;
}
