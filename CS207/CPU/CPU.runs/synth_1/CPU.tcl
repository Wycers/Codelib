# 
# Synthesis run script generated by Vivado
# 

proc create_report { reportName command } {
  set status "."
  append status $reportName ".fail"
  if { [file exists $status] } {
    eval file delete [glob $status]
  }
  send_msg_id runtcl-4 info "Executing : $command"
  set retval [eval catch { $command } msg]
  if { $retval != 0 } {
    set fp [open $status w]
    close $fp
    send_msg_id runtcl-5 warning "$msg"
  }
}
set_param xicom.use_bs_reader 1
create_project -in_memory -part xc7a100tfgg484-1

set_param project.singleFileAddWarning.threshold 0
set_param project.compositeFile.enableAutoGeneration 0
set_param synth.vivado.isSynthRun true
set_msg_config -source 4 -id {IP_Flow 19-2162} -severity warning -new_severity info
set_property webtalk.parent_dir D:/Desktop/CPU/CPU.cache/wt [current_project]
set_property parent.project_path D:/Desktop/CPU/CPU.xpr [current_project]
set_property XPM_LIBRARIES {XPM_CDC XPM_MEMORY} [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language Verilog [current_project]
set_property ip_output_repo d:/Desktop/CPU/CPU.cache/ip [current_project]
set_property ip_cache_permissions {read write} [current_project]
add_files D:/Desktop/CPU/CPU.srcs/sources_1/ip/prgrom/prgmip32.coe
add_files D:/Desktop/CPU/CPU.srcs/sources_1/ip/RAM/dmem32.coe
add_files D:/Desktop/CPU/testcase1/dmem32.coe
add_files D:/Desktop/CPU/testcase1/prgmip32.coe
add_files D:/Desktop/CPU/output/prgmip32.coe
add_files D:/Desktop/CPU/output/dmem32.coe
read_verilog -library xil_defaultlib -sv {
  D:/Desktop/CPU/CPU.srcs/sources_1/new/Idecode32.v
  D:/Desktop/CPU/CPU.srcs/sources_1/new/CPU.v
}
read_verilog -library xil_defaultlib {
  D:/Desktop/CPU/CPU.srcs/sources_1/new/Executs32.v
  D:/Desktop/CPU/CPU.srcs/sources_1/new/control32.v
  D:/Desktop/CPU/CPU.srcs/sources_1/new/dmemory32.v
  D:/Desktop/CPU/CPU.srcs/sources_1/new/ioread.v
  D:/Desktop/CPU/CPU.srcs/sources_1/new/leds.v
  D:/Desktop/CPU/CPU.srcs/sources_1/new/lfetc32.v
  D:/Desktop/CPU/CPU.srcs/sources_1/new/memio.v
  D:/Desktop/CPU/CPU.srcs/sources_1/new/memorio.v
  D:/Desktop/CPU/CPU.srcs/sources_1/new/switchs.v
}
read_ip -quiet D:/Desktop/CPU/CPU.srcs/sources_1/ip/RAM/RAM.xci
set_property used_in_implementation false [get_files -all d:/Desktop/CPU/CPU.srcs/sources_1/ip/RAM/RAM_ooc.xdc]

read_ip -quiet D:/Desktop/CPU/CPU.srcs/sources_1/ip/cpuclk/cpuclk.xci
set_property used_in_implementation false [get_files -all d:/Desktop/CPU/CPU.srcs/sources_1/ip/cpuclk/cpuclk_board.xdc]
set_property used_in_implementation false [get_files -all d:/Desktop/CPU/CPU.srcs/sources_1/ip/cpuclk/cpuclk.xdc]
set_property used_in_implementation false [get_files -all d:/Desktop/CPU/CPU.srcs/sources_1/ip/cpuclk/cpuclk_ooc.xdc]

read_ip -quiet D:/Desktop/CPU/CPU.srcs/sources_1/ip/prgrom/prgrom.xci
set_property used_in_implementation false [get_files -all d:/Desktop/CPU/CPU.srcs/sources_1/ip/prgrom/prgrom_ooc.xdc]

# Mark all dcp files as not used in implementation to prevent them from being
# stitched into the results of this synthesis run. Any black boxes in the
# design are intentionally left as such for best results. Dcp files will be
# stitched into the design at a later time, either when this synthesis run is
# opened, or when it is stitched into a dependent implementation run.
foreach dcp [get_files -quiet -all -filter file_type=="Design\ Checkpoint"] {
  set_property used_in_implementation false $dcp
}
read_xdc D:/Desktop/CPU/CPU.srcs/constrs_1/new/233.xdc
set_property used_in_implementation false [get_files D:/Desktop/CPU/CPU.srcs/constrs_1/new/233.xdc]

read_xdc dont_touch.xdc
set_property used_in_implementation false [get_files dont_touch.xdc]

synth_design -top CPU -part xc7a100tfgg484-1


# disable binary constraint mode for synth run checkpoints
set_param constraints.enableBinaryConstraints false
write_checkpoint -force -noxdef CPU.dcp
create_report "synth_1_synth_report_utilization_0" "report_utilization -file CPU_utilization_synth.rpt -pb CPU_utilization_synth.pb"
