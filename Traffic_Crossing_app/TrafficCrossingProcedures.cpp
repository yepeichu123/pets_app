
#include "TrafficCrossingProcedures.h"
#include <iostream>
#include <ctime>

using namespace std;

// 默认构造函数
TrafficCrossingProcedures::TrafficCrossingProcedures() {
    curr_light_ = TrafficLight::GREEN;
    curr_path_ = TrafficPath::LEFT;
}

// 默认析构函数
TrafficCrossingProcedures::~TrafficCrossingProcedures() {

}

void TrafficCrossingProcedures::SetupCurrentState(const TrafficLight& light, const TrafficPath& path) {
    curr_light_ = light;
    curr_path_ = path;
}

void TrafficCrossingProcedures::RunTrafficCrossingProcedures() {
    cout << "进入十字路口交通信号灯处理程序！" << endl;
    bool quit = false;
    while (!quit) {
        if (curr_light_ == TrafficLight::GREEN) {
            cout << ">>>>>>>>>>>>>>>>当前信号灯为绿灯！" << endl;
            DisplayTrafficPath(curr_path_);
            DelayTime(5);
            curr_light_ = TrafficLight::YELLOW;
        }
        else if (curr_light_ == TrafficLight::YELLOW) {
            cout << ">>>>>>>>>>>>>>>>当前信号灯为黄灯！" << endl;
            DisplayTrafficPath(curr_path_);
            DelayTime(3);
            curr_light_ = TrafficLight::RED;
        }
        else {
            cout << ">>>>>>>>>>>>>>>>当前信号灯为红灯！" << endl;
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

// 延时
void TrafficCrossingProcedures::DelayTime(double seconds) {
    clock_t delay = seconds * CLOCKS_PER_SEC;
    clock_t start = clock();
    while(clock() - start < delay);
}


void TrafficCrossingProcedures::DisplayTraffic1() {
    cout << "---------------------------------------" << endl;
    cout << "显示当前交通灯信号下，可通行的情况！" << endl;
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
    cout << "1中车道的车辆可直行进入3车道，可右转进入4车道，可左转进入2车道！" << endl;
    cout << "2车道中的车辆可以右转进入1车道！" << endl;
    cout << "3车道中的车辆可以右转进入2车道！" << endl;
    cout << "4车道中的车辆可以右转进入3车道！" << endl;
    cout << "---------------------------------------" << endl;
}

void TrafficCrossingProcedures::DisplayTraffic2() {
    cout << "---------------------------------------" << endl;
    cout << "显示当前交通灯信号下，可通行的情况！" << endl;
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
    cout << "2中车道的车辆可直行进入4车道，可右转进入1车道，可左转进入3车道！" << endl;
    cout << "1车道中的车辆可以右转进入4车道！" << endl;
    cout << "3车道中的车辆可以右转进入2车道！" << endl;
    cout << "4车道中的车辆可以右转进入3车道！" << endl;
    cout << "---------------------------------------" << endl;
}

void TrafficCrossingProcedures::DisplayTraffic3() {
    cout << "---------------------------------------" << endl;
    cout << "显示当前交通灯信号下，可通行的情况！" << endl;
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
    cout << "3中车道的车辆可直行进入1车道，可右转进入2车道，可左转进入4车道！" << endl;
    cout << "1车道中的车辆可以右转进入4车道！" << endl;
    cout << "2车道中的车辆可以右转进入1车道！" << endl;
    cout << "4车道中的车辆可以右转进入3车道！" << endl;
    cout << "---------------------------------------" << endl;
}

void TrafficCrossingProcedures::DisplayTraffic4() {
    cout << "---------------------------------------" << endl;
    cout << "显示当前交通灯信号下，可通行的情况！" << endl;
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
    cout << "4中车道的车辆可直行进入2车道，可右转进入3车道，可左转进入1车道！" << endl;
    cout << "1车道中的车辆可以右转进入4车道！" << endl;
    cout << "2车道中的车辆可以右转进入1车道！" << endl;
    cout << "3车道中的车辆可以右转进入2车道！" << endl;
    cout << "---------------------------------------" << endl;
}
