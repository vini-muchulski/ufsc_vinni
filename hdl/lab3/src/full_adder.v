module full_adder(
a_i,
b_i,
c_i,
s_o,
c_o
);

	input a_i,b_i,c_i;
	output s_o,c_o;
	
	wire w_carry1,w_carry2, w_sum;
	

	
half_adder U0(
	.a_i(a_i), //escritos
	.b_i(b_i),//escritos
	.s_o(w_sum),//lidos
	.c_o(w_carry1) //lidos
	);
	
half_adder U1(
	.a_i(w_sum), //escritos
	.b_i(c_i),//escritos
	.s_o(s_o),//lidos
	.c_o(w_carry2) //lidos
	);

or U2(c_o,w_carry1,w_carry2);


endmodule


