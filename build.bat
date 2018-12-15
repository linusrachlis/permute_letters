@echo off
pushd %~dp0%build
cl -nologo /FC -Zi %1
popd
