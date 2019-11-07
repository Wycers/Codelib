`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/04/29 00:33:55
// Design Name: 
// Module Name: div_sim
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


module div_sim(

    );
    reg rst = 0;
    reg clk = 0;
    reg [7: 0] a;
    reg [3: 0] b;
    wire busy;
    wire [7: 0] r;
    wire [7: 0] q;
    initial
    begin
        a = 8'b00000110;
        b = 4'b0011;
        rst = 1'b0; #20 rst = 1'b1;
        clk = 1'b0; forever #5 clk = ~clk;
    end
    div div(rst, clk, a, b, busy, r, q);
    
endmodule
