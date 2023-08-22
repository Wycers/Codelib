`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Design Name: 
// Module Name: main
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

module main(
    input rst,
    input clk,
    input [2: 0] up_button,
    input [3: 1] dw_button,
    input [3: 0] rq_button,
    input [1: 0] dr_button,
    output [2: 0] up,
    output [3: 1] dw,
    output [3: 0] rq,
    output [1: 0] dr,
    output [7: 0] dig,
    output [7: 0] tube,
    output beep
);
wire timer_clk;
wire [1: 0] floor;
wire [1: 0] state;
wire [3: 0] process_ten;
wire [3: 0] process_one;
wire [3: 0] step;
wire alarm_en;

// clk
timer tm(rst, clk, timer_clk);

// alarm
alarm am(rst, clk, alarm_en, beep);

// button
button btn(
    rst, clk,
    up_button, dw_button, rq_button,
    state, floor, step,
    up, dw, rq
);

// elevator control
elevator el(
    rst, clk, timer_clk,
    up, dw, rq, dr_button,
    dr, floor, state, step, alarm_en,
    process_ten, process_one
);

// display control
display dp(
    rst, clk,
    state, floor,
    {process_ten, process_one},
    dig, tube
);

endmodule
