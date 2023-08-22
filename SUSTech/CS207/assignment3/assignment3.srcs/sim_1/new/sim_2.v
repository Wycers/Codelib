`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/11/15 20:17:58
// Design Name: 
// Module Name: sim_2
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


module multiplexer_sim();
    reg sa, sb, sc, sd;
    wire q;
    multiplexer XD(.s2(sa), .s1(sb), .s0(sc), .d(sd), .q(q));
    initial 
    begin
        {sa, sb, sc, sd} = 4'h0;
        while({sa, sb, sc, sd} < 4'hf)
            #10 {sa, sb, sc, sd} = {sa, sb, sc, sd} + 1;
        $finish(1);
    end
endmodule
