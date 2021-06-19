// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleXMLParserFunctionLibrary.h"
#include "SimpleXMLParserImpl.h"

void USimpleXMLParserFunctionLibrary::ParseXML(FString contents, TArray<FSimpleXMLParsedData>& parsedDataArray)
{
	SimpleXMLParserImpl impl(parsedDataArray);
	impl.Parse(contents);
}
