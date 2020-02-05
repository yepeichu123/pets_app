#include "ElevatorProcedures.h"
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

// 默认构造函数
ElevatorProcedures::ElevatorProcedures() {
    min_level_ = 1;
    max_level_ = 13;

    count_ = 0;

    curr_level_ = 1;
    curr_state_ = ElevatorState::S;
    first_state_ = ElevatorState::S;

    cout << "电梯状态 " << ElevatorState::U << " 表示电梯上行！" << endl;
    cout << "电梯状态 " << ElevatorState::D << " 表示电梯下行！" << endl;
    cout << "电梯状态 " << ElevatorState::S << " 表示电梯悬停！" << endl;
}

// 默认析构函数
ElevatorProcedures::~ElevatorProcedures() {

}

// 无人按电梯时，重新回到一楼
void ElevatorProcedures::ResetElevator() {
    if (curr_level_ > 1) {
        cout << "当前楼层为 " << curr_level_ << " ，重新回到一楼！" << endl;
        curr_state_ = D;
        multimap<ElevatorState, int> temp;
        temp.insert(make_pair(curr_state_, min_level_));
        GoDownElevator(temp);
    }
    else {
        cout << "当前楼层为 1 楼，无需移动！" << endl;
        curr_state_ = S;
    }
}

// 电梯运行
void ElevatorProcedures::RunElevator() {
    // 当前按电梯的楼层数量
    int nlevels = each_level_.size();
    cout << "共有 " << nlevels << " 个任务需要执行！" << endl;

    while (nlevels != 0) {
        switch (first_state_) {
            case ElevatorState::U: {
                GoUpElevator(each_level_);
                int max_l = UpToMaxLevelTypes();
                if (max_l > 0) {
                    multimap<ElevatorState, int> temp;
                    temp.insert(make_pair(ElevatorState::U, max_l));
                    GoUpElevator(temp);
                }
                first_state_ = ElevatorState::D;
                break;
            }
            case ElevatorState::D: {
                GoDownElevator(each_level_);
                int min_l = DownToMinLevelTypes();
                if (min_l > 0) {
                    multimap<ElevatorState, int> temp;
                    temp.insert(make_pair(ElevatorState::D, min_l));
                    GoDownElevator(temp);
                }
                first_state_ = ElevatorState::U;
                break;
            }
            case ElevatorState::S: {
                StayElevator();
                first_state_ = ElevatorState::D;
                break;
            }
        }
        nlevels = each_level_.size();
    }

    if (nlevels == 0) {
        StayElevator();
        if (curr_level_ > min_level_) {
            multimap<ElevatorState, int> temp;
            temp.insert(make_pair(ElevatorState::D, min_level_));
            GoDownElevator(temp);
        }
    }
}

void ElevatorProcedures::SetupCurrentState(const ElevatorState& state, const int& level) {
    if (level >= min_level_ && level <= max_level_) {
        curr_state_ = state;
        curr_level_ = level;
        cout << "设置当前电梯状态为 " << state << ", 当前楼层为 " << level << " <<<<<<<<<<<<<<<< " << endl;
    }
    else {
        cout << "楼层设置超出范围，请重新设置！" << endl;
    }
}

// 上楼
void ElevatorProcedures::GoUpElevator(multimap<ElevatorState, int>& each_level) {
    // 取上楼部分的按键
    multimap<ElevatorState, int>::iterator it = each_level.find(ElevatorState::U);
    multimap<ElevatorState, int>::iterator last = each_level.find(ElevatorState::D);
    vector<int> levels;
    while(it != last) {
        // 取比当前层大的按键楼层
        if (it->second >= curr_level_) {
            levels.push_back(it->second);
            it = each_level.erase(it);
            --count_;
        }
        else {
            ++it;
        }
    }

    if (levels.empty()) {
        return;
    }

    // 将所有楼层进行排序
    cout << ">>>>>>>>>>>>>>>>>>>电梯上行" << endl;
    sort(levels.begin(), levels.end());
    vector<int>::iterator it_level = levels.begin();
    while(it_level != levels.end()) {
        while(*it_level >= curr_level_) {
            cout << ">>>>>>>>>>>>>>>>>>>当前楼层为 " << curr_level_ << endl;
            DelayTime(1);
            if (*it_level == curr_level_) {
                DelayTime(1);
                cout << "*******************到达楼层 " << *it_level << " *******************" << endl << endl;
            }
            curr_level_++;
        }
        ++it_level;
    }
    --curr_level_;
}

// 当前上楼楼层小于小楼楼层，比如上升到4楼，而有人在12楼按了下降,找出12楼
int ElevatorProcedures::UpToMaxLevelTypes() {

    vector<int> levels_down;

    multimap<ElevatorState, int>::iterator it = each_level_.find(ElevatorState::D);
    while (it != each_level_.end()) {
        levels_down.push_back(it->second);
        ++it;
    }
    if (levels_down.size() == 0) {
        return -1;
    }

    sort(levels_down.begin(), levels_down.end());
    int max_level = levels_down[levels_down.size()-1];
    if (curr_level_ < max_level) {
        return max_level;
    }
    else {
        return -1;
    }
}

// 下楼
void ElevatorProcedures::GoDownElevator(multimap<ElevatorState, int>& each_level) {
    // 取上楼部分的按键
    multimap<ElevatorState, int>::iterator it = each_level.find(ElevatorState::D);
    vector<int> levels;
    while(it != each_level.end()) {
        // 取比当前层大的按键楼层
        if (it->second <= curr_level_) {
            levels.push_back(it->second);
            it = each_level.erase(it);
            --count_;
        }
        else {
            ++it;
        }
    }

    if (levels.empty()) {
        return;
    }

    // 将所有楼层进行排序
    cout << ">>>>>>>>>>>>>>>>>>>电梯下行" << endl;
    sort(levels.begin(), levels.end());
    for (int i = levels.size()-1; i >= 0; --i) {
        int next_level = levels[i];
        while (next_level <= curr_level_) {
            cout << ">>>>>>>>>>>>>>>>>>>当前楼层为 " << curr_level_ << endl;
            DelayTime(1);
            if (next_level == curr_level_) {
                cout << "*******************到达楼层 " << next_level << "*******************" << endl << endl;
                DelayTime(1);
            }
            --curr_level_;
        }
    }

    ++curr_level_;
}

// 下楼楼层大于上楼楼层，比如下降到4楼后，有人在1楼按了上升，找出1楼
int ElevatorProcedures::DownToMinLevelTypes() {

    vector<int> levels_up;

    multimap<ElevatorState, int>::iterator it = each_level_.find(ElevatorState::U);
    multimap<ElevatorState, int>::iterator last = each_level_.find(ElevatorState::D);
    while (it != last) {
        levels_up.push_back(it->second);
        ++it;
    }
    if (levels_up.size() == 0) {
        return -1;
    }

    sort(levels_up.begin(), levels_up.end());
    int min_level = levels_up[0];
    if (curr_level_ > min_level) {
        return min_level;
    }
    else {
        return -1;
    }
}

// 悬停
void ElevatorProcedures::StayElevator() {
    cout << "当前无人按电梯，悬停！" << endl;
    DelayTime(1);
}

// 按电梯
void ElevatorProcedures::TypeElevator(const ElevatorState& type, const int& level) {
    if (count_ == 0) {
        first_state_ = type;
    }

    if (level >= min_level_ && level <= max_level_) {
        ++count_;
        each_level_.insert(make_pair(type, level));
        cout << "电梯类型 = " << type << ", 按键楼层 = " << level << endl;
    }
    else {
        cout << "错误楼层！" << endl;
    }
}

// 延时
void ElevatorProcedures::DelayTime(double seconds) {
    clock_t delay = seconds * CLOCKS_PER_SEC;
    clock_t start = clock();
    while(clock() - start < delay);
}


