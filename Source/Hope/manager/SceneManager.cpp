#include "Hope.h"
#include "SceneManager.h"

SceneManager::SceneManager(){

}
SceneManager::~SceneManager(){

}
SceneManager* SceneManager::GetInstance(){
    static SceneManager s_instance;
    return &s_instance;
}

void SceneManager::Destroy(){

}
void SceneManager::Tick(float dt){


}


void SceneManager::ChangeScene(EScene eScene){


}