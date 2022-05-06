#include <list>

/*
    Курсова робота
    Варіант 23
    автор - Громовий Костянтин
*/

using namespace std;

template <typename T> class MyVector
{
private:

    // массив що зберігає адресу нашого вектора
    T* arr;

    // загальний розмір
    int capacity;

    // кількість елементів
    int size;

public:
    // конструктор
    MyVector() {
        arr = new T[10]; 
        capacity = 10; // початковий розмір
        size = 0;
    }
    ~MyVector() {
        delete[] arr;
    }

    // додає елемент до вектора в його кінець
    void add(T data) {

        // якщо кількість елементів дорівнює розміру,збільшуємо массив
        if (size == capacity) {
            T* temp = new T[2 * capacity];

            // копіюємо старий массив до нового збільшеного
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }

            // видаляємо старий
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }

        // додаємо елемент на свободну позицію
        arr[size] = data;
        size++;
    }

    // доступ до елемента за його індексом
    T get(int index) {
        if (index < size)
            return arr[index];
    }
    // функція що видаляє елемент за його індексом
    void remove_by_index(int index) {
        T* temp = new T[capacity]; // створюємо новий массив
        for (int i = 0; i < size; i++) {
            if (i == index) { 
                break;
            }
            else {
                temp[i] = arr[i];
            }
        }
        for (int i = index; i < size - 1; i++) { // продовжуємо копіювати просто без потрібного елемента
            temp[i] = arr[i + 1];
        }
        delete[] arr;
        arr = temp;
        size--;
    }
    // видалення за значенням 
    bool remove(T data) {
        if (isHere(data)) { // перевірка на присутність елемента
            int pos = index(data); // присвоюємо йому індекс
            remove_by_index(pos); // виклик методу видалення за індексом
            return true;
        }
        else {
            return false;
        }
    }
    // пошук індекс елемента
    int index(T data) {
        for (int i = 0; i < size; i++) {
            if (data == arr[i]) {
                return i;
            }
        }
        return -1;
    }
    // перевірка на присутність елемента в массиві
    bool isHere(T data) {
        for (int i = 0; i < size; i++) {
            if (data == arr[i]) {
                return true;
            }
        }
        return false;
    }
    
    // додає список до вектора (true - в звичайному,false - в зворотньому)
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

    // метод що повертає кількість елементів вектора

    int sizeOfVector() { return size; }

    // відображення вектора на екран
    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    // відображення вектора на екран (зворотній порядок)
    void print_reverse() {
        for (int i = size - 1; i > -1; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    // інверсія вектора
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
    // сортування вектора (якщо значення true,то сортування відбувається від меньшого до більшого, в іншому випадку - навпаки)
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