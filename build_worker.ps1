# ============================================================
#  Incremental build script for Worker Management System
#  - only recompiles .cpp files that changed (cached .o files)
#  - links all .o files into build/Debug/outDebug.exe
#  - uses 8.3 short path (d:/vscoding/基于多~1) to avoid
#    Chinese-char encoding issues in cmd/PowerShell
# ============================================================
$ErrorActionPreference = "Stop"

$gpp      = "D:/mingw64/bin/g++.exe"
$projDir  = "d:/vscoding/基于多~1"          # short path of Chinese project dir
$buildDir = "d:/vscoding/build/Debug"
$exe      = "$buildDir/outDebug.exe"
$common   = "d:/vscoding/C++/common.h"

$flags = @(
    "-Wall",
    "-Wextra",
    "-Wpedantic",
    "-Wformat=2",
    "-g3",
    "-O0",
    "-include", $common
)

New-Item -ItemType Directory -Force -Path $buildDir | Out-Null

# collect all .cpp files in the project dir (workManger.cpp, 职工管理系统.cpp)
$sources = Get-ChildItem -Path $projDir -Filter "*.cpp" -File
$objs    = @()
$needLink = $false

# newest header file - if a header changed, force full rebuild
# (project .h files + the forced-include common.h in workspace root)
$headers = @(Get-ChildItem -Path $projDir -Filter "*.h" -File)
$headers += Get-Item -Path "d:/vscoding/C++/common.h" -ErrorAction SilentlyContinue
$newestHeader = $headers | Where-Object { $_ } |
    Sort-Object LastWriteTime -Descending | Select-Object -First 1

foreach ($src in $sources) {
    $objPath = Join-Path $buildDir ($src.BaseName + ".o")
    $objs += $objPath

    $needCompile = $true
    if (Test-Path $objPath) {
        $objTime = (Get-Item $objPath).LastWriteTime
        $srcNewer   = $src.LastWriteTime -gt $objTime
        $hdrNewer   = ($newestHeader -and $newestHeader.LastWriteTime -gt $objTime)
        $needCompile = $srcNewer -or $hdrNewer
    }

    if ($needCompile) {
        Write-Host "[build] compiling $($src.Name) ..."
        & $gpp $flags -c $src.FullName -o $objPath
        if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
        $needLink = $true
    } else {
        Write-Host "[build] unchanged, skip $($src.Name)"
    }
}

# link if: something was recompiled, exe is missing, or any .o is newer than exe
$exeExists = Test-Path $exe
$exeStale  = $false
if ($exeExists) {
    $exeTime = (Get-Item $exe).LastWriteTime
    foreach ($obj in $objs) {
        if ((Get-Item $obj).LastWriteTime -gt $exeTime) {
            $exeStale = $true
            break
        }
    }
}

if ($needLink -or -not $exeExists -or $exeStale) {
    Write-Host "[build] linking ..."
    & $gpp $objs -o $exe
    if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
}

Write-Host "[build] done: $exe"
