module juncao (
    input a, b, c, d, rst,
    output outt
);

// Declare w_outt as a wire
wire w_outt;

// Instanciar o módulo ex0_1
ex0_1 ex0_1_inst (
    .a(a),
    .b(b),
    .c(c),
    .d(d),
    .outt(w_outt) // Conectar a saída do ex0_1 a um fio intermediário
);

// Instanciar o módulo FF_d
FF_d FF_d_inst (
    .clk(d), // Conectar d do ex0_1 ao clk do FF_d
    .rst(rst),
    .D(w_outt), // Conectar a saída do ex0_1 à entrada D do FF_d
    .Q(outt) // Conectar a saída do FF_d à saída final
);

endmodule