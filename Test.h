template <typename T>
class Test {
private:
    int value;
public:
    Test(T value);
    T getValue();
};

template<typename T>
Test<T>::Test(T value) {
    this->value = value;
}

template<typename T>
T Test<T>::getValue() {
    return value;
}
