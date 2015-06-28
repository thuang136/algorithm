#include <iostream>
#include <functional>
using namespace std;

class CAdd
{
public:
    CAdd() : m_nSum(0) {}


    int operator() (int i)
    {
        m_nSum += i;

        return m_nSum;
    }

    int Sum() const
    {
        return m_nSum;
    }

private:

    int m_nSum;




};


int main()
{
    CAdd add;

    std::function<int(int)> f1 = add;

    std::function<int(int)> f2 = add;

    cout << f1(10) << "," << f2(10) << "," << add.Sum() << endl;

    return 0;


}
