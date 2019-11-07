`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Design Name: 
// Module Name: button
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

module display_sim();
reg clk;
reg rst = 0;
reg [1: 0] state;
reg [7: 0] doorstate;
reg [1: 0] floor;
wire [7: 0] DIG;
wire [7: 0] Y;

display dp(rst, clk, state, floor, doorstate, DIG, Y);

always #10 clk = ~clk;

initial
begin
    clk = 0;
    #1      rst = 1;
    #2      {state, doorstate, floor} = 12'b010011010011;
    #400    {state, doorstate, floor} = 12'b100011100010;
end
endmodule