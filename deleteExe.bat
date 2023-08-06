:: PS: Only for Windows
:: Warning: Don't use this file if you need compiled files!

@echo off
del /s /q *.exe >nul 2>nul
del /s /q *.out >nul 2>nul
del /s /q *.o >nul 2>nul
echo Done
: Run this bat file will delete all compiled 
: files in this directory (include its children
: directory, and children's children directory, and
: so on). You can put it in your C++ working root
: directory, then you can run it to delete all
: compiled files to minimize your disk usage.
