`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////

module ioread(reset,ior,switchctrl,ioread_data,ioread_data_switch);
    input reset;			// ��λ�ź� 
    input ior;              //  �ӿ���������I/O����
    input switchctrl;		//  ��memorio������ַ�߶��߻�õĲ��뿪��ģ��Ƭѡ
    input[15:0] ioread_data_switch;  //���������Ķ����ݣ��˴����Բ��뿪��
    output[15:0] ioread_data;	// ���������������͸�memorio
    
    reg[15:0] ioread_data;
    
    always @* begin
        if(reset == 1)
            ioread_data = 16'b0000000000000000;
        else if(ior == 1) begin
            if(switchctrl == 1)
                ioread_data = ioread_data_switch;
            else   ioread_data = ioread_data;
        end
    end
endmodule
