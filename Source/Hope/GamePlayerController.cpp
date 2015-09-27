// Fill out your copyright notice in the Description page of Project Settings.

#include "Hope.h"
#include "GamePlayerController.h"
#include "camera/MainCameraActor.h"


#include "manager/SceneManager.h"
#include "Engine/LocalPlayer.h"
#include "Engine/GameInstance.h"
#include "MovieScene.h"
#include "scene/TitleScene.h"
#include "UMG.h"

//#include "HorizonCore.h"


/*
#include "StateMachineContext.h"

namespace boost
{

#ifdef BOOST_NO_EXCEPTIONS

    void throw_exception(std::exception const & e){
        throw e;
    }; // user defined

#endif

}


namespace horizon{
    //list of event
    namespace events{
        class GameStartEvent{};
        class GameExitToTitleViewEvent{};
    }

    class UGUIView : public boost::msm::front::state < > {
    public:
        UGUIView(){

        }
        // empty implementation for the states not wishing to define an entry condition
        // will not be called polymorphic way
        template <class Event, class FSM>
        void on_entry(Event const& e, FSM &fsm){
            OnEnter();
        }

        template <class Event, class FSM>
        void on_exit(Event const& e, FSM& fsm){
            OnExit();
        }

    protected:
        virtual void OnEnter() = 0;
        virtual void OnExit() = 0;
    };

    // The list of FSM states
    class UTitleView : public UGUIView{
    public:
        UTitleView(){

        }
        virtual void OnEnter() override{
            std::cout << "entering: UTitleView" << std::endl;
        }


        virtual void OnExit() override{
            std::cout << "OnExit: UTitleView" << std::endl;
        }
    };

    class UHomeView : public UGUIView{
    public:
        UHomeView(){

        }

        virtual void OnEnter() override{
            std::cout << "entering: UHomeView" << std::endl;
        }


        virtual void OnExit() override{
            std::cout << "OnExit: UHomeView" << std::endl;
        }

    };



    class UGUIViewFSM : public boost::msm::front::state_machine_def < UGUIViewFSM > {
    private:


    public:
        template <class TFSMContext>
        UGUIViewFSM(TFSMContext &m){
        };
        // the initial state of the SM. Must be defined
        typedef UTitleView initial_state;
        struct transition_table : boost::mpl::vector<
            //   Start            Event                     Next
            _row<UTitleView, events::GameStartEvent, UHomeView>,
            _row<UHomeView, events::GameExitToTitleViewEvent, UTitleView>
        >{};


    };

}

void start(){
    horizon::StateMachineContext<horizon::UGUIViewFSM> sm;

    sm.start();
    sm.processEvent(horizon::events::GameStartEvent());
    sm.processEvent(horizon::events::GameExitToTitleViewEvent());
    sm.stop();
}*/


//#include <boost/system/config.hpp>
AGamePlayerController::AGamePlayerController(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , MainCameraActor(nullptr)
{
    this->bShowMouseCursor = true;
    this->bEnableClickEvents = true;
    this->bEnableMouseOverEvents = true;
    //UGameplayStatics::GetPlayerController
    //GetWorld()->AddController(this);
   // boost::asio::io_service io_service;
    //io_service.run();
    //horizon::HTest t1;

    //start();

}

AGamePlayerController::~AGamePlayerController(){
    
}



void AGamePlayerController::PrintAllObjectsNamesAndClasses()
{
   /* for (TObjectIterator<UObject> Itr; Itr; ++Itr)
    {
        auto name = Itr->GetName();
        auto desc = Itr->GetClass()->GetDesc();

        //UE_LOG(LogHope, Log, TEXT("test:%s"), name.);
        //UE_LOG(LogHope, Log, TEXT("test:%s"), Itr->GetClass()->GetDesc());
        ClientMessage(Itr->GetName());
        ClientMessage(Itr->GetClass()->GetDesc());
    }*/


    for (TActorIterator<AMainCameraActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
    {
        UE_LOG(LogHope, Log, TEXT("GetName:%s"), *ActorItr->GetName());
        UE_LOG(LogHope, Log, TEXT("GetDesc:%s"), *ActorItr->GetClass()->GetDesc());
       // UE_LOG(LogHope, Log, TEXT("GetActorLabel:%s"), *ActorItr->GetActorLabel());
        UE_LOG(LogHope, Log, TEXT("GetFName:%s"), *ActorItr->GetClass()->GetFName().GetPlainNameString());

        ClientMessage(ActorItr->GetName());
        ClientMessage(ActorItr->GetActorLocation().ToString());
    }
}



void AGamePlayerController::BeginPlay(){
    Super::BeginPlay();
    //PrintAllObjectsNamesAndClasses();

    for (TActorIterator<ACameraActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
    {
        auto objectName = ActorItr->GetName();
        auto classDesc = ActorItr->GetClass()->GetDesc();
        UE_LOG(LogHope, Log, TEXT("GetName:%s"), *objectName);
        //UE_LOG(LogHope, Log, TEXT("classDesc:%s"), *classDesc);
        //UE_LOG(LogHope, Log, TEXT("GetActorLabel:%s"), *ActorItr->GetActorLabel());
        //UE_LOG(LogHope, Log, TEXT("GetFName:%s"), *ActorItr->GetClass()->GetFName().GetPlainNameString());

        if (FString("MainCamera") == objectName){
            this->MainCameraActor = *ActorItr;
            break;
        }
    }
    ensureMsg(nullptr != MainCameraActor , TEXT("MainCamera can't find"));
    //check((nullptr != MainCameraActor) && "Did you forget to call Init()?");
    //SetViewTarget(this->MainCameraActor);
    USceneManager::Destroy();
    USceneManager::GetInstance()->SetGameController(this);
    //TitleScene* pTitleScene = NewObject<TitleScene>();
    USceneManager::GetInstance()->ChangeScene<UTitleScene>();


    //IHorizonCoreModule* horizonCoreModule = FModuleManager::LoadModulePtr<IHorizonCoreModule>("HorizonCore");
    //if (horizonCoreModule != NULL)
    {
      //  horizonCoreModule->DumpModuleInfo();
    }

   // this->MainCameraActor-> = ECameraProjectionMode::Orthographic;
    
}


void AGamePlayerController::Tick(float DeltaSeconds){

    if (IsInputKeyDown(EKeys::A)){
       
    }else if (IsInputKeyDown(EKeys::LeftMouseButton) || 
             IsInputKeyDown(EKeys::TouchKeys[1])){
        //UE_LOG(LogHope, Log, TEXT("EKeys::LeftMouseButton || EKeys::TouchKeys[1]"));
       // ClientMessage("EKeys::LeftMouseButton");
    }else if (IsInputKeyDown(EKeys::MouseY)){

    }
    //GEngine->GetWorld();
    USceneManager::GetInstance()->Tick(DeltaSeconds);


}

