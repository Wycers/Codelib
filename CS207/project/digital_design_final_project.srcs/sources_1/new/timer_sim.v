`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Design Name: 
// Module Name: timer_sim
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

`include "constant.vh"

module timer_sim();
reg clk;
reg rst = 0;
wire clk_;

timer tm(rst, clk, clk_);

always #10 clk = ~clk;

initial
begin
    clk = 0;
    #10 rst = 1;
end
endmodule