`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Design Name: 
// Module Name: button
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


module button_sim();

reg [2: 0] up_button = 3'b0;
reg [3: 1] dw_button = 3'b0;
reg [3: 0] rq_button = 4'b0;
reg [2: 0] dr_button = 2'b0;
reg [1: 0] state;
reg [1: 0] floor;
wire [2: 0] up;
wire [3: 1] dw;
wire [3: 0] rq;
wire [1: 0] dr; 
reg clk = 1'b0;
reg rst = 1'b0;
button u(
    clk, rst, 
    up_button, dw_button, rq_button, dr_button,
    state, floor,
    up, dw, rq, dr    
);
always #10 clk = ~clk;
initial
begin
    #10 rst = 1'b1;
    $display("qwq");
    #10 rst = 1'b0;
    $display("qwq");
    #10 rst = 1'b1;
    $display("qwq");
    #100 up_button[2] = 1;
end
endmodule
