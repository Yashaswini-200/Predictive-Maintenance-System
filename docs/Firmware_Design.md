# Firmware Design

## Overview

The Predictive Maintenance System firmware is designed using a modular architecture to simulate machine condition monitoring and fault detection. The firmware continuously generates vibration and temperature data, processes vibration signals using RMS analysis, determines machine health through a fault state machine, and uploads data to ThingSpeak for remote monitoring.

---

## Design Goals

* Modular and maintainable code structure
* Separation of functionality into independent modules
* Real-time signal processing
* Fault state monitoring
* Cloud connectivity using WiFi
* Easy scalability for real sensor integration

---

## Firmware Modules

### 1. Vibration Module

**Purpose:**
Simulates machine vibration signals.

**Responsibilities:**

* Generate vibration waveform
* Add random noise for realism
* Simulate different vibration levels

**Output:**

* Instantaneous vibration sample

---

### 2. Temperature Module

**Purpose:**
Simulates machine temperature behavior using a state machine.

**States:**

* NORMAL
* HEATING
* FAULT
* RECOVERY

**Responsibilities:**

* Generate realistic temperature values
* Simulate heating and cooling cycles
* Provide machine thermal condition

---

### 3. RMS Module

**Purpose:**
Calculate vibration severity.

**Method:**

* Sliding window RMS calculation
* Circular buffer implementation

**Responsibilities:**

* Store recent vibration samples
* Compute RMS value
* Filter instantaneous noise

---

### 4. Fault Detection Module

**Purpose:**
Determine machine condition.

**Fault States:**

* NORMAL
* WARNING
* CRITICAL
* RECOVERY

**Inputs:**

* Temperature
* RMS vibration level

**Responsibilities:**

* Classify machine health
* Detect abnormal conditions
* Handle state transitions
* Prevent false fault recovery

---

### 5. Communication Module

**Purpose:**
Upload monitoring data to ThingSpeak.

**Responsibilities:**

* Connect to WiFi network
* Upload data periodically
* Handle HTTP communication

**Uploaded Parameters:**

* Temperature
* RMS
* Fault State
* Vibration

---

## Main Control Flow

1. Generate vibration sample
2. Generate temperature sample
3. Update RMS buffer
4. Calculate RMS value
5. Evaluate fault state
6. Display debug information
7. Upload data to ThingSpeak
8. Repeat continuously

---

## Design Advantages

* Modular architecture
* Easy debugging
* Reusable components
* Scalable for real sensors
* Suitable for embedded systems learning
* Clear separation of responsibilities
