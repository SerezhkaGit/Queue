#include <iostream>
#include <cstring>
using namespace std;

template<class T>
class Queue
{
private:
    T* data;
    int size;
public:
    Queue() : T{ nullptr }, size{0} {}
    Queue( const char* text) 
    {
        size = strlen(text);
        data = new char[size + 1];

        for (int i = 0; i < size; i++)
        {
            data[i] = text[i];
        }
    }

    Queue(Queue& ex)
    {
        T* tmp = new T[ex.size];
        for (int i = 0; i < ex.size; i++)
        {
            tmp[i] = ex.data[i];
        }
        size = ex.size;
        data = tmp;
    }

    friend ostream& operator<<(ostream& out, const Queue& ex)
    {
        for (int i = 0; i < ex.size; i++)
        {
            out << ex.data[i];
        }
        return out;
    }

    void push_back(const char* text)
    {
        int new_size = size + strlen(text);
        T* tmp = new T[new_size + 1]; 
        int m = 0;
        for (int i = 0; i < new_size; i++)
        {
            if (i < size)
            {
                tmp[i] = data[i];
            }
            else
            {
                tmp[i] = text[m];
                m++;
            }
        }

        data = tmp;
        size = new_size;

    }

    void pop_back()
    {
        int new_size = size - 1;
        T* tmp = new T[new_size + 1];
        for (int i = 0; i < new_size; i++)
        {
            tmp[i] = data[i];
        }
        data = tmp;
        size = new_size;
    }

    ~Queue()
    {
        clear();
    }

    bool Is_Empty()
    {
        if (size == 0)
        {
            return true;
        }
        else { return false; }
    }

    bool Is_Full()
    {
        if (!Is_Empty())
        {
            return true;
        }
        else { return false; }
    }

    void clear()
    {
        delete[] data;
        size = 0;
    }
};

int main()
{
    Queue<char> l("Sergiy"); 
    l.push_back(" Kuziv");
    l.pop_back();
    cout << l << endl;
    cout << l.Is_Empty() << endl;
    cout << l.Is_Full() << endl;

   

    return 0;
}
