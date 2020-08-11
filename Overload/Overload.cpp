#include "pch.h"

using namespace System;

value struct IntVal
{
//private:
    int value;
public:
    IntVal(int v) : value(v) { }
    int getVal() { return value; }
    static operator IntVal(int v)
    {
        return IntVal(v);
    } 
   static IntVal operator+(IntVal lhs, IntVal rhs)
   {
       IntVal result(lhs.value + rhs.value);
       return result;
    }
   static bool operator==(IntVal lhs, IntVal rhs)
   {
       return lhs.value == rhs.value;
   }
   static bool operator!=(IntVal lhs, IntVal rhs)
   {
       return !(lhs == rhs);
   }
   virtual bool Equals(Object^ other) override 
   { 
       IntVal^ obj = dynamic_cast<IntVal^>(other); 
       if (obj == nullptr) 
           return false; 
       
       return value == obj->value; 
   }
   static IntVal operator++(IntVal i)
   {
       i.value++;
       return i;
   }

};

int main(array<System::String ^> ^args)
{
    IntVal one(1);
    IntVal two(2); 
    IntVal three; // will get zero value 

    three = one + two;
    Console::WriteLine("three is {0}", three.value);

    three = one + 2;
    Console::WriteLine("three is {0}", three.value);
    three = 2 + one;
    Console::WriteLine("three is {0}", three.value);

    if (three == 3)
        Console::WriteLine("All is OK");
    else
        Console::WriteLine("Something is very wrong!");

    if (three != 3)
        Console::WriteLine("Something is wrong!");
    else
        Console::WriteLine("Inequality working OK");

    IntVal four(4), anotherFour(4), five(5);

    if (four.Equals(anotherFour))
        Console::WriteLine("All is OK");
    else
        Console::WriteLine("Something is wrong...");

    if (four.Equals(five))
        Console::WriteLine("Something is very wrong!");
    else
        Console::WriteLine("All is OK");

    IntVal first(3);
    IntVal next = ++first; //pre-increment
    Console::WriteLine("pre-inc, next = {0}, first = {1}", next.value, first.value);

    next = first++; //post-increment
    Console::WriteLine("post-inc, next = {0}, first = {1}", next.value, first.value);

    return 0;
}
