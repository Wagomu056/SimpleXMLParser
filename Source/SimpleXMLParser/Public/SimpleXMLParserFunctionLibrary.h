// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SimpleXMLParserFunctionLibrary.generated.h"

/**
 * 
 */
struct FSimpleXMLParsedData;

UCLASS()
class SIMPLEXMLPARSER_API USimpleXMLParserFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "SimpleXMLParser")
	static void ParseXML(FString contents, TArray<FSimpleXMLParsedData>& parsedDataArray);
};
