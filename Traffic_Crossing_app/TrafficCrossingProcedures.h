#ifndef TRAFFIC_CROSSING_PROCEDURES_H
#define TRAFFIC_CROSSING_PROCEDURES_H

enum TrafficLight {
    GREEN = 1,
    YELLOW = 2,
    RED = 3
};

enum TrafficPath {
    LEFT = 1,
    UP = 2,
    RIGHT = 3,
    DOWN = 4
};

class TrafficCrossingProcedures {

public:
    TrafficCrossingProcedures();

    ~TrafficCrossingProcedures();

    void SetupCurrentState(const TrafficLight& light, const TrafficPath& path);

    void RunTrafficCrossingProcedures();

    void DisplayTrafficPath(const TrafficPath& path);

private:
    // 延时程序
    void DelayTime(double seconds);

    // 1车道
    void DisplayTraffic1();

    // 2车道
    void DisplayTraffic2();

    // 3车道
    void DisplayTraffic3();

    // 4车道
    void DisplayTraffic4();

    // 当前交通灯信号
    TrafficLight curr_light_;

    // 当前绿灯车道
    TrafficPath curr_path_;

};
#endif // TRAFFIC_CROSSING_PROCEDURES_H
