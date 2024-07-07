// Fill out your copyright notice in the Description page of Project Settings.


#include "EditFunctionLibrary.h"
#include "Global/DataTable/GlobalObjectRow.h"
#include "DesktopPlatformModule.h"
#include "IDesktopPlatform.h"
#include "Engine/StreamableManager.h"


void UEditFunctionLibrary::DataTableTest(UDataTable* _DataTable)
{
	IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();

	if (nullptr == DesktopPlatform)
	{
		UE_LOG(LogType, Fatal,TEXT("if (nullptr == DesktopPlatform) Error"));
		return;
	}

	FString DefaultPath;
	FString Result;
	bool bOpen = false;

	bOpen = DesktopPlatform->OpenDirectoryDialog(
		NULL,
		TEXT("Select Directory"),
		DefaultPath,
		Result
	);

	TArray<FString> FileList;

	Result += TEXT("/*.*");

	IFileManager::Get().FindFiles(FileList, *Result, true, false);

	if (nullptr == _DataTable)
	{
		return;
	}

	//for (size_t i = 0; i < FileList.Num(); i++)
	//{
	//	FGlobalObjectRow NewData = FGlobalObjectRow();

	//	FString Path = TEXT("Blueprint'/Game/BluePrint/FPSShoot/");

	//	FString FileName = FileList[i];

	//	FileName = FileName.Replace(TEXT(".uasset"), TEXT(""));
	//	
	//	Path += FileName + "." + FileName + "_C";

	//	TSubclassOf<UObject> MyActorClass = LoadClass<UObject>(nullptr, *Path);

	//	NewData.Object = MyActorClass;

	//	_DataTable->AddRow(*FileName, NewData);
	//}

	//_DataTable->Modify();
}