# Password Strength Checker in C — Part 1

## 📌 Module Overview
This repository contains the foundational implementation for a dynamic password evaluation system built in C. It validates passwords against industrial standard criteria rules by classifying string metrics in a clean pipeline.

## ⚙️ Core Logic Flow
1. **Dynamic Input Parsing**: Captures string inputs safely, accepting spaces up to a 29-character buffer limit.
2. **Matrix Token Generation**: Scans individual character arrays to group them into Uppercase, Lowercase, Numeric, and Special characters.
3. **Threshold Classification**: Filters data outputs into three distinct states based on absolute length boundaries (0-7, 8-16, 17-30).

```text
[ START OF EXECUTION ]
          │
          ▼
┌────────────────────────────────┐
│ Input: scanf(" %29[^\n]", z)   │  ◄── User inputs custom password string
└───────────────┬────────────────┘
                │
                ▼
┌────────────────────────────────┐
│    Loop Matrix: for(...)       │  ◄── Iterates over characters until '\0'
└───────────────┬────────────────┘
                │
                ├─► (z[i] >= 'A' && z[i] <= 'Z') ──► [ Uppercase Count (u++) ]
                ├─► (z[i] >= 'a' && z[i] <= 'z') ──► [ Lowercase Count (s++) ]
                ├─► (z[i] >= '0' && z[i] <= '9') ──► [ Numeric Count (n++)   ]
                └─► [ Else / Special Symbols ] ───► [ Special Count (sp++) ]
                │
                ▼
┌────────────────────────────────┐
│  Print: String Total Length    │  ◄── Outputs absolute length count (c)
└───────────────┬────────────────┘
                │
                ▼
     ───[ Evaluation Branch ]───
                │
                ├─► [ 0 <= c <= 7 ]  ──► Print: "Too short to use. Try Again"
                │
                ├─► [ 8 <= c <= 16 ] ──► Print: "Length is perfect"
                │           │
                │           ▼
                │     [ Criteria Matrix ]
                │           ├─► (u>=1 && s>=1 && n>=1 && sp>=1) ──► "Usable password"
                │           └─► (Else) ──► Print exact missing character type
                │
                └─► [ 17 <= c <= 30 ] ──► Print: "Too long to use. Try Again"
                │
                ▼
┌────────────────────────────────┐
│    [ EXIT FORM THE PROGRAM ]   │  ◄── Prints exit borders, flushes and returns 0
└────────────────────────────────┘