`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/11/20 09:08:43
// Design Name: 
// Module Name: led
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


module LED(
    input [3: 0] num,
    output reg[7: 0] out
);
    always @ (num)
    begin
        case (num)
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
