-- Copyright 1986-2017 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2017.4 (win64) Build 2086221 Fri Dec 15 20:55:39 MST 2017
-- Date        : Wed Apr 17 09:21:12 2019
-- Host        : Wycer running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode funcsim -rename_top mux_AND_GATE_1_0 -prefix
--               mux_AND_GATE_1_0_ mux_AND_GATE_0_1_sim_netlist.vhdl
-- Design      : mux_AND_GATE_0_1
-- Purpose     : This VHDL netlist is a functional simulation representation of the design and should not be modified or
--               synthesized. This netlist cannot be used for SDF annotated simulation.
-- Device      : xc7a100tfgg484-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity mux_AND_GATE_1_0 is
  port (
    a : in STD_LOGIC_VECTOR ( 0 to 0 );
    b : in STD_LOGIC_VECTOR ( 0 to 0 );
    q : out STD_LOGIC_VECTOR ( 0 to 0 )
  );
  attribute NotValidForBitStream : boolean;
  attribute NotValidForBitStream of mux_AND_GATE_1_0 : entity is true;
  attribute CHECK_LICENSE_TYPE : string;
  attribute CHECK_LICENSE_TYPE of mux_AND_GATE_1_0 : entity is "mux_AND_GATE_0_1,and_gate,{}";
  attribute DowngradeIPIdentifiedWarnings : string;
  attribute DowngradeIPIdentifiedWarnings of mux_AND_GATE_1_0 : entity is "yes";
  attribute X_CORE_INFO : string;
  attribute X_CORE_INFO of mux_AND_GATE_1_0 : entity is "and_gate,Vivado 2017.4";
end mux_AND_GATE_1_0;

architecture STRUCTURE of mux_AND_GATE_1_0 is
begin
\q[0]_INST_0\: unisim.vcomponents.LUT2
    generic map(
      INIT => X"8"
    )
        port map (
      I0 => b(0),
      I1 => a(0),
      O => q(0)
    );
end STRUCTURE;
