#include<iostream>
#include<cstring>
#include<cstdio>
#include<functional>
using namespace std;

class MyString
{
public:


    MyString(const char* str = NULL)
    {
        if(str == NULL)
        {
            m_strArr = new char[1];
            *m_strArr = '\0';
        }
        else
        {
            int size = strlen(str);
            m_strArr = new char[size+1];
            strcpy(m_strArr,str);
        }
    }


    MyString(const MyString& other)
    {
        int size = strlen(other.m_strArr);
        m_strArr = new char[size+1];
        strcpy(m_strArr,other.m_strArr);

    }


    operator char* ()
    {
        return m_strArr;
    }

    MyString& operator= (const MyString& other)
    {
        if(this == &other)
        {
            return *this;
        }

        delete [] m_strArr;

        int len = strlen(other.m_strArr);

        m_strArr = new char[len+1];

        strcpy(m_strArr,other.m_strArr);

        return *this;
    }

    void print()
    {
        cout << m_strArr << endl;
    }

    
private:
    char* m_strArr;
};


class CAdd
{
public:
    CAdd() : m_nSum(0) {}

    int operator()(int i)
    {
        m_nSum += i;
        return m_nSum;
    }

    int Sum() const
    {
        return m_nSum;
    }
    
private:
    int m_nSum ;
};



int main(int argc, char** argv)
{
    MyString myStr("OK");

    char* pCh = myStr;

    pCh[0] = 'K';

    myStr.print();

    CAdd add;

    function<int(int)> f1 = add;

    function<int(int)> f2 = add;

    cout << f1(10) << endl;
    cout << f2(10) << endl;
    cout << add.Sum() << endl;
}

