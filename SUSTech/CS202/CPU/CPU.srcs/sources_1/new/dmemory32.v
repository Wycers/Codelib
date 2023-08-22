`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
 module dmemory32(read_data,address,write_data,Memwrite,clock);
    output[31:0] read_data;  // �Ӵ洢���л�õ�����
    input[31:0] address;     //����memorioģ�飬Դͷ������ִ�е�Ԫ�����alu_result
    input[31:0] write_data;  //�������뵥Ԫ��read_data2
    input  Memwrite;         //���Կ��Ƶ�Ԫ
    input  clock;
    
    wire clk;
    assign clk = !clock;     //  ��Ϊʹ��Block ram�Ĺ����ӳ٣�RAM�ĵ�ַ����������ʱ��������׼����,
                             //  ʹ��ʱ�����������ݶ����������Բ��÷���ʱ�ӣ�ʹ�ö������ݱȵ�ַ׼
                             //  ����Ҫ���Լ���ʱ�ӣ��Ӷ��õ���ȷ��ַ��
    
    //����64KB RAM��������ʵ��ֻ�� 64KB RAM
    RAM ram (
        .clka(clk),             // input wire clka
        .wea(Memwrite),         // input wire [0 : 0] wea
        .addra(address[15:2]),  // input wire [13 : 0] addra
        .dina(write_data),      // input wire [31 : 0] dina
        .douta(read_data)       // output wire [31 : 0] douta
    );
endmodule
