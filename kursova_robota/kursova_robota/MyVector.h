#include <list>

/*
    ������� ������
    ������ 23
    ����� - �������� ���������
*/

using namespace std;

template <typename T> class MyVector
{
private:

    // ������ �� ������ ������ ������ �������
    T* arr;

    // ��������� �����
    int capacity;

    // ������� ��������
    int size;

public:
    // �����������
    MyVector() {
        arr = new T[10]; 
        capacity = 10; // ���������� �����
        size = 0;
    }
    ~MyVector() {
        delete[] arr;
    }

    // ���� ������� �� ������� � ���� �����
    void add(T data) {

        // ���� ������� �������� ������� ������,�������� ������
        if (size == capacity) {
            T* temp = new T[2 * capacity];

            // ������� ������ ������ �� ������ ����������
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }

            // ��������� ������
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }

        // ������ ������� �� �������� �������
        arr[size] = data;
        size++;
    }

    // ������ �� �������� �� ���� ��������
    T get(int index) {
        if (index < size)
            return arr[index];
    }
    // ������� �� ������� ������� �� ���� ��������
    void remove_by_index(int index) {
        T* temp = new T[capacity]; // ��������� ����� ������
        for (int i = 0; i < size; i++) {
            if (i == index) { 
                break;
            }
            else {
                temp[i] = arr[i];
            }
        }
        for (int i = index; i < size - 1; i++) { // ���������� �������� ������ ��� ��������� ��������
            temp[i] = arr[i + 1];
        }
        delete[] arr;
        arr = temp;
        size--;
    }
    // ��������� �� ��������� 
    bool remove(T data) {
        if (isHere(data)) { // �������� �� ���������� ��������
            int pos = index(data); // ���������� ���� ������
            remove_by_index(pos); // ������ ������ ��������� �� ��������
            return true;
        }
        else {
            return false;
        }
    }
    // ����� ������ ��������
    int index(T data) {
        for (int i = 0; i < size; i++) {
            if (data == arr[i]) {
                return i;
            }
        }
        return -1;
    }
    // �������� �� ���������� �������� � ������
    bool isHere(T data) {
        for (int i = 0; i < size; i++) {
            if (data == arr[i]) {
                return true;
            }
        }
        return false;
    }
    
    // ���� ������ �� ������� (true - � ����������,false - � �����������)
    void add_list(list <T> &data, bool boolean)
    {
        if (data.size() >= capacity - size) {
            T* temp = new T[2 * capacity];
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        if (boolean) {
            for (T x : data) {
                arr[size] = x;
                size++;
            }
        }
        else {
            int n = data.size();
            for (int i = 0;i < n;i++) {
                arr[size] = data.back();
                data.pop_back();
                size++;
            }
        
        }

    }

    int capacityOfVector() { return capacity; }

    void pop() { size--; }

    // ����� �� ������� ������� �������� �������

    int sizeOfVector() { return size; }

    // ����������� ������� �� �����
    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    // ����������� ������� �� ����� (�������� �������)
    void print_reverse() {
        for (int i = size - 1; i > -1; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    // ������� �������
    void inverse() {
        T* reverse = new T[size];
        int j = 0;
        for (int i = size - 1; i > -1; i--) {
            reverse[j] = arr[i];
            j++;
        }
        delete[] arr;
        arr = reverse;

    }
    // ���������� ������� (���� �������� true,�� ���������� ���������� �� �������� �� �������, � ������ ������� - �������)
    void sort(bool b) {
        if (b) {
            for (int startIndex = 0; startIndex < size - 1; ++startIndex)
            {
                
                int smallestIndex = startIndex;

    
                for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
                {
            
                    if (arr[currentIndex] < arr[smallestIndex])
                    
                        smallestIndex = currentIndex;
                }

                std::swap(arr[startIndex], arr[smallestIndex]);
            }
        }
        else {
            for (int startIndex = 0; startIndex < size - 1; ++startIndex)
            {

                int biggestIndex = startIndex;


                for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
                {

                    if (arr[currentIndex] > arr[biggestIndex])

                        biggestIndex = currentIndex;
                }

                std::swap(arr[startIndex], arr[biggestIndex]);
            }
        }
    }
    
};