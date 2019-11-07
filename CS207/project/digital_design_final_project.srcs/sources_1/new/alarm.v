module alarm(
    input rst,
    input clk, 
    input en,
    output reg beep
);
    
reg [24:0] counter;
reg [14:0] delay_cnt;
wire [14:0] delay_end;

parameter freq1 = 56817;
parameter freq2 = 28408;
assign delay_end = counter ? freq1 : freq2;

always @ (posedge clk, posedge en, negedge rst)
if(~rst || ~en)
    counter <= 25'b0;
else 
    counter <= counter + 1;

always @ (posedge clk, posedge en, negedge rst)
if(~rst || ~en)
begin
    delay_cnt <= delay_end;
    if (beep)
        beep <= ~beep;
end
else if (delay_cnt == 15'd0)
    begin
        beep <= ~beep;
        delay_cnt = delay_end;
    end
else
    delay_cnt <= delay_cnt - 1'b1;    
endmodule