#ifndef __TEXT_PRINTER__
#define __TEXT_PRINTER__

#include "tinyxml2/tinyxml2.h"  
#include "cocos2d.h"
using namespace std;
USING_NS_CC;

class TextPrinter
{
public:
	bool anchor;
	string icon;
	string name;
	string content;
	
	//void init(TiXmlNode *node);

	bool getAnchor()
	{
		return anchor;
	};

	const char* getIcon()
	{
		return icon.c_str();
	};

	const char* getName()
	{
		return name.c_str();
	};

	const char* getContent()
	{
		return content.c_str();
	};

	string getContentByLength(int length);

	int contentLeght;
	
	int getContentLength();
};

#endif