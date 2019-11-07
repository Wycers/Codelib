`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/04/16 22:49:34
// Design Name: 
// Module Name: addsub
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


module addsub
#(parameter WIDTH = 8)
(
    input [(WIDTH-1) : 0] a,
    input [(WIDTH-1) : 0] b,
    input sub,
    output reg [(WIDTH-1):0] sum,
    output reg cf, 
    output reg of,
    output reg sf, 
    output reg zf
);
    reg [WIDTH : 0] tmp;
    always @ *
    begin
        if (sub == 1'b0)
        begin
            tmp = a + b;
            if (tmp[WIDTH - 1: 0] == 1'b0)
                zf = 1'b1;
            else
                zf = 1'b0;
                
            cf = tmp[WIDTH];
            sum = tmp[WIDTH - 1 : 0];
            if(a[WIDTH - 1] == b[WIDTH - 1] && b[WIDTH - 1] == !sum[WIDTH - 1]) 
                of = 1'b1;
            else
                of = 1'b0;
        end
        else
        begin
            tmp = a + {0, (~b) + 1};
            if(tmp[WIDTH - 1 : 0] == 1'b0)
                zf = 1'b1;
            else 
                zf = 1'b0;
                
            cf = ~tmp[WIDTH];
            sum = tmp[WIDTH - 1 : 0];
            
            if(!a[WIDTH - 1] == b[WIDTH - 1] && b[WIDTH - 1] == sum[WIDTH - 1]) 
                of = 1'b1;
            else
                of = 1'b0;
        end
        sf = sum[WIDTH - 1];
    end     
endmodule