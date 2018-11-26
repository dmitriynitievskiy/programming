/*---------------------------------------------Ћабораторна€ работа є4-----------------------------------*/
/*—оздать шаблон класса дл€ работы с одномерным массивом. ¬ыполнить тестирование путем создани€ и обработки 
массивов, содержащих элементы различных типов (например, сортировка элементов массивов различными методами*/
	#include <iostream>
    #include <algorithm>
    using namespace std;
    
    template<class T>
    class Array
    {
    public:
        Array(size_t size) // онструктор
        {
            m_nSize = size;
            m_pArray = new T[m_nSize];
        }
     
        ~Array() //ƒеструктор
        {
            delete [] m_pArray;
        }
     
        T operator [](size_t offset) const
        {
            return m_pArray[offset];
        }
     
        T& operator [](size_t offset)
        {
            return m_pArray[offset];
        }
     
        T* operator &()
        {
            return m_pArray;
        }
     
        size_t size() const
        {
            return m_nSize;
        }
     
    private:
        T* m_pArray;
        size_t m_nSize;
    };
     
    template<class T>
    ostream& operator << (ostream& stream, const Array<T>& obj)
    {
        size_t ssize = 0;
        while (ssize < obj.size())
        {
            stream << obj[ssize++] << ' ';
        }
        return stream;
    }
     
    int main()
    {
        Array<int> int_arr(10); // массив из 10 элементов типа int 
        Array<string> string_arr(10); // массив из 10 элементов типа string
     
        //инициализаци€ массивов
        for (size_t i = 0; i < int_arr.size(); ++i)
        {
            int_arr[i] = int_arr.size()-1 - i;
            string_arr[i] = 'a' + string_arr.size()-1 - i;
        }
     
    
        cout << int_arr << endl; // вывод на экран массива типа int
        cout << string_arr << endl; // вывод на экран массива типа string
     
        // выполнение сортировки массива
        sort(&int_arr, &int_arr + int_arr.size()); //сортировка массива типа int
        sort(&string_arr, &string_arr + string_arr.size()); //сортировка массива типа string
        cout << int_arr << endl; // отсортированный массив типа int
        cout << string_arr << endl; // отсортированный массив типа string
    }
