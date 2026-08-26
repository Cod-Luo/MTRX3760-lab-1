// A subsystem that can run one robot cycle and report its current state.

#ifndef CSUBSYSTEM_H
#define CSUBSYSTEM_H

//---CSubsystem----------------------------------------------------------------
// CSubsystem is the common interface used by the robot controller. Different
// kinds of robot hardware inherit from it so the controller can operate every
// subsystem without knowing its concrete type.
class CSubsystem
{
  public:
    // Cleans up a subsystem through a base-class pointer.
    virtual ~CSubsystem();

    // Update runs one cycle of this subsystem.
    virtual void Update() = 0;

    // Report prints this subsystem's current state.
    virtual void Report() const = 0;
};

#endif
