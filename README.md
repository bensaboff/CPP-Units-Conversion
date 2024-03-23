Generic units library
=====================

C++ units library with defined operators.

Inter-dimensional operations should be written the same way as any other operation.

Usage
------------

```c++
Units::Speed GetUpdatedSpeed(Units::Time FrameTime, Units::Distance NewPosition)
{
   static Units::Distance oldPosition(Units::Distance::zero());

   Units::Speed ret = ((NewPosition - oldPosition) / FrameTime);
   oldPosition = NewPosition;

   return ret;
}

Units::MetersPerSecond newSpeed;

newSpeed = GetUpdatedSpeed(Units::Seconds(5), Units::Meters(10));
//newSpeed is now Units::MetersPerSecond(2)

newSpeed = GetUpdatedSpeed(Units::Hours(1), Units::Kilometers(10)+Units::Meters(10));
//newSpeed is now Units::MetersPerSecond((10.0*1000.0)/3600.0)
```

Values can be initialized using user literals
```c++
{
   using namespace Units::Literals;

   Units::Mass mass_value = 3.4_st;
}
```
