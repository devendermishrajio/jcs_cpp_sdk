/*****************************************************************************
* Copyright (c) 2016 Jiocloud.com, Inc. or its affiliates.  All Rights Reserved
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish, dis-
* tribute, sublicense, and/or sell copies of the Software, and to permit
* persons to whom the Software is furnished to do so, subject to the fol-
* lowing conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABIL-
* ITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
* SHALL THE AUTHOR BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
******************************************************************************/
#include "model/describe_key_pairs_response.hpp"
#include "XMLParser.h"
#include <iostream>
#include <string>
#include <vector>


#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;
using namespace model;

model::describe_key_pairs_response::describe_key_pairs_response(const string &xml_doc)
{
	XMLDocument doc;
	doc.Parse(xml_doc.c_str());
	//Root
	XMLNode *RootNode = doc.FirstChild();
	XMLElement *Element = RootNode->FirstChildElement("requestId");
	if(Element!=NULL)
	{
		request_id = Element->GetText();
		Element=Element->NextSiblingElement();
	}
	else cout<<"Error Parsing request_id from XML describe_key_pairs_response\n";

	XMLElement *ListElement = Element->FirstChildElement("item");
	XMLElement *KeyPairElement;
	string keyname,keyfingerprint;
	while(ListElement != NULL)
	{	
		KeyPairElement = ListElement->FirstChildElement("keyName");
		if(KeyPairElement!=NULL)
		{
			if(KeyPairElement->GetText()!=NULL) keyname=KeyPairElement->GetText();
			KeyPairElement=KeyPairElement->NextSiblingElement();
		}
		else cout<<"Error Parsing keyname from XML describe_key_pairs_response\n";
		if(KeyPairElement!=NULL)
			{if(KeyPairElement->GetText()!=NULL)keyfingerprint=KeyPairElement->GetText();}
		else
			cout<<"Error Parsing keyfingerprint from XML describe_key_pairs_response\n";
		
		model::key_pair key(keyname,keyfingerprint);
		key_pairs.push_back(key);
		ListElement=ListElement->NextSiblingElement();
	}

}
