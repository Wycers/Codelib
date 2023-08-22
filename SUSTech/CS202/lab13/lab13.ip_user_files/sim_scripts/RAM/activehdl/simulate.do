onbreak {quit -force}
onerror {quit -force}

asim -t 1ps +access +r +m+RAM -L blk_mem_gen_v8_4_1 -L xil_defaultlib -L unisims_ver -L unimacro_ver -L secureip -O5 xil_defaultlib.RAM xil_defaultlib.glbl

do {wave.do}

view wave
view structure

do {RAM.udo}

run -all

endsim

quit -force
