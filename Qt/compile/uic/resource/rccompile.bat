@echo off
echo=
echo ---compile *.qrc to source qrc_*.cpp---
rcc resource.qrc -o qrc_resource.cpp
echo ---ui compile end---