#ifndef FAULT_H
#define FAULT_H
enum FaultState
{
    FAULT_NORMAL,
    FAULT_WARNING,
    FAULT_CRITICAL,
    FAULT_RECOVERY
};
FaultState get_fault_state(float temperature,float rms);

#endif