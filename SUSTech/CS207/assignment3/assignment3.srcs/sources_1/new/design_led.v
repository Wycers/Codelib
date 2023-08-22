`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/11/15 17:48:30
// Design Name: 
// Module Name: design_led
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


module design_led(
    input [15:0] in,
    output reg[7:0] out
);
    reg[3:0] res;
    reg[3:0] i;
    always @ (in)
    begin
        for (i = 15; i > 0; i = i - 1 )
            if(in[i] == 1) 
                res = i;
        if (in[0] == 1)
            res = 0;
        $display("%0dns\t\in=%b\tout=%d", $stime, in, res);
        case (res)
            4'h0 : out = 8'b01000000;
            4'h1 : out = 8'b01111001;
            4'h2 : out = 8'b00100100;
            4'h3 : out = 8'b00110000;
            4'h4 : out = 8'b00011001;
            4'h5 : out = 8'b00010010;
            4'h6 : out = 8'b00000010;
            4'h7 : out = 8'b01111000;
            4'h8 : out = 8'b00000000;
            4'h9 : out = 8'b00010000;
            4'ha : out = 8'b00001000;
            4'hb : out = 8'b00000011;
            4'hc : out = 8'b01000110;
            4'hd : out = 8'b00100001;
            4'he : out = 8'b00000110;
            4'hf : out = 8'b00001110;
            default : out = 8'b00000000;
        endcase
    end
endmodule
