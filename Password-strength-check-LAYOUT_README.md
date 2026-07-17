# Password Strength Checker in C — Part 5

## 📌 Module Overview
This repository contains the fifth major architectural evolution (Part 5) of the C-based password complexity analysis framework. This update transitions the application from a simple script into a full-fledged **CLI Management Dashboard** backed by a **Persistent Binary File Database (`password.bin`)**. 

## ⚙️ Evolving Logic Updates
1. **Interactive Dashboard Navigation**: Wraps the program in a master `do-while` menu block featuring explicit operation choices ($1-4$).
2. **Persistent Storage Module**: Integrates `int file(char[], int)` subroutine using standard File I/O modes (`ab`, `rb`) to write, stream, and clear passwords locally.
3. **Robust Input Flushing**: Implements inline `while (getchar() != '\n');` stream buffers to completely eliminate console trailing new-line glitches.

```text
              [ START OF APPLICATION ]
                         │
                         ▼
         ┌──►[ Master Menu Loop: do-while ]◄──┐
         │               │                    │
         │               ▼                    │
         │   [ 1. Check  2. View  3. Delete  4. Exit ]
         │               │                    │
         │               ▼                    │
         │      [ Switch Selector ]           │
         │               │                    │
   ┌─────┴───────────────┼────────────────────┴──────────────┐
   ▼                     ▼                                   ▼
[CASE 1: CHECK]      [CASE 2: VIEW]                  [CASE 3: DELETE]
   │                     │                                   │
   ▼                     ▼                                   ▼
Scan/Parse string    Call: file(z, 1)                    Call: file(z, 2)
   │                     │                                   │
   ▼                     ├─► File Missing: Alert             ├─► File Missing: Alert
chk(u,s,n,sp)            │                                   │
   │                     └─► Stream & Print Passwords        └─► Secure remove()
   ▼                               │                                   │
Save Prompt (y/n)?                 ▼                                   ▼
   │                     [ Call: flreop() ]                  [ Call: flreop() ]
   ├─► (y) ──► file(z,0)           │                                   │
   │            [Save to file]     ├─► (y) Return to Menu ─────────────┤
   │               │               │                                   │
   └─► (n) ──► reop() ─────────────└─► (n) exit(0) [Terminate System] ─┘
                │
                ├─► (y) Restart Check
                │
                └─► (n) Return to Menu