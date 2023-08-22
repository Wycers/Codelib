`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/12/04 22:23:10
// Design Name: 
// Module Name: jk_ff_sim
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


module jk_ff_sim(); 
reg clk, j, k, rst; 
wire Q; 
jk_ff u(Q, j, k, clk, rst); 
always #5 clk = ~clk; 
initial begin 
    clk = 0; 
    #2 rst = 1; 
    #8 rst = 0;
    {j, k} = 2'b00;
    #10 {j, k} = 2'b01;
    #10 {j, k} = 2'b10;
    #10 {j, k} = 2'b11;
    #40 $finish(1); 
end 
endmodule