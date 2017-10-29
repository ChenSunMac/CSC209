#include <stdlib.h>
#include <stdio.h>
/* Wild pointer, Null Pointer, Void Pointer, Dangling Pointer and Function Pointer
 *  - Wilder Pointer : A pointer which has not been initialized to anything (not even NULL) is known as wild pointer.
 *  - NULL Pointer :  A pointer which is pointing to nothing.
 *  - Void Pointer : A specific pointer type – void *
 * 					 a pointer that points to some data location in storage, which doesn’t have any specific type. 
 *  - Dangling Pointer : A pointer pointing to a memory location that has been deleted (or freed) 
 *  - Function Pointer : address of the function code entry
 */

// void fun(int a)
// {
//     printf("Value of a is %d\n", a);
// }

int main()
{
    int *wild_p;  /* wild pointer */
 
    int x = 10;
 	printf("The value of ptr is %u \n", wild_p);
 	// Uncomment the following to eliminate the warnings
    // p is not a wild pointer now
    //wild_p = &x;

    // Null Pointer
    //int *null_ptr = NULL;
     
    //printf("The value of ptr is %u \n", null_ptr);

    // Null Pointer stores a defined value (NULL pointer is a value)
    // An uninitialized pointer stores an undefined value.

    //float y = 5.5;
	//A void pointer
    //void *void_ptr;
    //void_ptr = &x;
    //printf("Integer variable is = %d\n", *( (int*) void_ptr) );
    //void_ptr = &y; 
    //printf("Float variable is= %f\n", *( (float*) void_ptr) );
 
    //int *dangling_ptr = (int *)malloc(sizeof(int));
 
    // After below free call, ptr becomes a 
    // dangling pointer
    //free(dangling_ptr); 
    
    //printf("The value in dangling Pointer = %d\n", *( (int*) dangling_ptr) );
    // No more a dangling pointer
    // dangling_ptr = NULL;

    // fun_ptr is a pointer to function fun() 
    //void (*fun_ptr)(int) = &fun;
 
    /* The above line is equivalent of following two
       void (*fun_ptr)(int);
       fun_ptr = &fun; 
    */
 
    // Invoking fun() using fun_ptr
    //(*fun_ptr)(10);

    // Function name can be used to get functions’ address
    //void (*fun_ptr)(int) = fun;  // & removed
 
    //fun_ptr(10);  // * removed

    return 0;
}


