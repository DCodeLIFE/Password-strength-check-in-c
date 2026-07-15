# Password Strength Checker in C — Part 3

## 📌 Module Overview
This repository contains the third iterative stage (Part 3) of the dynamic password strength verification architecture in C. This build introduces **Functional Modularization** by decoupling the validation core matrix from the `main()` execution thread into a dedicated subroutine `chk()`, improving code reusability and structured flow control.

## ⚙️ Evolving Logic Updates
1. **Decoupled Architecture**: Nested parameter validation is now encapsulated inside a custom function prototype `void chk(int, int, int, int)`.
2. **Simplified Execution Call**: Replaces bulk conditional code blocks inside length evaluation paths with systematic, clean function triggers.
3. **Persisted Control States**: Retains the user dynamic length bypass protocols (`y/n`) established in the previous release.

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
│    Loop Matrix: for(...)       │  ◄── Scans string elements until '\0'
└───────────────┬────────────────┘
                │
                ├─► Uppercase Check ──► (u++)
                ├─► Lowercase Check ──► (s++)
                ├─► Numeric Check   ──► (n++)
                └─► Special Check   ──► (sp++)
                │
                ▼
┌────────────────────────────────┐
│  Print: String Total Length    │  ◄── Outputs absolute length count (c)
└───────────────┬────────────────┘
                │
                ▼
     ───[ Evaluation Branch ]───
                │
                ├─► [ 0 <= c <= 7 ] (Weak)
                │         │
                │         ▼
                │   [ Override Prompt? ] ──( n )──► Print: "Try Again"
                │         │ ( y )
                │         ▼
                │   [ Call Function: chk(u, s, n, sp) ]
                │
                ├─► [ 8 <= c <= 16 ] (Perfect)
                │         │
                │         ▼
                │   [ Call Function: chk(u, s, n, sp) ]
                │
                └─► [ 17 <= c <= 30 ] (Too Long)
                          │
                          ▼
                    [ Override Prompt? ] ──( n )──► Print: "Try Again"
                          │ ( y )
                          ▼
                    [ Call Function: chk(u, s, n, sp) ]
                │
                ▼
┌────────────────────────────────────────────────────────┐
│ ───► [ SUBROUTINE FUNCTION MODULE: chk() ]             │
│   Checks if (u>=1 && s>=1 && n>=1 && sp>=1)            │
│   Outputs "Usable password" OR explicit missing types   │
└───────────────────────┬────────────────────────────────┘
                        │
                        ▼
┌────────────────────────────────┐
│  Print: Character Counts       │  ◄── Prints detailed breakdown metrics
└───────────────┬────────────────┘
                │
                ▼
┌────────────────────────────────┐
│    [ EXIT FORM THE PROGRAM ]   │  ◄── Flushes buffers and returns 0
└────────────────────────────────┘