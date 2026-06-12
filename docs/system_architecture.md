# System Architecture

## Overview

The Predictive Maintenance System monitors machine condition by combining vibration analysis and temperature monitoring. Processed data is classified into fault states and transmitted to a cloud dashboard for remote observation.

---

## High-Level Architecture

```text
                +----------------+
                | Temperature    |
                | Generator      |
                +--------+-------+
                         |
                         |
                         v
+-------------+    +------------+     +----------------+
| Vibration   |--->| RMS Module |---->| Fault Detector |
| Generator   |    +------------+     +--------+-------+
+------+------+                           |
       |                                  |
       +----------------------------------+
                                          |
                                          v
                                 +----------------+
                                 | Fault State    |
                                 | Classification |
                                 +--------+-------+
                                          |
                                          v
                                 +----------------+
                                 | NodeMCU ESP8266|
                                 +--------+-------+
                                          |
                                          v
                                 +----------------+
                                 | ThingSpeak     |
                                 | Cloud Dashboard|
                                 +----------------+
```

---

## Data Flow

### Vibration Path

```text
Vibration Generator
        ↓
Sliding Window Buffer
        ↓
RMS Calculation
        ↓
Fault Detection
```

---

### Temperature Path

```text
Temperature State Machine
        ↓
Temperature Value
        ↓
Fault Detection
```

---

### Communication Path

```text
Fault Detection Results
        ↓
NodeMCU WiFi Stack
        ↓
HTTP Request
        ↓
ThingSpeak Cloud
        ↓
Dashboard Visualization
```

---

## Hardware Components

### NodeMCU ESP8266

Responsibilities:

* Firmware execution
* WiFi communication
* Data processing
* Cloud connectivity

---

## Software Components

### Signal Processing

* RMS calculation
* Sliding window analysis

### State Machines

Temperature State Machine:

* NORMAL
* HEATING
* FAULT
* RECOVERY

Fault State Machine:

* NORMAL
* WARNING
* CRITICAL
* RECOVERY

### Cloud Monitoring

ThingSpeak fields:

| Field   | Parameter   |
| ------- | ----------- |
| Field 1 | Temperature |
| Field 2 | RMS         |
| Field 3 | Fault State |
| Field 4 | Vibration   |

---

## Future Improvements

* Real vibration sensor integration
* Real temperature sensor integration
* MQTT communication
* Local OLED display
* Predictive health scoring
* Remaining Useful Life estimation
* Fault history logging
* OTA firmware updates
