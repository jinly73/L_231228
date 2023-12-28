// Fill out your copyright notice in the Description page of Project Settings.


#include "BBAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


void UBBAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds); // 부모함수 불러오기 이거 꼭 해줘야함

	ACharacter* MyCharacter = Cast<ACharacter>(TryGetPawnOwner());
	if (IsValid(MyCharacter))
	{
		Speed = MyCharacter->GetCharacterMovement()->Velocity.Size2D();
	}
}
