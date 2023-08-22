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

module elevator(
    input rst,
    input clk,
    input clk_,
    input [2: 0] up,
    input [3: 1] dw,
    input [3: 0] rq,
    input [1: 0] dr_button,
    output reg [1: 0] dr,
    output reg [1: 0] floor,
    output reg [1: 0] state,
    output reg [3: 0] step,
    output reg alarm_en,
    output reg [3: 0] process_ten,
    output reg [3: 0] process_one
);
// ================================================
// ================================================
// target
reg [1: 0] target;
always @ (posedge clk, negedge rst)
if (~rst)
begin
    target <= `FLOOR_1;
end
else
begin
    if (state == `STATE_PAUSE)
    begin
        if (step == 4'd9)
            target <= `FLOOR_1;
            
        if (dw[`FLOOR_4] == `ON)
            target <= `FLOOR_4;
        else if (up[`FLOOR_3] == `ON)
            target <= `FLOOR_3;
        else if (up[`FLOOR_2] == `ON)
            target <= `FLOOR_2;
        else if (up[`FLOOR_1] == `ON)
            target <= `FLOOR_1;
            
        if (up[`FLOOR_1] == `ON)
            target <= `FLOOR_1;
        else if (dw[`FLOOR_2] == `ON)
            target <= `FLOOR_2;
        else if (dw[`FLOOR_3] == `ON)
            target <= `FLOOR_3;
        else if (dw[`FLOOR_4] == `ON)
            target <= `FLOOR_4;

        if (rq[`FLOOR_1] == `ON )
            target <= `FLOOR_1;
        else if (rq[`FLOOR_2] == `ON )
            target <= `FLOOR_2;
        else if (rq[`FLOOR_3] == `ON )
            target <= `FLOOR_3;
        else if (rq[`FLOOR_4] == `ON )
            target <= `FLOOR_4;
    end
    else if (state == `STATE_UP)
    begin
        if (dw[`FLOOR_4] == `ON && target <= `FLOOR_4)
            target <= `FLOOR_4;
        else if (up[`FLOOR_3] == `ON && target <= `FLOOR_3)
            target <= `FLOOR_3;
        else if (up[`FLOOR_2] == `ON && target <= `FLOOR_2)
            target <= `FLOOR_2;
        else if (up[`FLOOR_1] == `ON && target <= `FLOOR_1)
            target <= `FLOOR_1;
            
        if (rq[`FLOOR_4] == `ON && target <= `FLOOR_4)
            target <= `FLOOR_4;
        else if (rq[`FLOOR_3] == `ON && target <= `FLOOR_3)
            target <= `FLOOR_3;
        else if (rq[`FLOOR_2] == `ON && target <= `FLOOR_2)
            target <= `FLOOR_2;
        else if (rq[`FLOOR_1] == `ON && target <= `FLOOR_1)
            target <= `FLOOR_1;
    end
    else if (state == `STATE_DOWN)
    begin
        if (up[`FLOOR_1] == `ON && target >= `FLOOR_1)
            target <= `FLOOR_1;
        else if (dw[`FLOOR_2] == `ON && target >= `FLOOR_2)
            target <= `FLOOR_2;
        else if (dw[`FLOOR_3] == `ON && target >= `FLOOR_3)
            target <= `FLOOR_3;
        else if (dw[`FLOOR_4] == `ON && target >= `FLOOR_4)
            target <= `FLOOR_4;

        
        if (rq[`FLOOR_1] == `ON && target >= `FLOOR_1)
            target <= `FLOOR_1;
        else if (rq[`FLOOR_2] == `ON && target >= `FLOOR_2)
            target <= `FLOOR_2;
        else if (rq[`FLOOR_3] == `ON && target >= `FLOOR_3)
            target <= `FLOOR_3;
        else if (rq[`FLOOR_4] == `ON && target >= `FLOOR_4)
            target <= `FLOOR_4;
    end
end
// ================================================

always @ (posedge clk, negedge rst)
if (~rst)
    state <= `STATE_RST;
else
case (state)
    `STATE_RST:     state <= `STATE_PAUSE;
    `STATE_PAUSE:   begin
                        if (floor > target)
                            state <= `STATE_DOWN;
                        else if (floor < target)
                            state <= `STATE_UP;
                    end
    `STATE_UP:      begin
                        if (floor == target)
                            state <= `STATE_PAUSE;
                    end
   
    `STATE_DOWN:    begin
                        if (floor == target)
                            state <= `STATE_PAUSE;
                    end
endcase
    

// ================================================
// open and close
reg [1: 0] dr_flag;
always @ (posedge clk, negedge rst)
if (~rst)
begin
    dr_flag[1] <= `FALSE;
end
else
begin
    if ((step == 4'd0 || step == 4'd3) && dr_flag[1] != dr_button[1])
        dr[1] <= `ON;
    if (step == 4'd1)
        dr[1] <= `OFF;
    dr_flag[1] <= dr_button[1];
end
always @ (posedge clk, negedge rst)
if (~rst)
begin
    dr_flag[0] <= `FALSE;
end
else
begin
    if (step == 4'd2 && dr_flag[0] != dr_button[0])
        dr[0] <= `ON;
    if (step == 4'd3)
        dr[0] <= `OFF;
    dr_flag[0] <= dr_button[0];
end

// main process
reg [7: 0] tmp;
always @ (posedge clk_, negedge rst)
if (~rst)
begin
    process_ten <= 0;
    process_one <= 0;
    step <= 4'd0;
    tmp <= 0;
    floor <= `FLOOR_1;
    alarm_en <= `OFF;
end
else
begin
case (step)

    // wait for requests
    4'd0:   begin
                if (floor != `FLOOR_1)
                begin
                    if (state == `STATE_PAUSE)
                    begin
                        tmp = tmp + 8'd1;           // 10s
                        if (tmp == 8'd100)
                        begin
                            tmp <= 0;
                            step <= 4'd9;
                        end 
                    end
                end
                if (state == `STATE_UP || state == `STATE_DOWN)
                begin   
                    tmp <= 0;
                    step <= 4'd4;
                end
                if (rq[floor] == `ON || dr[1] == `ON)
                begin
                    tmp <= 0;
                    step <= 4'd8;
                end
                else
                case (floor)
                    `FLOOR_4:   if (dw[`FLOOR_4] == `ON)
                                begin
                                    step <= 4'd8;
                                    tmp <= 0;
                                end
                    `FLOOR_1:   if (up[`FLOOR_1] == `ON)
                                begin
                                    step <= 4'd8;
                                    tmp <= 0;
                                end
                    default:    if (dw[floor] == `ON || up[floor] == `ON)
                                begin
                                    step <= 4'd8;
                                    tmp <= 0;
                                end
                endcase
            end
    // open the door
    4'd1:   begin
                process_one = process_one + 4'd2;
                if (process_one == 4'd10)
                begin
                    process_ten = process_ten + 1'd1;
                    process_one = 4'd0;
                    if (process_ten == 4'd2)
                        alarm_en <= `OFF;
                end
                if (process_ten == 4'd10)
                    step <= 4'd2;
                // tmp = tmp + 8'd2;
                // if (tmp == 8'd100)
                // begin
                //     tmp <= 8'b0;
                //     step <= 4'd2;
                // end
            end 
    // hold the door
    4'd2:   begin
                tmp = tmp + 8'd2;
                if (dr[0] == `TRUE || tmp == 8'd100)
                begin
                    tmp <= 0;
                    step <= 4'd3;
                end 
                
                // process_one = process_one + 4'd2;
                // if (process_one == 4'd10)
                // begin
                //     process_ten = process_ten + 1'd1;
                //     process_one = 4'd0;
                // end
                // if (dr[0] == `TRUE || { process_ten, process_one} == 8'b10100000)
                // begin
                //     { process_ten, process_one} <= 8'b00000000;
                //     step <= 4'd4;
                // end 
            end
    // close the door
    4'd3:   begin
                if (dr[1] == `TRUE)
                    step <= 4'd1;
                else
                begin
                    // tmp = tmp - 8'd2;
                    // if (tmp == 8'd0)
                    //     step <= 4'd7;

                    if (process_one == 4'd0)
                    begin
                        if (process_ten > 4'd0)
                        begin
                            process_ten = process_ten - 1'd1;
                            process_one = process_one + 4'd10;
                        end
                    end
                    if (process_one > 4'd0)
                        process_one = process_one - 4'd2;
                    else
                        step <= 4'd7;
                end
            end
    // move from floor to floor
    4'd4:   begin
                tmp = tmp + 8'd2;
                if (tmp == 100)
                begin
                    tmp <= 0;
                    step <= 4'd5;
                end
            end
    //  arrive
    4'd5:   begin
                if (state == `STATE_DOWN)
                    floor <= floor - 2'd1;
                else if (state == `STATE_UP)
                    floor <= floor + 2'd1;
                step <= 4'd6;
            end
    //  whether to open the door
    4'd6:   begin
                if (state == `STATE_UP        && (up[floor] == `ON || rq[floor] == `ON))
                    step <= 4'd8;
                else if (state == `STATE_DOWN && (dw[floor] == `ON || rq[floor] == `ON))
                    step <= 4'd8;
                else
                    step <= 4'd7;
            end
    //  whether to move
    4'd7:   begin
                if (floor == target)
                    step <= 4'd0;
                else
                    step <= 4'd4;
            end
    //  clear and open
    4'd8:   begin
                tmp = tmp + 8'd10;
                if (tmp == 8'd100)
                begin
                    tmp <= 0;
                    step <= 4'd1;
                    alarm_en <= `ON;
                end
            end
    //  back to floor_1
    4'd9:   begin
                step <= 4'd4;
            end
endcase
$display("%d %d %d", step, tmp, target);
end
endmodule
