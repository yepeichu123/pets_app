#include "ElevatorProcedures.h"
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

// Ĭ�Ϲ��캯��
ElevatorProcedures::ElevatorProcedures() {
    min_level_ = 1;
    max_level_ = 13;

    count_ = 0;

    curr_level_ = 1;
    curr_state_ = ElevatorState::S;
    first_state_ = ElevatorState::S;

    cout << "����״̬ " << ElevatorState::U << " ��ʾ�������У�" << endl;
    cout << "����״̬ " << ElevatorState::D << " ��ʾ�������У�" << endl;
    cout << "����״̬ " << ElevatorState::S << " ��ʾ������ͣ��" << endl;
}

// Ĭ����������
ElevatorProcedures::~ElevatorProcedures() {

}

// ���˰�����ʱ�����»ص�һ¥
void ElevatorProcedures::ResetElevator() {
    if (curr_level_ > 1) {
        cout << "��ǰ¥��Ϊ " << curr_level_ << " �����»ص�һ¥��" << endl;
        curr_state_ = D;
        multimap<ElevatorState, int> temp;
        temp.insert(make_pair(curr_state_, min_level_));
        GoDownElevator(temp);
    }
    else {
        cout << "��ǰ¥��Ϊ 1 ¥�������ƶ���" << endl;
        curr_state_ = S;
    }
}

// ��������
void ElevatorProcedures::RunElevator() {
    // ��ǰ�����ݵ�¥������
    int nlevels = each_level_.size();
    cout << "���� " << nlevels << " ��������Ҫִ�У�" << endl;

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
        cout << "���õ�ǰ����״̬Ϊ " << state << ", ��ǰ¥��Ϊ " << level << " <<<<<<<<<<<<<<<< " << endl;
    }
    else {
        cout << "¥�����ó�����Χ�����������ã�" << endl;
    }
}

// ��¥
void ElevatorProcedures::GoUpElevator(multimap<ElevatorState, int>& each_level) {
    // ȡ��¥���ֵİ���
    multimap<ElevatorState, int>::iterator it = each_level.find(ElevatorState::U);
    multimap<ElevatorState, int>::iterator last = each_level.find(ElevatorState::D);
    vector<int> levels;
    while(it != last) {
        // ȡ�ȵ�ǰ���İ���¥��
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

    // ������¥���������
    cout << ">>>>>>>>>>>>>>>>>>>��������" << endl;
    sort(levels.begin(), levels.end());
    vector<int>::iterator it_level = levels.begin();
    while(it_level != levels.end()) {
        while(*it_level >= curr_level_) {
            cout << ">>>>>>>>>>>>>>>>>>>��ǰ¥��Ϊ " << curr_level_ << endl;
            DelayTime(1);
            if (*it_level == curr_level_) {
                DelayTime(1);
                cout << "*******************����¥�� " << *it_level << " *******************" << endl << endl;
            }
            curr_level_++;
        }
        ++it_level;
    }
    --curr_level_;
}

// ��ǰ��¥¥��С��С¥¥�㣬����������4¥����������12¥�����½�,�ҳ�12¥
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

// ��¥
void ElevatorProcedures::GoDownElevator(multimap<ElevatorState, int>& each_level) {
    // ȡ��¥���ֵİ���
    multimap<ElevatorState, int>::iterator it = each_level.find(ElevatorState::D);
    vector<int> levels;
    while(it != each_level.end()) {
        // ȡ�ȵ�ǰ���İ���¥��
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

    // ������¥���������
    cout << ">>>>>>>>>>>>>>>>>>>��������" << endl;
    sort(levels.begin(), levels.end());
    for (int i = levels.size()-1; i >= 0; --i) {
        int next_level = levels[i];
        while (next_level <= curr_level_) {
            cout << ">>>>>>>>>>>>>>>>>>>��ǰ¥��Ϊ " << curr_level_ << endl;
            DelayTime(1);
            if (next_level == curr_level_) {
                cout << "*******************����¥�� " << next_level << "*******************" << endl << endl;
                DelayTime(1);
            }
            --curr_level_;
        }
    }

    ++curr_level_;
}

// ��¥¥�������¥¥�㣬�����½���4¥��������1¥�����������ҳ�1¥
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

// ��ͣ
void ElevatorProcedures::StayElevator() {
    cout << "��ǰ���˰����ݣ���ͣ��" << endl;
    DelayTime(1);
}

// ������
void ElevatorProcedures::TypeElevator(const ElevatorState& type, const int& level) {
    if (count_ == 0) {
        first_state_ = type;
    }

    if (level >= min_level_ && level <= max_level_) {
        ++count_;
        each_level_.insert(make_pair(type, level));
        cout << "�������� = " << type << ", ����¥�� = " << level << endl;
    }
    else {
        cout << "����¥�㣡" << endl;
    }
}

// ��ʱ
void ElevatorProcedures::DelayTime(double seconds) {
    clock_t delay = seconds * CLOCKS_PER_SEC;
    clock_t start = clock();
    while(clock() - start < delay);
}


