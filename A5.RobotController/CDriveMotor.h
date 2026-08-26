// A drive motor subsystem for the robot controller.

#ifndef CDRIVEMOTOR_H
#define CDRIVEMOTOR_H

#include <string>

#include "CSubsystem.h"

//---CDriveMotor---------------------------------------------------------------
// A CDriveMotor models one motor. It gradually changes its current speed to
// match the target speed requested by the rest of the robot.
class CDriveMotor : public CSubsystem
{
  public:
    // Creates a stopped motor with the given label.
    CDriveMotor( const std::string& aName );

    // SetTargetSpeed requests a new speed for the motor.
    void SetTargetSpeed( double aTargetSpeed );

    // Update moves the current speed one step towards the target speed.
    virtual void Update();

    // Report prints the motor's label, current speed, and target speed.
    virtual void Report() const;

  private:
    std::string mName;          // label used when reporting the motor
    double mCurrentSpeed;       // speed currently reached by the motor
    double mTargetSpeed;        // speed requested for the motor
};

#endif
