// A robot controller that manages a set of subsystems.

#ifndef CROBOTCONTROLLER_H
#define CROBOTCONTROLLER_H

#include "CSubsystem.h"

//---Consts---------------------------------------------------------------------
const int MaxSubsystems = 10;

//---CRobotController-----------------------------------------------------------
// CRobotController stores robot subsystems and runs each one every cycle.
class CRobotController
{
  public:
    // Creates an empty robot controller.
    CRobotController();

    // AddSubsystem adds a subsystem to the controller.
    void AddSubsystem( CSubsystem* aSubsystem );

    // Update runs one cycle of every subsystem.
    void Update();

    // Report prints the state of every subsystem.
    void Report() const;

  private:
    CSubsystem* mSubsystems[MaxSubsystems];
    int mNumSubsystems;
};

#endif
