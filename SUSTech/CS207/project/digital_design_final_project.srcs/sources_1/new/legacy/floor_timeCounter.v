`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Design Name: 
// Module Name: floor_timeCounter
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


module floor_timeCounter(
    input en,                 // enable signal, 1 is effective
    input rst_n,              // reset signal, 0 is effective
    input clk,
    input [10:0] total_time,  // count to that time
    output reg finish             // 0--still count, 1--counting finished
    );
    
    reg [10:0] cur_time;      // current counted time
    wire floor_clk;           // 1 seconds, 50%   (0.5 second high, 0.5 second low)
    frequency_divider fd(rst_n, clk, floor_clk);
    
    always @(posedge floor_clk, negedge rst_n, negedge en)
    begin
        if (~en || ~rst_n) 
        begin
            cur_time <= 0;
            finish <= 0;
        end
        else if (cur_time == total_time) 
        begin
            finish <= 1;
            cur_time <= 0;
        end
        else 
        begin
            finish <= 0;
            cur_time <= cur_time + 1;     
        end
    end   
endmodule
