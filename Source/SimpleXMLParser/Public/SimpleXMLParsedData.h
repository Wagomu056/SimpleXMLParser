// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SimpleXMLParsedData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FSimpleXMLParsedData
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SimpleXMLParsedData")
	FName key;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SimpleXMLParsedData")
	FString text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SimpleXMLParsedData")
	TMap<FName, FString> attribute;
};
