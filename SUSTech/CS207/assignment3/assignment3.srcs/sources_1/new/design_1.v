`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/11/15 16:48:00
// Design Name: 
// Module Name: design_1
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

module design_1(
    input [15:0] in,
    output reg[3:0] out
);
    reg [3: 0] res;
    reg [3: 0] i;
    
    always @ (in) 
    begin
        i = 4'b1111;
        while (i > 4'b0000)
        begin
            if (in[i] == 1)
                res = i;
            i = i - 1;
        end
        if (in[i] == 1)
            res = i;
        LED led(.num(res), .out(out))
    end 
endmodule
