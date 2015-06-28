#include<iostream>
using namespace std;

class MovingAverage
{
public:
    virtual float getAverage() = 0;
    virtual void addSample(float val) = 0;
};

class SimpleMovingAverage : public MovingAverage
{

public:
    SimpleMovingAverage(int size);
    virtual ~SimpleMovingAverage();
    float getAverage();
    void addSample(float val);

private:
    float* m_samples;
    float m_total;
    int m_nextLoadPos;
    int m_Size;
    bool isFullLoad;

};

SimpleMovingAverage :: SimpleMovingAverage(int size)
{
    m_samples = new float[size];
    m_Size = size;
    m_total = 0.0f;
    m_nextLoadPos = 0;
    isFullLoad = false;

}

SimpleMovingAverage :: ~SimpleMovingAverage()
{
    delete [] m_samples;
}

float SimpleMovingAverage :: getAverage()
{
    int count = m_Size;
    if(!isFullLoad)
    {
        count = m_nextLoadPos;
    }
    return m_total / count;
}

void SimpleMovingAverage :: addSample(float val)
{
    if(!isFullLoad)
    {
        m_samples[m_nextLoadPos] = val;
        m_total += val;
        m_nextLoadPos++;
        if(m_nextLoadPos == m_Size)
        {
            isFullLoad = true;
            m_nextLoadPos = 0;
        }
    }
    else
    {
        m_total -= m_samples[m_nextLoadPos];
        m_total += val;
        m_samples[m_nextLoadPos] = val;
        m_nextLoadPos =( m_nextLoadPos + 1) % m_Size;
    }
}


int main(int argc, char** argv)
{

    MovingAverage* pAverage = new SimpleMovingAverage(5);

    for(int i = 1; i < 8; i++)
    {
        pAverage->addSample(i);
        cout << pAverage->getAverage() << endl;
    }

}



