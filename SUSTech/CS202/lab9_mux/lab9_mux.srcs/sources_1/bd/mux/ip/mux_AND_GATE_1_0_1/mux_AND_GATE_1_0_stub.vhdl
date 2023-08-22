-- Copyright 1986-2017 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2017.4 (win64) Build 2086221 Fri Dec 15 20:55:39 MST 2017
-- Date        : Wed Apr 17 09:21:12 2019
-- Host        : Wycer running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode synth_stub -rename_top mux_AND_GATE_1_0 -prefix
--               mux_AND_GATE_1_0_ mux_AND_GATE_0_1_stub.vhdl
-- Design      : mux_AND_GATE_0_1
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7a100tfgg484-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity mux_AND_GATE_1_0 is
  Port ( 
    a : in STD_LOGIC_VECTOR ( 0 to 0 );
    b : in STD_LOGIC_VECTOR ( 0 to 0 );
    q : out STD_LOGIC_VECTOR ( 0 to 0 )
  );

end mux_AND_GATE_1_0;

architecture stub of mux_AND_GATE_1_0 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "a[0:0],b[0:0],q[0:0]";
attribute X_CORE_INFO : string;
attribute X_CORE_INFO of stub : architecture is "and_gate,Vivado 2017.4";
begin
end;
