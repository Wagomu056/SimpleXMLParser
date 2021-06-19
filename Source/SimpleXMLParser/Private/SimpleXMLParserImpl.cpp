// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleXMLParserImpl.h"

DEFINE_LOG_CATEGORY(SimpleXMLParser);

void SimpleXMLParserImpl::Parse(FString contents)
{
	FText errorMessage;
	int32 errorLineNumber;
	if (!FFastXml::ParseXmlFile(this, TEXT(""), contents.GetCharArray().GetData(), nullptr, false, false, errorMessage, errorLineNumber))
	{
		UE_LOG(SimpleXMLParser, Error, TEXT("[XML] ParseXML Error. [%s:%d]"), *errorMessage.ToString(), errorLineNumber);
	}
}

bool SimpleXMLParserImpl::ProcessXmlDeclaration(const TCHAR* ElementData, int32 XmlFileLineNumber)
{
	return true;
}

bool SimpleXMLParserImpl::ProcessElement(const TCHAR* ElementName, const TCHAR* ElementData, int32 XmlFileLineNumber)
{
	++addingArrayIdx;

	FSimpleXMLParsedData data;
	data.key = ElementName;
	data.text = ElementData;
	outDataArray.Add(data);

	return true;
}

bool SimpleXMLParserImpl::ProcessAttribute(const TCHAR* AttributeName, const TCHAR* AttributeValue)
{
	FSimpleXMLParsedData& addingData = outDataArray[addingArrayIdx];
	addingData.attribute.Add(AttributeName, AttributeValue);

	return true;
}

bool SimpleXMLParserImpl::ProcessClose(const TCHAR* Element)
{
	return true;
}

bool SimpleXMLParserImpl::ProcessComment(const TCHAR* Comment)
{
	return true;
}

