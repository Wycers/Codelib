`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
 module dmemory32(read_data,address,write_data,Memwrite,clock);
    output[31:0] read_data;  // 从存储器中获得的数据
    input[31:0] address;     //来自memorio模块，源头是来自执行单元算出的alu_result
    input[31:0] write_data;  //来自译码单元的read_data2
    input  Memwrite;         //来自控制单元
    input  clock;
    
    wire clk;
    assign clk = !clock;     //  因为使用Block ram的固有延迟，RAM的地址线来不及在时钟上升沿准备好,
                             //  使得时钟上升沿数据读出有误，所以采用反相时钟，使得读出数据比地址准
                             //  备好要晚大约半个时钟，从而得到正确地址。
    
    //分配64KB RAM，编译器实际只用 64KB RAM
    RAM ram (
        .clka(clk),             // input wire clka
        .wea(Memwrite),         // input wire [0 : 0] wea
        .addra(address[15:2]),  // input wire [13 : 0] addra
        .dina(write_data),      // input wire [31 : 0] dina
        .douta(read_data)       // output wire [31 : 0] douta
    );
endmodule
