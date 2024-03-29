#include <iostream>
#include <math.h>
#include <string>
#include <memory>
#include "PtrDetails.h"

void basicPointerAssignment() {
    int val = 20;
    int* ptr = nullptr;
    ptr = &val;
    
    std::cout << "value of val: " << val << std::endl;
    std::cout << "&val: " << &val << std::endl;
    std::cout << "ptr: " << ptr << std::endl;
    std::cout << "*ptr: " << *ptr << std::endl;
}

void initializeBasicPointer() {
    //create int memory on heap
    int* intPtr = new int;
    *intPtr = 10;
    
    std::cout << "intPtr: " << intPtr << std::endl;
    std::cout << "*intPtr: " << *intPtr << std::endl;
    
    //free the memory
    delete intPtr;
}

void trigonometry(double angle, double* _sin, double* _cos) {
    *_sin = sin(angle);
    *_cos = cos(angle);
}

void tryParamsByReference() {
    double angle, _sin, _cos;
    std::cout << "Enter angel: ";
    std::cin >> angle;
    
    //calculate sin cose
    trigonometry(angle, &_sin, &_cos);
    //print sin cos
    std::cout << "Sin: " << _sin << std::endl;
    std::cout << "Cos: " << _cos << std::endl;
}

int* createArray(int n) {
    return new int[n];
}

int* resizeArray(int* array, int size, int expandBy) {
    int* newArray = new int[size + expandBy];
    for (int i = 0; i  < size; i++) {
        newArray[i] = array[i];
    }
    
    //deallocate the old array
    delete []array;
    return newArray;
}

void tryArrayCreateResize() {
    int* array = createArray(3);
    int* newArray = resizeArray(array, 3, 2);
    
    delete []newArray;
}

void addSpaces(const char* &str) {
    char* newStr = new char(sizeof(str) * 2);
    
    char* newStrStart = newStr;
    while (*str != '\0') {
        *newStr = *str;
        newStr++;
        str++;
        *newStr = ' ';
        newStr++;
    }
    
    *newStr = '\0';
    //because pointer param is received as a reference param so we can directly change its
    //value here
    str = newStrStart;
}

void tryStringManipulation() {
    std::string str = "Hello world";
    const char* ptr = str.c_str();
    std::cout << "ptr: " << ptr << std::endl;
    addSpaces(ptr);
    std::cout << ptr << std::endl;
}

void tryUniquePointer() {
    std::unique_ptr<int> ptr1(new int(4));
    std::cout << "*ptr1: " << *ptr1 << std::endl;
    std::cout << "ptr1: " << ptr1.get() << std::endl;
    
    //move the ownership to new ptr2, after this ptr1 should be 0x0 as it no longer has ownership
    std::unique_ptr<int> ptr2 = std::move(ptr1);
    std::cout << "-------after move ownership to ptr2--------" << std::endl;
    std::cout << "after move, ptr1: " << ptr1 << std::endl;
    std::cout << "*ptr2: " << *ptr2 << std::endl;
    std::cout << "ptr2: " << ptr2.get() << std::endl;
}

void trySharedPtr() {
    std::cout << "------shared ptr-------" << std::endl;
    std::shared_ptr<int> ptr1(new int(4));
    
    std::cout << "ptr1: " << ptr1 << std::endl;
    std::cout << "*ptr1: " << *ptr1 << std::endl;
    std::cout << "reference cout: " << ptr1.use_count() << std::endl;
    
    std::cout << "--> Assign to new pointer" << std::endl;
    std::shared_ptr<int> ptr2 = ptr1;
    
    std::cout << "ptr1: " << ptr1 << std::endl;
    std::cout << "*ptr1: " << *ptr1 << std::endl;
    std::cout << "ptr2: " << ptr2 << std::endl;
    std::cout << "*ptr2: " << *ptr2 << std::endl;
    std::cout << "reference cout: " << ptr1.use_count() << std::endl;
    
    std::cout << "------end----------" << std::endl;
}

int main() {
    trySharedPtr();
    return 0;
}
