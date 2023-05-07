#ifndef STOP_WATCH_H
#define STOP_WATCH_H
#include<chrono>
#include<vector>
class stop_watch//结束主线程
{
public:
    stop_watch():m_start_time()
    {}
    ~stop_watch()
    {}
    void start()
    {
        m_start_time=std::chrono::high_resolution_clock::now();
    }
    void stop()
    {
        const auto end_time=std::chrono::high_resolution_clock::now();
    }
    void restart()
    {
        start();
    }
    void reset()
    {

    }
    double elapsed()
    {
        const auto end_time = std::chrono::high_resolution_clock::now();
        const auto duration = end_time - m_start_time;
        return std::chrono::duration_cast<std::chrono::duration<double, std::ratio<1, 1000>>>(duration).count();
    }
private:
    typedef std::chrono::time_point<std::chrono::high_resolution_clock> time_pt;
    time_pt m_start_time;
};
#endif // STOP_WATCH_H
