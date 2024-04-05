`timescale 10ns/100ps

module half_adder_tb;

	reg a_tb, b_tb;
	wire s_tb,c_tb;

half_adder U0(
.a_i(a_tb), //escritos
.b_i(b_tb),//escritos
.s_o(s_tb),//lidos
.c_o(c_tb) //lidos
);

initial 
begin
  a_tb = 0;
  b_tb = 0;
  
  #5;
  
  a_tb = 0;
  b_tb = 1;
  
  #5;
  
  a_tb = 1;
  b_tb = 0;
  
  #5;
  
  a_tb = 1;
  b_tb = 1;
  #20;
  $stop;
  
end

always @(a_tb or b_tb) $display("s_tb = %b, c_tb = %b", s_tb, c_tb);




endmodule

