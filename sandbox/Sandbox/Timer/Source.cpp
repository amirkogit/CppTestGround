// Timer test

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

using Clock = std::chrono::high_resolution_clock;
using Second = std::chrono::duration<double, std::ratio<1>>;

class Timer
{
public:
    explicit Timer(): m_begin(Clock::now()){}

    void Reset()
    {
        m_begin = Clock::now();
    }

    double Elapsed() const
    {
        return std::chrono::duration_cast<Second>
                (Clock::now() - m_begin).count();
    }

private:
    std::chrono::time_point<Clock> m_begin;
};


int main()
{
    Timer timer;
    cout << "Waiting...\n";

    std::this_thread::sleep_for(2s);

    double elapsed = timer.Elapsed();
    
    cout.precision(1);
    std::cout << fixed << elapsed << " seconds" << std::endl;

    timer.Reset();
    cout << "Waiting...\n";
    std::this_thread::sleep_for(3s);

    elapsed = timer.Elapsed();
    std::cout << fixed << elapsed << " seconds" << std::endl;

    cout << "Done.\n";

    getchar();
    return 0;
}