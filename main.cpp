#include <iostream>
#include <math.h>

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

int main() {
    tryParamsByReference();
    return 0;
}
