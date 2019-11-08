`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/04/23 05:24:29
// Design Name: 
// Module Name: mul
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


module mul(
    input rst,
    input clk,
    input [15: 0] a,
    input [15: 0] b,
    output reg sign,
    output reg [31: 0] res
);
    integer now;
    reg [15: 0] ta;
    reg [15: 0] tb;
    reg tmpc;
    reg [15: 0] tmp;
    always @ (posedge clk or negedge rst)
    begin
        ta = a;
        if (a[15])
            ta = ~a + 1;
        tb = b;
        if (b[15])
            tb = ~b + 1;
        sign = a[15] ^ b[15];
        if(!rst)
        begin
            sign <= 1'b0;
            tmpc <= 1'b0;
            res <= 32'b0;
            tmp <= 16'b0;
            now = 0;
        end
        else
        begin
            if (now < 16)
            begin
                $display("run %d %d", tmp, ta);
                if (tb[now] == 1'b1)
                    { tmpc, tmp } = tmp + ta;
                $display("run %d %d %d!!", now, tmpc, tmp[0]);
                res[now] = tmp[0];
                tmp = { tmpc, tmp[15: 1] };
                $display("run x %d", tmp);
            end
            else
            if(now == 16)
            begin
                res[30: 16] <= tmp[14: 0];
                if (sign == 1'b1)
                    res <= ~(res - 1);
            end
            now = (now + 1);
        end
    end
endmodule
