`timescale 10ns/100ps
module full_adder_tb;

	reg a_tb,b_tb,c_tb;
	wire s_tb,co_tb;
	
	
	

	
full_adder U0(
	.a_i(a_tb), //escritos
	.b_i(b_tb),
	.c_i(c_tb),//escritos
	.s_o(s_tb),//lidos
	.c_o(co_tb) //lidos
	);
	

initial
begin
  a_tb = 0;
  b_tb = 0;
  c_tb = 0;
  
  #5;
  
  a_tb = 0;
  b_tb = 0;
  c_tb = 1;
  
  #5;
  
  a_tb = 0;
  b_tb = 1;
  c_tb = 0;
  #5;
  
  a_tb = 0;
  b_tb = 1;
  c_tb = 1;
  
  #5;
  
  a_tb = 1;
  b_tb = 0;
  c_tb = 0;
  
  #5;
  
  a_tb = 1;
  b_tb = 0;
  c_tb = 1;
  
  #5;
  
  a_tb = 1;
  b_tb = 1;
  c_tb = 0;
  
  #5;
  
  a_tb = 1;
  b_tb = 1;
  c_tb = 1;
  
  
  
  #20;
  $stop;
  

  
end

always @(a_tb or b_tb or c_tb) $display("a_tb = %b  b_tb = %b c_tb = %b        s_tb = %b, co_tb = %b",a_tb, b_tb, c_tb, s_tb, co_tb);


endmodule


