onbreak {quit -f}
onerror {quit -f}

vsim -t 1ps -lib xil_defaultlib mux_opt

do {wave.do}

view wave
view structure
view signals

do {mux.udo}

run -all

quit -force
