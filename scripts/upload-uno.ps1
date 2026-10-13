param(
    [string]$Port = "COM4",
    [string]$Sketch = (Join-Path $PSScriptRoot "..\code\s03_joystick")
)

$cli = "C:\Program Files\Arduino CLI\arduino-cli.exe"
if (-not (Test-Path $cli)) {
    $found = Get-Command arduino-cli -ErrorAction SilentlyContinue
    if (-not $found) {
        throw "arduino-cli not found. Install with: winget install ArduinoSA.CLI"
    }
    $cli = $found.Source
}

$fqbn = "arduino:avr:uno"
Write-Host "Compiling $Sketch for Uno..."
& $cli compile --fqbn $fqbn $Sketch
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

Write-Host "Uploading to $Port..."
& $cli upload -p $Port --fqbn $fqbn $Sketch
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

Write-Host "Done. Serial Monitor: `"$cli`" monitor -p $Port -c baudrate=115200"
