// Fill out your copyright notice in the Description page of Project Settings.

#include "Hope.h"
#include "HopePaperCharacter.h"
#include "PaperFlipbookComponent.h"

AHopePaperCharacter::AHopePaperCharacter(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)

{
   // this->bShowMouseCursor = true;
   // this->bEnableClickEvents = true;
   // this->bEnableMouseOverEvents = true;
    /*RunningAnimation = ConstructorStatics.RunningAnimationAsset.Get();
    IdleAnimation = ConstructorStatics.IdleAnimationAsset.Get();
    GetSprite()->SetFlipbook(IdleAnimation);*/
   // this->BeginPlay();
}



void AHopePaperCharacter::BeginPlay(){

}

//////////////////////////////////////////////////////////////////////////
// Animation

void AHopePaperCharacter::UpdateAnimation()
{
    /*const FVector PlayerVelocity = GetVelocity();
    const float PlayerSpeed = PlayerVelocity.Size();

    // Are we moving or standing still?
    UPaperFlipbook* DesiredAnimation = (PlayerSpeed > 0.0f) ? RunningAnimation : IdleAnimation;

    GetSprite()->SetFlipbook(DesiredAnimation);*/
}

//////////////////////////////////////////////////////////////////////////
// Input

void AHopePaperCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
    // Note: the 'Jump' action and the 'MoveRight' axis are bound to actual keys/buttons/sticks in DefaultInput.ini (editable from Project Settings..Input)
   /* InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
    InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
    InputComponent->BindAxis("MoveRight", this, &ATP_2DSideScrollerCharacter::MoveRight);

    InputComponent->BindTouch(IE_Pressed, this, &ATP_2DSideScrollerCharacter::TouchStarted);
    InputComponent->BindTouch(IE_Released, this, &ATP_2DSideScrollerCharacter::TouchStopped);*/
   // InputComponent->BindAxis();
  
}



void AHopePaperCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{

}

void AHopePaperCharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
  
}
