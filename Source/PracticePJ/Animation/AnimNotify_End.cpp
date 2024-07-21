// Fill out your copyright notice in the Description page of Project Settings.

#include "Animation/AnimNotify_End.h"
#include "Global/Animation/GlobalAnimInstance.h"

UAnimNotify_End::UAnimNotify_End()
{
#if WITH_EDITOR
	bShouldFireInEditor = false;
#endif
}

void UAnimNotify_End::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	//UGlobalAnimInstance* AnimInst = Cast<UGlobalAnimInstance>(MeshComp->GetAnimInstance());

	//if (nullptr != AnimInst)
	//{
	//	AnimInst->ChangeAnimation(NextAnimationName);
	//}
}