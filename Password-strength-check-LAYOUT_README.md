# Password Strength Checker in C — Part 4

## 📌 Module Overview
This repository showcases the fourth major architectural iteration (Part 4) of the C-based password complexity analysis framework. This version integrates a **Continuous Lifecycle Engine** using conditional application looping coupled with an exit management routine `reop()`. This allows users to test multiple strings dynamically without restarting the process binary.

## ⚙️ Evolving Logic Updates
1. **Application Runtime Loop**: Wraps execution within a persistent `while (x == 1)` state tracker.
2. **Dynamic Re-operation Controller**: Integrates `int reop(int)` subroutine to handle session refresh requests (`y/n`) or clean execution terminations (`exit(0)`).
3. **Optimized Missing Matrix**: Standardizes character checks inside `chk()` using clear conditional sequencing blocks.

```text
       [ START OF APPLICATION ]
                 │
                 ▼
     ───►[ Runtime Loop: while(x == 1) ]◄───┐
                 │                          │
                 ▼                          │
 ┌────────────────────────────────┐         │
 │ Input: scanf(" %29[^\n]", z)   │         │
 └───────────────┬────────────────┘         │
                 │                          │
                 ▼                          │
 ┌────────────────────────────────┐         │
 │  Loop Matrix: Scans String     │         │
 └───────────────┬────────────────┘         │
                 │                          │
                 ▼                          │
    ───[ Character Length Checks ]───       │
                 │                          │
  ├─► [ 0 <= c <= 7 ]  ──► Prompt Override  │
  ├─► [ 8 <= c <= 16 ] ──► Auto-Validate    │
  └─► [ 17 <= c <= 30 ] ──► Prompt Override  │
                 │                          │
                 ▼                          │
 ┌────────────────────────────────┐         │
 │ Module Call: chk(u, s, n, sp)  │         │
 └───────────────┬────────────────┘         │
                 │                          │
                 ▼                          │
 ┌────────────────────────────────┐         │
 │ Print Breakdown Character Logs │         │
 └───────────────┬────────────────┘         │
                 │                          │
                 ▼                          │
 ┌────────────────────────────────┐         │
 │ Function Call: x = reop(x)     │         │
 └───────────────┬────────────────┘         │
                 │                          │
        [ Check User Choice ]               │
                 │                          │
                 ├─► (Choice == 'y') ───────┘ [Loop Restarts]
                 │
                 └─► (Choice == 'n') ──► [ exit(0) / TERMINATE SYSTEM ]