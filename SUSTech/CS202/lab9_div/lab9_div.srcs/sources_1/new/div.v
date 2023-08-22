`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/04/29 00:17:26
// Design Name: 
// Module Name: div
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


module div(
    input rst,
    input clk,
    input [7: 0] a,
    input [3: 0] b,
    output reg busy,
    output reg [7: 0] r,
    output reg [7: 0] q
);
    integer now;
    reg sign;
    reg [7: 0] ta;
    reg [3: 0] tb;
    reg [7: 0] tmp;
    reg [7: 0] gg;
    always @ (posedge clk or negedge rst)
    begin
        ta = a;
        if (a[7])
            ta = ~a + 1;
        tb = b;
        if (b[3])
            tb = ~b + 1;
        sign = a[7] ^ b[3];
        if(!rst)
        begin
            sign <= 1'b0;
            r <= 8'b0;
            q <= 8'b0;
            now = 0;
        end
        else
        begin
            if (now == 0)
            begin
                tmp = { tb, 4'b0};
                r = ta;
            end
            if (now != 5)
            begin
                busy = 1'b1;
                gg = r - tmp;
                if (gg[7] == 1'b1)
                    q = { q[6: 0], 1'b0};
                else
                begin
                    q = { q[6: 0], 1'b1};
                    r = gg;
                end
                tmp = { 1'b0, tmp[7: 1] };
                now = now + 1;
            end
            else
            begin
                busy = 1'b0;
            end
        end
    end
endmodule
