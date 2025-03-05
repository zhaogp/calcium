# build.ps1
Set-Location build
if (-Not (Test-Path CMakeCache.txt)) {
    cmake -G 'Unix Makefiles' -DCMAKE_BUILD_TYPE=Debug ..
}
make -j4