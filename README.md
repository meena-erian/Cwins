Cwins
===
Cwins is a general purpose C++ library for adding exta functionalities by providing most commonly needed and commonly used functions, operators, datatypes and macro definitions. It consist of many separate header files, each will be described in detailes below.
+ License: [GNU GPL v3](LICENSE)
+ Created: 2016
+ Author: Meena Erian H
+ Version:

---
---
##StringFormating.h
**Required Libraries:** \<sstream.h\>
**Cross-Platform:** Yes
###Description:
StringFormating.h overloads operators of the standard std::string class for performing common tasks.
###Example
```C++
#include "StringFormaing.h"
int main()
{
  std::string s = "abc012";
  s = ++(2>>s<<3) + "++ flexibility = " + 10 +"1" + (3>>s<<1)*7;
}
```
The final value of **s** is gooing to be "C++ flexibility = 101010101010101"
see [StringFormating.cpp](StringFormating.cpp) for more detailes about what you can do with [StringFormating.h](https://raw.githubusercontent.com/meena-hanna/Cwins/master/StringFormating.h).
