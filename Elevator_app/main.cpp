#include <iostream>
#include "ElevatorProcedures.h"

using namespace std;

int main()
{
    // 电梯程序
    ElevatorProcedures my_elevator;

    // Todo: 这部分键入电梯的程序，理论上应该是与电梯运行是并行的
    ElevatorState state_up = U;
    ElevatorState state_down = D;
    // 按电梯
    vector<int> level_up = {4, 7, 12};
    vector<int> level_down = {13, 4, 8};
    for (int i = 0; i < level_up.size(); ++i) {
        my_elevator.TypeElevator(state_up, level_up[i]);
    }
    for (int i = 0; i < level_down.size(); ++i) {
        my_elevator.TypeElevator(state_down, level_down[i]);
    }

    // 设置当前电梯楼层
    my_elevator.SetupCurrentState(ElevatorState::D, 8);
    // 运行电梯
    my_elevator.RunElevator();

    return 0;
}
