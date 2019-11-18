
/*

*/
#include<assert.h>
#include"queue.h"
#define QUEUE_SIZE 10

int main()
{
    int result1;
    int result2;
    //char testChar;
    int testNum;
    // *******************************************************************
    // Test1: Retrieve item from an empty queue
    // *******************************************************************
    // Arrange:
    result1 = 42;
    //testChar = 'Z';
    testNum = 42;
    queue_init();
    
    // Act:
    //result1 = queue_get(&testChar);
    result1 = queue_get(&testNum);
      
    // Assert:
    assert(-1 == result1);
    //assert('Z' == testChar);
    assert(42 == testNum);
    
    // *******************************************************************
    // Test2: Successfully retrieve an item from the queue
    // *******************************************************************
    // Arrange:
    result1 = 42;
    result2 = 42;
    //testChar = 'Z';
    testNum = 42;

    queue_init();
    
    // Act:
    result1 = queue_put(30);
    //result2 = queue_get(&testChar);
    result2 = queue_get(&testNum);

    // Assert:
    assert(0 == result1);
    assert(0 == result2);
    //assert('A' == testChar);
    assert(30 == testNum);
    
    
    // *******************************************************************
    // Test3: Fill queue, then get all items.
    // *******************************************************************
    // Arrange:
    //testChar = 'Z';
    testNum  = 42;
    queue_init();
    
    // Act:
    //queue_put('A');
    //queue_put('B');
    //queue_put('C');                                    
    queue_put(30);
    queue_put(31);
    queue_put(32); 
    // Assert:
    assert(0 == queue_get(&testNum));
    assert(30 == testNum);

    assert(0 == queue_get(&testNum));
    assert(31 == testNum);

    assert(0 == queue_get(&testNum));
    assert(32 == testNum);

    
    // *******************************************************************
    // Test4: Fill queue, then put one more item, should fail
    // *******************************************************************
    // Arrange:
    testNum = 42;
    queue_init();
    
    // Act:
    queue_put(30);
    queue_put(31);
    queue_put(32);
    
    // Assert:
    assert(-1 == queue_put(33));

    assert(0 == queue_get(&testNum));
    assert(30 == testNum);

    assert(0 == queue_get(&testNum));
    assert(31 == testNum);

    assert(0 == queue_get(&testNum));
    assert(32 == testNum);


    // ***********************************************************************
    // Test5: Fill queue, retrieve one item, then add item, then retieve all
    // ***********************************************************************
    // Arrange:
    testNum = 42;
    queue_init();
    
    // Act:
    queue_put(30);
    queue_put(31);
    queue_put(32);
    
    // Assert:
    assert(0 == queue_get(&testNum));
    assert(31 == testNum);

    assert(0 == queue_put('D'));

    assert(0 == queue_get(&testNum));
    assert(32 == testNum);

    assert(0 == queue_get(&testNum));
    assert(33 == testNum);

    assert(0 == queue_get(&testNum));
    assert(34 == testNum);

    // ***********************************************************************
    // Test6: Fill queue and retrieve all items twice
    // ***********************************************************************
    // Arrange:
    testNum = 42;
    queue_init();
    
    // Act:
    queue_put(30);
    queue_put(31);
    queue_put(32);
    
    // Assert:
    assert(0 == queue_get(&testNum));
    assert(31 == testNum);

    assert(0 == queue_get(&testNum));
    assert(32 == testNum);

    assert(0 == queue_get(&testNum));
    assert(33 == testNum);

    assert(0 == queue_put(30));
    assert(0 == queue_put(31));
    assert(0 == queue_put(32));
    
    assert(-1 == queue_put(42));

    assert(0 == queue_get(&testNum));
    assert(33 == testNum);
   
    assert(0 == queue_get(&testNum));
    assert(34 == testNum);

    assert(0 == queue_get(&testNum));
    assert(35 == testNum);

    return 0;
}
