module display(
    input rst,
    input clk,
    input [1: 0] state,
    input [1: 0] floor,
    input [7: 0] doorstate,
    output [7: 0] DIG,
    output [7: 0] Y
    //***** try to check scan_cnt
);
parameter period =200000;//flash period
reg [31: 0] cnt;
reg [ 2: 0] scan_cnt;
reg clkout;
reg [6: 0] Y_r;
reg [7: 0] DIG_r;
reg tmp;
assign Y = {1'b1, ~Y_r[6: 0]};
assign DIG = ~DIG_r;
always @(posedge clk or negedge rst)
begin
    if(!rst) begin
        cnt <= 0;
        clkout <= 0;
    end
    else
    begin
        if (cnt == (period >> 1) - 1)
        begin 
            clkout <= ~clkout;
            cnt <= 0;
        end
        else
            cnt <= cnt + 1;
    end
end

always @(posedge clkout or negedge rst)
begin
    if(!rst)
        scan_cnt <= 0;
    else begin
        scan_cnt = scan_cnt + 1;
        //noted*************
        if (scan_cnt == 3'd5) scan_cnt <= 0;
    end
end
always @(scan_cnt)
begin
    case(scan_cnt)
        3'b000 : DIG_r = 8'b0000_0001;       
        3'b001 : DIG_r = 8'b0000_0010;   
        3'b010 : DIG_r = 8'b0001_0000;   
        3'b011 : DIG_r = 8'b0010_0000;   
        3'b100 : DIG_r = 8'b0100_0000;   
        default: DIG_r = 8'b0000_0000; 
    endcase
end
always @(scan_cnt, floor, state, doorstate)
begin
    
    if(scan_cnt == 0)
    begin
        case(floor)
            2'b00 : Y_r = 7'b0000110;
            2'b01 : Y_r = 7'b1011011;
            2'b10 : Y_r = 7'b1001111;
            2'b11 : Y_r = 7'b1100110;
            default:Y_r = 7'b0000000;
        endcase
    end
    else if(scan_cnt == 1)
    begin
        case(state)
            2'b00 :  Y_r = 7'b1001001;
            2'b01 :  Y_r = 7'b1000000; //set by linyou in 1:47
            2'b11 :  Y_r = 7'b1110111;
            2'b10 :  Y_r = 7'b1111110;
            default: Y_r = 7'b0000000; 
        endcase
    end
    else if (scan_cnt == 2)
    begin
        case(doorstate[3:0])
            0 : Y_r = 7'b0111111;
            1 : Y_r = 7'b0000110;
            2 : Y_r = 7'b1011011;
            3 : Y_r = 7'b1001111;
            4 : Y_r = 7'b1100110;
            5 : Y_r = 7'b1101101;
            6 : Y_r = 7'b1111101;
            7 : Y_r = 7'b0100111;
            8 : Y_r = 7'b1111111;
            9 : Y_r = 7'b1101111;
            default : Y_r = 7'b0000000; 
        endcase
    end
    else if (scan_cnt == 3)
    begin
        case(doorstate[7:4])
            0 : Y_r = 7'b0111111;
            1 : Y_r = 7'b0000110;
            2 : Y_r = 7'b1011011;
            3 : Y_r = 7'b1001111;
            4 : Y_r = 7'b1100110;
            5 : Y_r = 7'b1101101;
            6 : Y_r = 7'b1111101;
            7 : Y_r = 7'b0100111;
            8 : Y_r = 7'b1111111;
            9 : Y_r = 7'b1101111;
            10 : Y_r = 7'b0111111;
            default : Y_r = 7'b0000000; 
        endcase
    end
    else //(scan_cnt == 4)
    begin
        if (doorstate[7:4] == 10)
            Y_r = 7'b0000110;
        else 
            Y_r = 7'b0111111; 
    end  
end
endmodule

