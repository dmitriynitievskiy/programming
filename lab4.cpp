/*---------------------------------------------������������ ������ �4-----------------------------------*/
/*������� ������ ������ ��� ������ � ���������� ��������. ��������� ������������ ����� �������� � ��������� 
��������, ���������� �������� ��������� ����� (��������, ���������� ��������� �������� ���������� ��������*/
	#include <iostream>
    #include <algorithm>
    using namespace std;
    
    template<class T>
    class Array
    {
    public:
        Array(size_t size) //�����������
        {
            m_nSize = size;
            m_pArray = new T[m_nSize];
        }
     
        ~Array() //����������
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
        Array<int> int_arr(10); // ������ �� 10 ��������� ���� int 
        Array<string> string_arr(10); // ������ �� 10 ��������� ���� string
     
        //������������� ��������
        for (size_t i = 0; i < int_arr.size(); ++i)
        {
            int_arr[i] = int_arr.size()-1 - i;
            string_arr[i] = 'a' + string_arr.size()-1 - i;
        }
     
    
        cout << int_arr << endl; // ����� �� ����� ������� ���� int
        cout << string_arr << endl; // ����� �� ����� ������� ���� string
     
        // ���������� ���������� �������
        sort(&int_arr, &int_arr + int_arr.size()); //���������� ������� ���� int
        sort(&string_arr, &string_arr + string_arr.size()); //���������� ������� ���� string
        cout << int_arr << endl; // ��������������� ������ ���� int
        cout << string_arr << endl; // ��������������� ������ ���� string
    }
