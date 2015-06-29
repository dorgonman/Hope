// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PaperCharacter.h"
#include "HopePaperCharacter.generated.h"

/**
 * 
 */
UCLASS()
class HOPE_API AHopePaperCharacter : public APaperCharacter
{
	GENERATED_BODY()
public:
    AHopePaperCharacter(const FObjectInitializer& ObjectInitializer);


    virtual void BeginPlay() override;
protected:
    // The animation to play while running around
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
    class UPaperFlipbook* RunningAnimation;

    // The animation to play while idle (standing still)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
    class UPaperFlipbook* IdleAnimation;

    /** Called to choose the correct animation to play based on the character's movement state */
    void UpdateAnimation();


    /** Handle touch inputs. */
    void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

    /** Handle touch stop event. */
    void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

    // APawn interface
    virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
    // End of APawn interface

	
	
	
};
