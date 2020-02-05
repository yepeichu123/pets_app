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
    // ��ʱ����
    void DelayTime(double seconds);

    // 1����
    void DisplayTraffic1();

    // 2����
    void DisplayTraffic2();

    // 3����
    void DisplayTraffic3();

    // 4����
    void DisplayTraffic4();

    // ��ǰ��ͨ���ź�
    TrafficLight curr_light_;

    // ��ǰ�̵Ƴ���
    TrafficPath curr_path_;

};
#endif // TRAFFIC_CROSSING_PROCEDURES_H
