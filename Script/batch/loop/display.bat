@echo off & setlocal
rem ��ӡ1-20֮����ż��

setlocal EnableDelayedExpansion
for /l %%i in (1,1,20) do (
	set /a var=%%i %% 2
	if !var! == 0 (
		echo %%i is even number
	) else (
		echo %%i is uneven number
	)
)