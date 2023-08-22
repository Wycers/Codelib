`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/10/02 14:28:29
// Design Name: 
// Module Name: Lab2_addition
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


module Lab2_Addition(addend, augend, addend_led, augend_led, sum_led);
    input [1:0] addend, augend;
    output [1:0] addend_led, augend_led;
    output [2:0] sum_led;
    assign addend_led = addend, augend_led = augend;
    assign sum_led = addend + augend;
endmodule
