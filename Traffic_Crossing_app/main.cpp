#include <iostream>
#include "TrafficCrossingProcedures.h"

using namespace std;

int main()
{
    // ��ͨ�������
    TrafficCrossingProcedures traffic_light;

    // ��ǰ��ͨ�ƺ͵�·
    TrafficLight light = TrafficLight::GREEN;
    TrafficPath path = TrafficPath::LEFT;

    // ���ý�ͨ�ź�
    traffic_light.SetupCurrentState(light, path);

    // ��������
    traffic_light.RunTrafficCrossingProcedures();

    return 0;
}
