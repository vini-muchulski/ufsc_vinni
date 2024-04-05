module half_adder(
a_i,
b_i,
s_o,
c_o
);

	input a_i,b_i;
	output s_o,c_o;

	and(c_o,a_i,b_i);
	xor(s_o,a_i,b_i);



endmodule
