// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FastXml.h"
#include "SimpleXMLParsedData.h"

DECLARE_LOG_CATEGORY_EXTERN(SimpleXMLParser, Log, All);

class SimpleXMLParserImpl : public IFastXmlCallback
{
public:
	SimpleXMLParserImpl(TArray<FSimpleXMLParsedData>& outDataArray)
		: outDataArray(outDataArray)
		, addingArrayIdx(-1)
	{};

	void Parse(FString contents);

	//IFastXmlCallback
	bool ProcessXmlDeclaration(const TCHAR* ElementData, int32 XmlFileLineNumber);
	bool ProcessElement(const TCHAR* ElementName, const TCHAR* ElementData, int32 XmlFileLineNumber);
	bool ProcessAttribute(const TCHAR* AttributeName, const TCHAR* AttributeValue);
	bool ProcessClose(const TCHAR* Element);
	bool ProcessComment(const TCHAR* Comment);

private:
	TArray<FSimpleXMLParsedData>& outDataArray;
	int32 addingArrayIdx;
};
