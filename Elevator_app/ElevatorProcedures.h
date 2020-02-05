#ifndef ELEVATOR_PROCEDURES_H
#define ELEVATOR_PROCEDURES_H

#include <vector>
#include <map>

enum ElevatorState {
    S = 0,
    U = 1,
    D = 2
};

class ElevatorProcedures {

public:

    ElevatorProcedures();

    ~ElevatorProcedures();

    void ResetElevator();

    void RunElevator();

    void SetupCurrentState(const ElevatorState& state, const int& level);

    // ��¥
    void GoUpElevator(std::multimap<ElevatorState, int>& each_level);

    // ��ǰ��¥¥��С��С¥¥�㣬����������4¥����������12¥�����½�,�ҳ�12¥
    int UpToMaxLevelTypes();

    // ��¥
    void GoDownElevator(std::multimap<ElevatorState, int>& each_level);

    // ��¥¥�������¥¥�㣬�����½���4¥��������1¥�����������ҳ�1¥
    int DownToMinLevelTypes();

    // ��ͣ
    void StayElevator();

    // ������
    void TypeElevator(const ElevatorState& type, const int& level);

private:

    // ��ʱ
    void DelayTime(double seconds);

    // ���¥��
    int max_level_;

    // ��С¥��
    int min_level_;

    // ��ǰ����״̬����¥/��¥
    ElevatorState curr_state_;

    // ��ǰ¥��
    int curr_level_;

    // ��¼���ٰ���
    int count_;

    // ����¥�㰴����ʱ��״̬�Լ�¥�㣺��¥/��¥
    std::multimap<ElevatorState, int> each_level_;

    // ��һ�������ݵ�״̬
    ElevatorState first_state_;
};

#endif // ELEVATOR_PROCEDURES_H
