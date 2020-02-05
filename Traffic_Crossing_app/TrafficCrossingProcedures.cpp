
#include "TrafficCrossingProcedures.h"
#include <iostream>
#include <ctime>

using namespace std;

// Ĭ�Ϲ��캯��
TrafficCrossingProcedures::TrafficCrossingProcedures() {
    curr_light_ = TrafficLight::GREEN;
    curr_path_ = TrafficPath::LEFT;
}

// Ĭ����������
TrafficCrossingProcedures::~TrafficCrossingProcedures() {

}

void TrafficCrossingProcedures::SetupCurrentState(const TrafficLight& light, const TrafficPath& path) {
    curr_light_ = light;
    curr_path_ = path;
}

void TrafficCrossingProcedures::RunTrafficCrossingProcedures() {
    cout << "����ʮ��·�ڽ�ͨ�źŵƴ������" << endl;
    bool quit = false;
    while (!quit) {
        if (curr_light_ == TrafficLight::GREEN) {
            cout << ">>>>>>>>>>>>>>>>��ǰ�źŵ�Ϊ�̵ƣ�" << endl;
            DisplayTrafficPath(curr_path_);
            DelayTime(5);
            curr_light_ = TrafficLight::YELLOW;
        }
        else if (curr_light_ == TrafficLight::YELLOW) {
            cout << ">>>>>>>>>>>>>>>>��ǰ�źŵ�Ϊ�Ƶƣ�" << endl;
            DisplayTrafficPath(curr_path_);
            DelayTime(3);
            curr_light_ = TrafficLight::RED;
        }
        else {
            cout << ">>>>>>>>>>>>>>>>��ǰ�źŵ�Ϊ��ƣ�" << endl;
            DelayTime(2);
            curr_light_ = TrafficLight::GREEN;
            switch (curr_path_) {
            case TrafficPath::LEFT:
                curr_path_ = TrafficPath::UP;
                break;
            case TrafficPath::UP:
                curr_path_ = TrafficPath::RIGHT;
                break;
            case TrafficPath::RIGHT:
                curr_path_ = TrafficPath::DOWN;
                break;
            case TrafficPath::DOWN:
                curr_path_ = TrafficPath::LEFT;
                break;
            }
        }
    }
}

void TrafficCrossingProcedures::DisplayTrafficPath(const TrafficPath& path) {
    switch(path) {
    case TrafficPath::LEFT:
        DisplayTraffic1();
        break;
    case TrafficPath::UP:
        DisplayTraffic2();
        break;
    case TrafficPath::RIGHT:
        DisplayTraffic3();
        break;
    case TrafficPath::DOWN:
        DisplayTraffic4();
        break;
    }
}

// ��ʱ
void TrafficCrossingProcedures::DelayTime(double seconds) {
    clock_t delay = seconds * CLOCKS_PER_SEC;
    clock_t start = clock();
    while(clock() - start < delay);
}


void TrafficCrossingProcedures::DisplayTraffic1() {
    cout << "---------------------------------------" << endl;
    cout << "��ʾ��ǰ��ͨ���ź��£���ͨ�е������" << endl;
    cout << "             |    2   |                " << endl;
    cout << "             |    |   |                " << endl;
    cout << "             |    | * |                " << endl;
    cout << "             | |  | * |                " << endl;
    cout << "             | *  | | |                " << endl;
    cout << "-------------  |    *  ----------------" << endl;
    cout << "           <-- *    *-- <--            " << endl;
    cout << "1-------------      /  ---------------3" << endl;
    cout << "-->-->-->-->-->-->-->-->-->-->-->-->-->" << endl;
    cout << "-------------- \    *  ----------------" << endl;
    cout << "             | |  | * |                " << endl;
    cout << "             | *  | | |                " << endl;
    cout << "             |    |   |                " << endl;
    cout << "             |    |   |                " << endl;
    cout << "             |    4   |                " << endl << endl;
    cout << "1�г����ĳ�����ֱ�н���3����������ת����4����������ת����2������" << endl;
    cout << "2�����еĳ���������ת����1������" << endl;
    cout << "3�����еĳ���������ת����2������" << endl;
    cout << "4�����еĳ���������ת����3������" << endl;
    cout << "---------------------------------------" << endl;
}

void TrafficCrossingProcedures::DisplayTraffic2() {
    cout << "---------------------------------------" << endl;
    cout << "��ʾ��ǰ��ͨ���ź��£���ͨ�е������" << endl;
    cout << "             |    2   |                " << endl;
    cout << "             | |  |   |                " << endl;
    cout << "             | *  |   |                " << endl;
    cout << "             | |  | * |                " << endl;
    cout << "             | *  | * |                " << endl;
    cout << "-------------  |    |  ----------------" << endl;
    cout << "           <-- *    **-<--           " << endl;
    cout << "1------------- |       ---------------3" << endl;
    cout << "           --> * \-->-->-->            " << endl;
    cout << "-------------  |    *  ----------------" << endl;
    cout << "             | *  | * |                " << endl;
    cout << "             | |  | | |                " << endl;
    cout << "             | *  |   |                " << endl;
    cout << "             | |  |   |                " << endl;
    cout << "             |    4   |                " << endl << endl;
    cout << "2�г����ĳ�����ֱ�н���4����������ת����1����������ת����3������" << endl;
    cout << "1�����еĳ���������ת����4������" << endl;
    cout << "3�����еĳ���������ת����2������" << endl;
    cout << "4�����еĳ���������ת����3������" << endl;
    cout << "---------------------------------------" << endl;
}

void TrafficCrossingProcedures::DisplayTraffic3() {
    cout << "---------------------------------------" << endl;
    cout << "��ʾ��ǰ��ͨ���ź��£���ͨ�е������" << endl;
    cout << "             |    2   |                " << endl;
    cout << "             |    |   |                " << endl;
    cout << "             |    | * |                " << endl;
    cout << "             | |  | * |                " << endl;
    cout << "             | *  | | |                " << endl;
    cout << "------------- /      \ ----------------" << endl;
    cout << "<--<--<--<--<--<- <--<--<--<--<--<--<--" << endl;
    cout << "1-------------  /      ---------------3" << endl;
    cout << "        -->--> |     / ->->            " << endl;
    cout << "-------------  *    /  ----------------" << endl;
    cout << "             | |  | * |                " << endl;
    cout << "             | *  | * |                " << endl;
    cout << "             |    | | |                " << endl;
    cout << "             |    |   |                " << endl;
    cout << "             |    4   |                " << endl << endl;
    cout << "3�г����ĳ�����ֱ�н���1����������ת����2����������ת����4������" << endl;
    cout << "1�����еĳ���������ת����4������" << endl;
    cout << "2�����еĳ���������ת����1������" << endl;
    cout << "4�����еĳ���������ת����3������" << endl;
    cout << "---------------------------------------" << endl;
}

void TrafficCrossingProcedures::DisplayTraffic4() {
    cout << "---------------------------------------" << endl;
    cout << "��ʾ��ǰ��ͨ���ź��£���ͨ�е������" << endl;
    cout << "             |    2   |                " << endl;
    cout << "             |    | * |                " << endl;
    cout << "             |    | * |                " << endl;
    cout << "             | |  | | |                " << endl;
    cout << "             | *  | * |                " << endl;
    cout << "-------------  |    *  ----------------" << endl;
    cout << "          <-- <--   | \ --<--          " << endl;
    cout << "1------------     \ *  ---------------3" << endl;
    cout << "        -->-->      *  -->-->          " << endl;
    cout << "-------------  \    | / ---------------" << endl;
    cout << "             | *  | * |                " << endl;
    cout << "             | |  | * |                " << endl;
    cout << "             | *  | | |                " << endl;
    cout << "             |    | * |                " << endl;
    cout << "             |    4 * |                " << endl << endl;
    cout << "4�г����ĳ�����ֱ�н���2����������ת����3����������ת����1������" << endl;
    cout << "1�����еĳ���������ת����4������" << endl;
    cout << "2�����еĳ���������ת����1������" << endl;
    cout << "3�����еĳ���������ת����2������" << endl;
    cout << "---------------------------------------" << endl;
}
