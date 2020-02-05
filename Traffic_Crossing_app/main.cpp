#include <iostream>
#include "TrafficCrossingProcedures.h"

using namespace std;

int main()
{
    // 交通处理程序
    TrafficCrossingProcedures traffic_light;

    // 当前交通灯和道路
    TrafficLight light = TrafficLight::GREEN;
    TrafficPath path = TrafficPath::LEFT;

    // 设置交通信号
    traffic_light.SetupCurrentState(light, path);

    // 启动程序
    traffic_light.RunTrafficCrossingProcedures();

    return 0;
}
