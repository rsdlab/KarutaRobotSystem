@echo off
cd /d %~dp0
setlocal
for %%I in (python.exe) do if exist %%~$path:I set f=%%~$path:I
if exist %f% (
  %f:python.exe=%omniidl.exe -bpython -I"%RTM_ROOT%rtm\idl" -I"/home/rsdlab/workspace/WebCamera/idl" -I"/home/rsdlab/Downloads/py_faster_rcnnRTC/idl" idl/Img.idl idl/BasicDataType.idl idl/ObjectRecognition.idl 
) else (
  echo "python.exe" can not be found.
  echo Please modify PATH environmental variable for python command.
)
endlocal
