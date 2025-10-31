# 🧠 Basic Enums in C — A Human-Readable Guide

## Overview

An **enum** (short for *enumeration*) is a set of named integer constants.  
They allow us to write **human-first** code that’s clear, expressive, and still runs at zero runtime cost.  
In performance engineering (ULL, low-latency systems, networking), enums make your logic self-documenting without slowing it down.

---

## 1. Defining an Enum

```c
typedef enum {
    PACKET_MARKET_DATA = 0,
    PACKET_ORDER_SUBMISSION,
    PACKET_HEARTBEAT,
    PACKET_CONTROL
} PacketType;


What this means

Each name maps to an integer (0, 1, 2, 3).

They improve readability without changing performance.

You can assign explicit numbers if you need protocol-level control.


2. Using Enums in Structs
typedef struct {
    PacketType type;
    double timestamp;
    char payload[256];
} Packet;

We use PacketType inside the Packet structure so every packet carries a clear, semantic type.
