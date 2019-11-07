`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/12/04 22:39:56
// Design Name: 
// Module Name: task3_sim
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


module task3_sim();
reg clk, x_in, rst_n; 
wire A, B, An, Bn; 
task3 g(A, B, An, Bn, x_in, clk, rst_n); 
always #10 clk = ~clk; 
always #20 x_in = ~x_in; 
initial begin 
    clk = 1'b0; 
    x_in = 1'b0; 
    rst_n = 1'b0;
    #2 rst_n = ~rst_n;
    #2 rst_n = ~rst_n; 
    #2 rst_n = ~rst_n; 
end 
endmodule 
