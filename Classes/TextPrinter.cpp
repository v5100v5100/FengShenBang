#include "TextPrinter.h"



//void TextPrinter::init(TiXmlNode *node)
//{
//	TiXmlElement *element = node->ToElement();
//
//	int intValue;
//	if (element->QueryIntAttribute("anchor", &intValue) == TIXML_SUCCESS)
//	{
//		anchor = intValue;
//	}
//	else
//	{
//		anchor = false;
//	}
//
//	name = element->Attribute("name");
//	icon = element->Attribute("icon");
//	content = element->Attribute("content");
//	contentLeght = 0;
//
//	int length = content.length();
//	int i = 0;
//	while (i < length)
//	{
//		char ch = getContent()[i];
//		//�ص�������
//		//������ASCII������-127~0
//		if (ch > -127 && ch< 0)
//		{
//			//����Ϊʲô+��3��
//			//��Ϊһ������ռ3���ֽ�
//			i += 3;
//		}
//		else
//		{
//			i++;
//		}
//		contentLeght++;
//	}
//}
//��ȡ���ݵ��ܳ���
int TextPrinter::getContentLength()
{
	return contentLeght;
}

//�������賤�ȵ��ַ���
string TextPrinter::getContentByLength(int length)
{
	if (length >= contentLeght)
	{
		return getContent();
	}
	int i = 0;
	int index = 0;
	while (index < length)
	{
		char ch = getContent()[i];
		//��������˵����
		if (ch > -127 && ch < 0)
		{
			i += 3;
		}
		else
		{
			i++;
		}
		index++;
	}
	//��ȡstrng
	string str = content.substr(0, i);
	return str;
}