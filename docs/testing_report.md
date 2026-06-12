**VIBRATION**
Module Tested:
Vibration Simulator

Result:
PASS

Observations:
Generated noisy sinusoidal waveform.

Noise Range:
Approximately ±0.2

Sampling Interval:
100 ms

Status:
Ready for integration with RMS module.

**TEMPERATURE**

Module Tested:
Temperature Simulator

Result:
PASS

Observations:
Generated stable temperature values around the target operating temperature of 37°C.

Fluctuation Range:
Approximately ±0.2°C

Control Mechanism:
Feedback correction applied to prevent long-term temperature drift.

Operating Range:
36.5°C – 37.5°C (observed during testing)

Status:
Normal state simulation verified and ready for integration with the temperature state machine.

**RMS**

Module Tested:
RMS Calculator (Sliding Window)

Result:
PASS

Observations:
Successfully calculated RMS values using a 10-sample circular buffer. RMS values varied according to changes in vibration amplitude and remained stable under steady operating conditions.

Buffer Size:
10 Samples

Calculation Method:
Root Mean Square (RMS) of vibration samples using a sliding window approach.

Observed RMS Range:
0.5 – 1.1 (Normal Operation)

Features Verified:

* Circular buffer operation
* Buffer wrap-around handling
* RMS readiness check
* Continuous RMS updates after buffer fill

Status:
RMS calculation verified and ready for integration with the fault detection module.

**FAULT DETECTION**

Module Tested:
Fault Detection State Machine

Result:
PASS

Observations:
Successfully classified machine condition using temperature and RMS inputs. State transitions occurred correctly based on predefined thresholds and operating conditions.

States Implemented:

* NORMAL
* WARNING
* CRITICAL
* RECOVERY

Decision Parameters:

* Temperature
* RMS Vibration Level

Transition Logic:
State changes are determined using combined temperature and vibration analysis. Recovery validation requires multiple consecutive healthy readings before returning to NORMAL operation.

Features Verified:

* State transition handling
* Warning condition detection
* Critical fault detection
* Recovery validation mechanism
* Consecutive healthy sample counting

Observed Behaviour:
System transitioned correctly between NORMAL and WARNING states during testing. State machine logic executed as expected without instability.

Status:
Fault detection state machine verified and ready for cloud integration and dashboard monitoring.
