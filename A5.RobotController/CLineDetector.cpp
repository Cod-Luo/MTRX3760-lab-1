// A line detector subsystem for the robot controller.

//--Includes-------------------------------------------------------------------
#include <iostream>

#include "CLineDetector.h"

//--Consts---------------------------------------------------------------------
const int NumReadings = 4;      // number of simulated line readings

//---CLineDetector Implementation---------------------------------------------
CLineDetector::CLineDetector( const std::string& aName )
  : mName( aName ),
    mCycle( 0 ),
    mLineOffset( 0 )
{
}
//---
int CLineDetector::GetLineOffset() const
{
  return mLineOffset;
}
//---
void CLineDetector::Update()
{
  const int Track[NumReadings] = { 2, 1, -1, -2 };

  mLineOffset = Track[mCycle];
  ++mCycle;

  if( mCycle == NumReadings )
  {
    mCycle = 0;
  }
}
//---
void CLineDetector::Report() const
{
  std::cout << mName << " line offset: " << mLineOffset << std::endl;
}
