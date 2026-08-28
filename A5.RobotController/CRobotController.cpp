// A robot controller that manages a set of subsystems.

//--Includes-------------------------------------------------------------------
#include "CRobotController.h"

//---CRobotController Implementation-------------------------------------------
CRobotController::CRobotController()
  : mNumSubsystems( 0 )
{
}

//---
void CRobotController::AddSubsystem( CSubsystem* aSubsystem )
{
  if( mNumSubsystems < MaxSubsystems )
  {
    mSubsystems[mNumSubsystems] = aSubsystem;
    ++mNumSubsystems;
  }
}

//---
void CRobotController::Update()
{
  for( int i = 0; i < mNumSubsystems; ++i )
  {
    mSubsystems[i]->Update();
  }
}

//---
void CRobotController::Report() const
{
  for( int i = 0; i < mNumSubsystems; ++i )
  {
    mSubsystems[i]->Report();
  }
}
