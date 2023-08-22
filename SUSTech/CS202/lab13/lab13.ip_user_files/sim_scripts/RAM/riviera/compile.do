vlib work
vlib riviera

vlib riviera/blk_mem_gen_v8_4_1
vlib riviera/xil_defaultlib

vmap blk_mem_gen_v8_4_1 riviera/blk_mem_gen_v8_4_1
vmap xil_defaultlib riviera/xil_defaultlib

vlog -work blk_mem_gen_v8_4_1  -v2k5 \
"../../../ipstatic/simulation/blk_mem_gen_v8_4.v" \

vlog -work xil_defaultlib  -v2k5 \
"../../../../lab13.srcs/sources_1/ip/RAM/sim/RAM.v" \


vlog -work xil_defaultlib \
"glbl.v"

