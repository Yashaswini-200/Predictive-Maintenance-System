#ifndef FAULT_H
#define FAULT_H
enum FaultState
{
    NORMAL,
    WARNING,
    FAULT,
    RECOVERY
};
FaultState get_fault_state(
    float temperature,
    float rms);
#endif