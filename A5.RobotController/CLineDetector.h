// A line detector subsystem for the robot controller.

#ifndef CLINEDETECTOR_H
#define CLINEDETECTOR_H

#include <string>

#include "CSubsystem.h"

//---CLineDetector-------------------------------------------------------------
// A CLineDetector reads a simulated line position. Each update takes the next
// reading from its track, allowing its reported state to change every cycle.
class CLineDetector : public CSubsystem
{
  public:
    // Creates a detector at the first reading on its track.
    CLineDetector( const std::string& aName );

    // GetLineOffset returns the latest distance from the centre of the line.
    int GetLineOffset() const;

    // Update takes the next reading from the detector's track.
    virtual void Update();

    // Report prints the detector's label and latest line offset.
    virtual void Report() const;

  private:
    std::string mName;          // label used when reporting the detector
    int mCycle;                 // index of the next reading to take
    int mLineOffset;            // latest detected offset from the line
};

#endif
