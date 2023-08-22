vlib work
vlib activehdl

vlib activehdl/xil_defaultlib
vlib activehdl/xpm

vmap xil_defaultlib activehdl/xil_defaultlib
vmap xpm activehdl/xpm

vlog -work xil_defaultlib  -sv2k12 "+incdir+../../../ipstatic" "+incdir+E:/vivado/Vivado/2017.4/data/xilinx_vip/include" "+incdir+../../../ipstatic" "+incdir+E:/vivado/Vivado/2017.4/data/xilinx_vip/include" \
"E:/vivado/Vivado/2017.4/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
"E:/vivado/Vivado/2017.4/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \

vcom -work xpm -93 \
"E:/vivado/Vivado/2017.4/data/ip/xpm/xpm_VCOMP.vhd" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../ipstatic" "+incdir+E:/vivado/Vivado/2017.4/data/xilinx_vip/include" "+incdir+../../../ipstatic" "+incdir+E:/vivado/Vivado/2017.4/data/xilinx_vip/include" \
"../../../../CPU.srcs/sources_1/ip/cpuclk/cpuclk_clk_wiz.v" \
"../../../../CPU.srcs/sources_1/ip/cpuclk/cpuclk.v" \

vlog -work xil_defaultlib \
"glbl.v"

