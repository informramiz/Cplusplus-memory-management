template <typename T>
class PtrDetails {
public:
    unsigned referenceCount; //reference count of this object
    T* memPtr; //pointer to the allocated memory
    bool isArray; //true if memPtr points to an array
    unsigned arraySize; //size of of the array
    
    PtrDetails(T* ptr, unsigned size = 0);
};

template <typename T>
PtrDetails<T>::PtrDetails(T* ptr, unsigned size)  {
    memPtr = ptr;
    arraySize = size;
    isArray = arraySize > 0;
    referenceCount = 1;
}

template <typename T>
bool operator==(const PtrDetails<T> &obj1, const PtrDetails<T> &obj2) {
    return obj1.memPtr == obj2.memPtr;
}
