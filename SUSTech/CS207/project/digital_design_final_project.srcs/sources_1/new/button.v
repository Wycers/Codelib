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

`include "constant.vh"

module button(
    input rst,
    input clk, 
    input [2: 0] up_button,
    input [3: 1] dw_button,
    input [3: 0] rq_button,
    input [1: 0] state,
    input [1: 0] floor,
    input [3: 0] step,
    output reg [2: 0] up = 3'b0,
    output reg [3: 1] dw = 3'b0,
    output reg [3: 0] rq = 4'b0
);
reg [2: 0] up_flag = 3'b0;
reg [3: 1] dw_flag = 3'b0;
reg [3: 0] rq_flag = 4'b0;

// switch signal handler for    up request
always @ (posedge clk, negedge rst)
if (~rst)
begin
    up[`FLOOR_3] <= `OFF;
    up_flag[`FLOOR_3] <= up_button[`FLOOR_3];
end
else
begin
    if (up_flag[`FLOOR_3] != up_button[`FLOOR_3])
        up[`FLOOR_3] <= `ON;
    if (step == 4'd8 && floor == `FLOOR_3 && state != `STATE_DOWN)
        up[`FLOOR_3] <= `OFF;
    up_flag[`FLOOR_3] <= up_button[`FLOOR_3];
end

always @ (posedge clk, negedge rst)
if (~rst)
begin
    up[`FLOOR_2] <= `OFF;
    up_flag[`FLOOR_2] <= up_button[`FLOOR_2];
end
else
begin
    if (up_flag[`FLOOR_2] != up_button[`FLOOR_2])
        up[`FLOOR_2] <= `ON;
    if (step == 4'd8 && floor == `FLOOR_2 && state != `STATE_DOWN)
        up[`FLOOR_2] <= `OFF;
    up_flag[`FLOOR_2] <= up_button[`FLOOR_2];
end

always @ (posedge clk, negedge rst)
if (~rst)
begin
    up[`FLOOR_1] <= `OFF;
    up_flag[`FLOOR_1] <= up_button[`FLOOR_1];
end
else
begin
    if (up_flag[`FLOOR_1] != up_button[`FLOOR_1])
        up[`FLOOR_1] <= `ON;
    if (step == 4'd8 && floor == `FLOOR_1 && state != `STATE_DOWN)
        up[`FLOOR_1] <= `OFF;
    up_flag[`FLOOR_1] <= up_button[`FLOOR_1];
end


// switch signal handler for  down request 
always @ (posedge clk, negedge rst)
if (~rst)
begin
    dw[`FLOOR_4] <= `OFF;
    dw_flag[`FLOOR_4] <= dw_button[`FLOOR_4];
end
else
begin
    if (dw_flag[`FLOOR_4] != dw_button[`FLOOR_4])
        dw[`FLOOR_4] <= `ON;
    if (step == 4'd8 && floor == `FLOOR_4 && state != `STATE_UP)
        dw[`FLOOR_4] <= `OFF;
    dw_flag[`FLOOR_4] <= dw_button[`FLOOR_4];
end

always @ (posedge clk, negedge rst)
if (~rst)
begin
    dw[`FLOOR_3] <= `OFF;
    dw_flag[`FLOOR_3] <= dw_button[`FLOOR_3];
end
else
begin
    if (dw_flag[`FLOOR_3] != dw_button[`FLOOR_3])
        dw[`FLOOR_3] <= `ON;
    if (step == 4'd8 && floor == `FLOOR_3 && state != `STATE_UP)
        dw[`FLOOR_3] <= `OFF;
    dw_flag[`FLOOR_3] <= dw_button[`FLOOR_3];
end

always @ (posedge clk, negedge rst)
if (~rst)
begin
    dw[`FLOOR_2] <= `OFF;
    dw_flag[`FLOOR_2] <= dw_button[`FLOOR_2];
end
else
begin
    if (dw_flag[`FLOOR_2] != dw_button[`FLOOR_2])
        dw[`FLOOR_2] <= `ON;
    if (step == 4'd8 && floor == `FLOOR_2 && state != `STATE_UP)
        dw[`FLOOR_2] <= `OFF;
    dw_flag[`FLOOR_2] <= dw_button[`FLOOR_2];
end



// switch signal handler for floor request 
always @ (posedge clk, negedge rst)
if (~rst)
begin
    rq[`FLOOR_1] <= `OFF;
    rq_flag[`FLOOR_1] <= `FALSE;
end
else
begin
    if (rq_flag[`FLOOR_1] != rq_button[`FLOOR_1])
        rq[`FLOOR_1] <= `ON;
    if (step == 4'd8 && floor == `FLOOR_1)
        rq[`FLOOR_1] <= `OFF;
    rq_flag[`FLOOR_1] <= rq_button[`FLOOR_1];
end

always @ (posedge clk, negedge rst)
if (~rst)
begin
    rq[`FLOOR_2] <= `OFF;
    rq_flag[`FLOOR_2] <= `FALSE;
end
else
begin
    if (rq_flag[`FLOOR_2] != rq_button[`FLOOR_2])
        rq[`FLOOR_2] <= `ON;
    if (step == 4'd8 && floor == `FLOOR_2)
        rq[`FLOOR_2] <= `OFF;
    rq_flag[`FLOOR_2] <= rq_button[`FLOOR_2];
end

always @ (posedge clk, negedge rst)
if (~rst)
begin
    rq[`FLOOR_3] <= `OFF;
    rq_flag[`FLOOR_3] <= `FALSE;
end
else
begin
    if (rq_flag[`FLOOR_3] != rq_button[`FLOOR_3])
        rq[`FLOOR_3] <= `ON;
    if (step == 4'd8 && floor == `FLOOR_3)
        rq[`FLOOR_3] <= `OFF;
    rq_flag[`FLOOR_3] <= rq_button[`FLOOR_3];
end

always @ (posedge clk, negedge rst)
if (~rst)
begin
    rq[`FLOOR_4] <= `OFF;
    rq_flag[`FLOOR_4] <= `FALSE;
end
else
begin
    if (rq_flag[`FLOOR_4] != rq_button[`FLOOR_4])
        rq[`FLOOR_4] <= `ON;
    if (step == 4'd8 && floor == `FLOOR_4)
        rq[`FLOOR_4] <= `OFF;
    rq_flag[`FLOOR_4] <= rq_button[`FLOOR_4];
end

endmodule
