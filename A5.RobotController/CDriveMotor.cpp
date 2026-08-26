// A drive motor subsystem for the robot controller.

//--Includes-------------------------------------------------------------------
#include <iostream>

#include "CDriveMotor.h"

//--Consts---------------------------------------------------------------------
const double SpeedStep = 0.2;   // maximum speed change in one cycle

//---CDriveMotor Implementation-----------------------------------------------
CDriveMotor::CDriveMotor( const std::string& aName )
  : mName( aName ),
    mCurrentSpeed( 0.0 ),
    mTargetSpeed( 0.0 )
{
}
//---
void CDriveMotor::SetTargetSpeed( double aTargetSpeed )
{
  mTargetSpeed = aTargetSpeed;
}
//---
void CDriveMotor::Update()
{
  if( mCurrentSpeed < mTargetSpeed )
  {
    mCurrentSpeed += SpeedStep;

    if( mCurrentSpeed > mTargetSpeed )
    {
      mCurrentSpeed = mTargetSpeed;
    }
  }
  else if( mCurrentSpeed > mTargetSpeed )
  {
    mCurrentSpeed -= SpeedStep;

    if( mCurrentSpeed < mTargetSpeed )
    {
      mCurrentSpeed = mTargetSpeed;
    }
  }
}
//---
void CDriveMotor::Report() const
{
  std::cout << mName << " motor: current " << mCurrentSpeed
            << ", target " << mTargetSpeed << std::endl;
}
