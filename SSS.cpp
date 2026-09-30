#include <iostream>
using namespace std;
class MyArray
{
public:
    int* data;

    int capacity;

    int size;
    MyArray(int cap) {
        data = new int[cap];
        capacity = cap;
        size = 0;
    };
    void add(int value)
    {
        if (size >= capacity)
        {
            resize();
        }
        data[size] = value;
        size++;
    };
    void resize() {
        int newCapacity = capacity * 2;
        int* newData = new int[newCapacity];
        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    ~MyArray()
    {
        delete[] data;
    }
    int get(int index) {
        return data[index];
    };
};

int main()
{
    cout << "Hello World!" << endl;
    MyArray arr(10);
    arr.add(30);
    cout << arr.get(0);
};
