// An oven temperature model (public-data version)
//
// This program models two ovens that warm up in steps and warn if they
// overheat. Each oven's data is stored in public member variables, and main()
// reads and changes the temperatures directly.
//
// Copyright (c) Donald Dansereau, 2026

//--Includes-------------------------------------------------------------------
#include <iostream>
#include <string>

//---COven---------------------------------------------------------------------
// COven holds an oven's name and current temperature. Both members are public,
// so any code can read or change them directly.
class COven
{
  public:
    std::string mName;       // the oven's label, e.g. "Reflow oven"
    int mTemperatureC;       // current temperature, in tenths of a degree Celsius
};

//---main----------------------------------------------------------------------
// Sets up two ovens, warms each in one-degree steps, checks each for
// overheating, and reports both. Every step reaches into the ovens' data
// directly.
int main()
{
  COven ReflowOven;
  ReflowOven.mName = "Reflow oven";
  ReflowOven.mTemperatureC = 200;           // start at room temperature (20.0 C)

  COven CuringOven;
  CuringOven.mName = "Curing oven";
  CuringOven.mTemperatureC = 200;           // start at room temperature (20.0 C)

  for( int i = 0; i < 5; ++i )
    ReflowOven.mTemperatureC += 10;         // warm up by one degree

  for( int i = 0; i < 8; ++i )
    CuringOven.mTemperatureC += 10;         // warm up by one degree

  if( ReflowOven.mTemperatureC >= 2500 )    // overheating limit is 250.0 C
    std::cout << "Warning: oven is overheating!" << std::endl;

  if( CuringOven.mTemperatureC >= 2500 )    // overheating limit is 250.0 C
    std::cout << "Warning: oven is overheating!" << std::endl;

  std::cout << ReflowOven.mName << " is at "
            << ReflowOven.mTemperatureC / 10.0 << "C" << std::endl;

  std::cout << CuringOven.mName << " is at "
            << CuringOven.mTemperatureC / 10.0 << "C" << std::endl;

  return 0;
}