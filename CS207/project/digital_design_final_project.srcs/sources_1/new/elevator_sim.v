`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Design Name: 
// Module Name: elevator
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

module elevator_sim();
reg rst = 0;
reg clk = 0;
always #10 clk = ~clk;

reg [2: 0] up;
reg [3: 1] dw;
reg [3: 0] rq;
reg [1: 0] dr_button;
wire [1: 0] floor;
wire [1: 0] state;
wire [1: 0] dr;
wire [3: 0] process_ten;
wire [3: 0] process_one;
wire timer_clk;
timer tm(rst, clk, timer_clk);

elevator el(
    rst, clk, clk,
    up, dw, rq, dr_button,
    dr, floor, state,
    process_ten, process_one
);

initial
begin
    {up, dw, rq, dr_button} = {3'b000, 3'b000, 4'b0000, 2'b00};
    #10 rst = 1;
    #100
    {up, dw, rq, dr_button} = {3'b000, 3'b000, 4'b0010, 2'b00};
end

endmodule
