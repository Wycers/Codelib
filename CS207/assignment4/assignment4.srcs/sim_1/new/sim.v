`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/12/04 13:31:05
// Design Name: 
// Module Name: sim
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


module sim();
reg clk, T, rst_n; 
wire Q, Qn; 
t_ff g(Q, Qn, T, clk, rst_n); 
always #5 clk = ~clk; 
always #10 T = ~T; 
initial
begin
    clk = 1'b0; 
    T = 1'b0; 
    #1 rst_n = 1'b1; 
    #1 rst_n = 1'b0; 
    #1 rst_n = 1'b1;
    #47 $finish(1); 
end 
endmodule
