`timescale 10ns/100ps


module ripple_carry_tb;

	reg [3:0]a_i,b_i;
	reg c_i;
	wire [3:0]s_o;
	wire c_o;
	
	wire [3:0]w_carry;
	

	
full_adder U0(
	.a_i(a_i[0]), //escritos
	.b_i(b_i[0]),//escritos
	.c_i(c_i),
	.s_o(s_o[0]),//lidos
	.c_o(w_carry[0]) //lidos
	);
	
full_adder U1(
	.a_i(a_i[1]), //escritos
	.b_i(b_i[1]),//escritos
	.c_i(w_carry[0]),
	.s_o(s_o[1]),//lidos
	.c_o(w_carry[1]) //lidos
	);
	
full_adder U2(
	.a_i(a_i[2]), //escritos
	.b_i(b_i[2]),//escritos
	.c_i(w_carry[1]),
	.s_o(s_o[2]),//lidos
	.c_o(w_carry[2]) //lidos
	);
	
	
full_adder U3(
	.a_i(a_i[3]), //escritos
	.b_i(b_i[3]),//escritos
	.c_i(w_carry[2]),
	.s_o(s_o[3]),//lidos
	.c_o(c_o) //lidos
	);
	

initial
begin

end

always @(a_tb or b_tb or c_tb) $display("a_tb = %b  b_tb = %b c_tb = %b        s_tb = %b, co_tb = %b",a_tb, b_tb, c_tb, s_tb, co_tb);


endmodule


