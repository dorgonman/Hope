// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "manager/SceneManager.h"
DECLARE_LOG_CATEGORY_EXTERN(LogHope, Log, All);

#define SAFE_DELETE(p) if(p){ delete p;} p = nullptr;