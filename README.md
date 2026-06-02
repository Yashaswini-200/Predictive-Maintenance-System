Predictive Maintenance System (Industrial IoT Simulation)
Overview

The Predictive Maintenance System is an Industrial IoT project that simulates machine health monitoring using virtual vibration and temperature sensors.

The system continuously generates machine condition data, processes the information, detects abnormal operating conditions, and uploads the results to a cloud dashboard for remote monitoring.

This project demonstrates the core concepts of Predictive Maintenance used in modern industries to reduce downtime and prevent unexpected equipment failures.

Problem Statement

Traditional maintenance approaches often result in either:

Unexpected machine failures (Reactive Maintenance)
Unnecessary servicing and component replacement (Preventive Maintenance)

A Predictive Maintenance System monitors machine health continuously and identifies potential failures before breakdown occurs.

Objectives
Simulate vibration sensor data
Simulate machine temperature data
Calculate vibration RMS values
Detect abnormal machine conditions
Upload data to IoT cloud platform
Generate maintenance alerts
Visualize machine health remotely
Features
Vibration Simulation
Generates sinusoidal vibration signals
Supports abnormal vibration spike injection
Simulates machine wear and faults
Temperature Monitoring
Simulates machine temperature trends
Generates overheating scenarios
Provides realistic sensor-like variations
Signal Processing
Stores vibration samples
Computes RMS vibration levels
Evaluates machine vibration intensity
Fault Detection
Threshold-based anomaly detection
High vibration alerts
High temperature alerts
IoT Integration
Cloud dashboard visualization
Historical data logging
Remote monitoring support
System Architecture
Virtual Vibration Sensor
            │
            ▼
Virtual Temperature Sensor
            │
            ▼
Data Buffer
            │
            ▼
RMS Calculation
            │
            ▼
Fault Detection
            │
            ▼
Cloud Upload
            │
            ▼
Dashboard & Alerts
Technologies Used
Hardware
NodeMCU (ESP8266) / ESP32
Wi-Fi Network
Software
Arduino IDE
Wokwi Simulator
ThingSpeak
Git & GitHub
Programming Language
Embedded C / Arduino C++
Project Structure
Predictive-Maintenance-System/

│
├── README.md
│
├── docs/
│   ├── Project_Overview.md
│   ├── System_Architecture.md
│   └── Firmware_Design.md
│
├── src/
│   ├── vibration.h
│   ├── vibration.cpp
│   ├── temperature.h
│   ├── temperature.cpp
│   ├── rms.h
│   ├── rms.cpp
│   ├── fault.h
│   ├── fault.cpp
│   ├── cloud.h
│   └── cloud.cpp
│
├── screenshots/
│
└── report/
Workflow
Generate Sensor Data
         ↓
Store Samples
         ↓
Calculate RMS
         ↓
Detect Faults
         ↓
Upload to Cloud
         ↓
Generate Alerts
         ↓
Repeat
Learning Outcomes
Embedded Firmware Development
Industrial IoT Concepts
Signal Processing Fundamentals
RMS Calculation Techniques
Cloud Data Visualization
Fault Detection Algorithms
Real-Time Monitoring Systems
Future Enhancements
FFT-based vibration analysis
Machine Learning anomaly detection
Predictive failure estimation
Multi-machine monitoring
Mobile notification system
MQTT-based communication
Author

Yashaswini

Embedded Systems & IoT Internship Project
