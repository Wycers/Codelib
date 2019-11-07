`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/12/04 12:56:03
// Design Name: 
// Module Name: d_ff
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


module d_ff(output reg Q, Qn, input D, clk, rst_n);
    always @ (posedge clk, negedge rst_n)
    begin
        if (!rst_n)
        begin
            Q <= 1'b0;
            Qn <= 1'b1;
        end
        else
        begin
            Q <= D;
            Qn <= ~D;
        end
    end
endmodule
