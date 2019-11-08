vlib questa_lib/work
vlib questa_lib/msim

vlib questa_lib/msim/xil_defaultlib

vmap xil_defaultlib questa_lib/msim/xil_defaultlib

vlog -work xil_defaultlib -64 \
"../../../bd/mux/sim/mux.v" \
"../../../bd/mux/ipshared/2bc0/not_gate.v" \
"../../../bd/mux/ip/mux_NOT_GATE_0_0_1/sim/mux_NOT_GATE_0_0.v" \
"../../../bd/mux/ipshared/aa0d/and_gate.v" \
"../../../bd/mux/ip/mux_AND_GATE_0_1_2/sim/mux_AND_GATE_0_1.v" \
"../../../bd/mux/ip/mux_AND_GATE_1_0_1/sim/mux_AND_GATE_1_0.v" \
"../../../bd/mux/ipshared/dd31/nor_gate.v" \
"../../../bd/mux/ip/mux_OR_GATE_0_0/sim/mux_OR_GATE_0_0.v" \


vlog -work xil_defaultlib \
"glbl.v"

