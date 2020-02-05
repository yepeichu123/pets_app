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

    // 上楼
    void GoUpElevator(std::multimap<ElevatorState, int>& each_level);

    // 当前上楼楼层小于小楼楼层，比如上升到4楼，而有人在12楼按了下降,找出12楼
    int UpToMaxLevelTypes();

    // 下楼
    void GoDownElevator(std::multimap<ElevatorState, int>& each_level);

    // 下楼楼层大于上楼楼层，比如下降到4楼后，有人在1楼按了上升，找出1楼
    int DownToMinLevelTypes();

    // 悬停
    void StayElevator();

    // 按电梯
    void TypeElevator(const ElevatorState& type, const int& level);

private:

    // 延时
    void DelayTime(double seconds);

    // 最大楼层
    int max_level_;

    // 最小楼层
    int min_level_;

    // 当前电梯状态：上楼/下楼
    ElevatorState curr_state_;

    // 当前楼层
    int curr_level_;

    // 记录多少按键
    int count_;

    // 各个楼层按电梯时的状态以及楼层：上楼/下楼
    std::multimap<ElevatorState, int> each_level_;

    // 第一个按电梯的状态
    ElevatorState first_state_;
};

#endif // ELEVATOR_PROCEDURES_H
