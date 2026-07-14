# Password Strength Checker in C — Part 2

## 📌 Module Overview
This repository contains the second iterative stage (Part 2) of the dynamic password strength verification architecture in C. This build introduces user-controlled validation override pathways for passwords falling outside standard boundary limits, while retaining complete nested matrix scanning logic for complex character subsets.

## ⚙️ Evolving Logic Updates
1. **Interactive Failure Override**: Users can force the evaluation of "Weak" or "Too Long" passwords dynamically using `y/n` prompts.
2. **Persistent String Tracking**: Preserves character counts across both standard validation runs and forced user overrides.
3. **Structured Threshold Categorization**: Retains length bounds sorting ($0-7$, $8-16$, $17-30$) while branching user pathways within conditions.

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
│    Loop Matrix: for(...)       │  ◄── Scans string for characters until '\0'
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
                ├─► [ 0 <= c <= 7 ] (Weak)
                │         │
                │         ▼
                │   [ User Override Prompt? ] ──( n )──► Print: "Try Again"
                │         │ ( y )
                │         ▼
                │   [ Run Criteria Matrix ] ──► Print Breakdown metrics
                │
                ├─► [ 8 <= c <= 16 ] (Perfect)
                │         │
                │         ▼
                │   [ Run Criteria Matrix ] ──► Print Breakdown metrics
                │
                └─► [ 17 <= c <= 30 ] (Too Long)
                          │
                          ▼
                    [ User Override Prompt? ] ──( n )──► Print: "Try Again"
                          │ ( y )
                          ▼
                    [ Run Criteria Matrix ] ──► Print Breakdown metrics
                │
                ▼
┌────────────────────────────────┐
│   [ Run Criteria Matrix Logic ]│  ◄─ Validates if (u>=1 && s>=1 && n>=1 && sp>=1)
└───────────────┬────────────────┘     Else prints specific missing component.
                │
                ▼
┌────────────────────────────────┐
│    [ EXIT FORM THE PROGRAM ]   │  ◄── Prints exit borders, flushes and returns 0
└────────────────────────────────┘