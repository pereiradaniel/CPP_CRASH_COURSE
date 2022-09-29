# DEBUGGER NOTES

---

## GNU Project Debugger (GDB)

[https://www.sourceware.org/gdb/](https://www.sourceware.org/gdb/)

Add the *-g* flag to command line.

## Low Level Debugger (LLDB)

[https://lldb.llvm.org/](https://lldb.llvm.org/)

Used with Clang.

## USE GDB

### **Step1**

Compile program with debug support:

```bash
g++ step_function_printf.cpp -o stepfun -g
```

### **Step2**

Debug using GDB

```bash
gdb stepfun
```

### **Step3**

Insert a breakpoint using break:

```bash
break main.cpp:5
```

### **Step4**

Insert a breakpoint using function name:

```bash
break main
```

### **Step5**

Execute program

```bash
run
```

### **Step6**

Step into an instruction

```bash
step
```

### **Step7**

To continue stepping, press ENTER to repeat the last command.

### **Step8**

Step back out of a function using *finish*.

```bash
finish
```

### **Step9**

Execute an instruction without stepping into a funtion call using *next*.

```bash
next
```

### **Step10**

Inspect current value of variables using *info locals*.

```bash
info locals
```

### **Step11**

Continue execution until next breakpoint or end of program using *continue*.

```bash
continue
```

### **Step12**

Use quit at anytime to exit *GDB*.

```bash
quit
```
