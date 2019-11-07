`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/04/16 15:11:02
// Design Name: 
// Module Name: mux_sim
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


module mux_sim();
    // input
    reg a = 0;
    reg b = 1;
    reg sel = 0;
    //output
    wire q;
    mux mux(.a(a),.b(b),.sel(sel),.q(q));
    initial begin
    # 50 sel = 0; a = 0; b = 0;
    # 50 sel = 0; a = 0; b = 1;
    # 50 sel = 0; a = 1; b = 0;
    # 50 sel = 0; a = 1; b = 1;
    # 50 sel = 1; a = 0; b = 0;
    # 50 sel = 1; a = 0; b = 1;
    # 50 sel = 1; a = 1; b = 0;
    # 50 sel = 1; a = 1; b = 1;
    end
endmodule
