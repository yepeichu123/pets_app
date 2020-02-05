#include <iostream>
#include "ElevatorProcedures.h"

using namespace std;

int main()
{
    // ���ݳ���
    ElevatorProcedures my_elevator;

    // Todo: �ⲿ�ּ�����ݵĳ���������Ӧ��������������ǲ��е�
    ElevatorState state_up = U;
    ElevatorState state_down = D;
    // ������
    vector<int> level_up = {4, 7, 12};
    vector<int> level_down = {13, 4, 8};
    for (int i = 0; i < level_up.size(); ++i) {
        my_elevator.TypeElevator(state_up, level_up[i]);
    }
    for (int i = 0; i < level_down.size(); ++i) {
        my_elevator.TypeElevator(state_down, level_down[i]);
    }

    // ���õ�ǰ����¥��
    my_elevator.SetupCurrentState(ElevatorState::D, 8);
    // ���е���
    my_elevator.RunElevator();

    return 0;
}
