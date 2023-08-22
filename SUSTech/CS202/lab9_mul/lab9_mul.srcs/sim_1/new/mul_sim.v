`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/04/23 07:29:47
// Design Name: 
// Module Name: mul_sim
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


module mul_sim(

    );
    reg rst = 0;
    reg clk = 0;
    reg [15: 0] a;
    reg [15: 0] b;
    wire [31: 0] res;
    wire sign;
    initial
    begin
        a = 16'b1111111111110001;
        b = 4'b1111;
        rst = 1'b0; #20 rst = 1'b1;
        clk = 1'b0; forever #5 clk = ~clk;
    end
    mul mul(rst, clk, a, b, sign, res);
    
endmodule
