/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(float v, const char* charName) : value(v), name(charName) { }   //1
    float value = 0.0f; //2
    std::string name = "init name"; //3
};

struct MyStruct1                                //4
{
    T* compare(T* a, T* b) //5
    {
        if(a != nullptr && b != nullptr)
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        
        std::cout << "a and/or b wasn't properly initialized or were equal" << std::endl;
        return nullptr;
    }
};

struct U
{
    float myFloat1 { 6.f }, myFloat2 { 3.f };
    float myMemberFunction(float& myUpdatedValue)      //12
    {
        std::cout << "U's myFloat1 value: " << myFloat1 << std::endl;
        
            myFloat1 = myUpdatedValue;
            std::cout << "U's myFloat1 updated value: " << myFloat1 << std::endl;

            while( std::abs(myFloat2 - myFloat1) > 0.001f )
            {
                 /*
                  write something that makes the distance between that->myFloat2 and that->myFloat1 get smaller
                 */
                 myFloat2 += .05f;
            }
            
            std::cout << "U's myFloat2 updated value: " << myFloat2 << std::endl;
            return myFloat2 * myFloat1;
    }
};

struct MyStruct2
{
    static float myStaticFunctionA(U& that, float& myUpdatedValue )        //10
    {
            std::cout << "U's myFloat1 value: " << that.myFloat1 << std::endl;
            that.myFloat1 = myUpdatedValue;
            std::cout << "U's myFloat1 updated value: " << that.myFloat1 << std::endl;
            while( std::abs(that.myFloat2 - that.myFloat1) > 0.001f )
            {
                /*
                 write something that makes the distance between that->myFloat2 and that->myFloat1 get smaller
                 */
                that.myFloat2 += .05f;
            }
            
            std::cout << "U's myFloat2 updated value: " << that.myFloat2 << std::endl;
            return that.myFloat2 * that.myFloat1;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.
 send me a DM to review your pull request when the project is ready for review.
 Wait for my code review.
 */

int main()
{
    T myT1( 5.0f, "a");                                             //6
    T myT2( 5.0f, "b");                                             //6
    
    MyStruct1 f;                                                      //7

    auto* smaller = f.compare(&myT1, &myT2);                              //8
    if(smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }
    else
    {
        std::cout << "smaller compare values were equal" << std::endl;
    }
    
    U myU1;
    float updatedValue = 5.f;
    std::cout << "myStaticFunctionA myU1's multiplied values: " << MyStruct2::myStaticFunctionA( myU1, updatedValue) << std::endl;                  //11
    
    U myU2;
    std::cout << "myMemberFunction myU2's multiplied values: " << myU2.myMemberFunction( updatedValue ) << std::endl;
}
