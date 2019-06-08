#include <iostream>

void initializeBasicPointer() {
    //create int memory on heap
    int* intPtr = new int;
    *intPtr = 10;
    
    std::cout << "intPtr: " << intPtr << std::endl;
    std::cout << "*intPtr: " << *intPtr << std::endl;
    
    //free the memory
    delete intPtr;
}

int main() {
    int val = 20;
    int* ptr = nullptr;
    ptr = &val;
    
    std::cout << "value of val: " << val << std::endl;
    std::cout << "&val: " << &val << std::endl;
    std::cout << "ptr: " << ptr << std::endl;
    std::cout << "*ptr: " << *ptr << std::endl;
    
    initializeBasicPointer();
    return 0;
}
