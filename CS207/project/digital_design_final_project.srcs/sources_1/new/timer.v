`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Design Name: 
// Module Name: timer
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

`include "constant.vh"

module timer(
    input rst_n,                // the reset signal, 0 is effective
    input input_clk,            // the original clk from FPGA
    output reg output_clk       // output clk: 0.1s high, 0.1s low
);
reg [30:0] counter;

always @ (posedge input_clk, negedge rst_n) 
begin
    if (~rst_n)
    begin
        counter <= 0;
        output_clk <= 0;
    end
    else
    begin
        if (counter == `TIME_SCALE)
        begin
            output_clk <= ~output_clk;
            counter <= 0;
        end
        else
            counter <= counter + 1;
    end
end
endmodule
