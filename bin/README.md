## 说明

fluffos v2017版，可在LIB中建`driver.cmd`驱动：

```
@echo off
set FLUFFOS="C:\cygwin64\home\Administrator\driver\driver.exe"
%FLUFFOS% driver.ini %*
pause
```