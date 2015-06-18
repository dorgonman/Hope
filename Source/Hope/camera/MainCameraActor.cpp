// Fill out your copyright notice in the Description page of Project Settings.

#include "Hope.h"
#include "MainCameraActor.h"




AMainCameraActor::AMainCameraActor(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{

    //FixedViewTarget
    // PlayerControllerClass = AGamePlayerController::StaticClass();
    //RootComponent = CameraBoom;
    GetCameraComponent()->ProjectionMode = ECameraProjectionMode::Orthographic;
    GetCameraComponent()->OrthoWidth = 2048.0f;
    GetCameraComponent()->bUsePawnControlRotation = false;
   // GetCameraComponent()->Deactivate();

    /*auto test0 = GetCameraComponent();
    // Create a camera boom attached to the root (capsule)
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    RootComponent = CameraBoom;
   // CameraBoom->AttachTo(RootComponent);
    CameraBoom->TargetArmLength = 1500.0f;
    CameraBoom->SocketOffset = FVector(0.0f, 0.0f, 75.0f);
    CameraBoom->bAbsoluteRotation = true;
    CameraBoom->RelativeRotation = FRotator(0.0f, -90.0f, 0.0f);

    auto test = GetCameraComponent();*/

    // Create an orthographic camera (no perspective) and attach it to the boom
    /*OrthoViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("OrthoViewCamera"));
    OrthoViewCameraComponent->ProjectionMode = ECameraProjectionMode::Orthographic;
    OrthoViewCameraComponent->OrthoWidth = 2048.0f;
    OrthoViewCameraComponent->AttachTo(CameraBoom, USpringArmComponent::SocketName);
    */
    //CameraComponent = OrthoViewCameraComponent;
    

}
