module ripple_carry(
a_i,
b_i,
c_i,
s_o,
c_o


);

	input [3:0]a_i,b_i;
	input c_i;
	output [3:0]s_o;
	output c_o;
	
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
	




endmodule


