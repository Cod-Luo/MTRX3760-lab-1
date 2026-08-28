// Integration program for the robot controller.

#include <iostream>

#include "CRobotController.h"
#include "CDriveMotor.h"
#include "CLineDetector.h"

//---Consts---------------------------------------------------------------------
const int NumCycles = 4;

//---main----------------------------------------------------------------------
int main()
{
  CDriveMotor driveMotor( "Drive" );
  CLineDetector lineDetector( "Front" );

  driveMotor.SetTargetSpeed( 0.8 );

  CRobotController controller;

  controller.AddSubsystem( &driveMotor );
  controller.AddSubsystem( &lineDetector );

  for( int i = 0; i < NumCycles; ++i )
  {
    std::cout << "Cycle " << i + 1 << std::endl;

    controller.Update();
    controller.Report();

    std::cout << std::endl;
  }

  return 0;
}
