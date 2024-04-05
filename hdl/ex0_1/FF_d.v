module FF_d 
#(parameter N=4)
(
    input wire clk,    // Clock
    input wire rst,  // Reset
    input wire [N-1:0] D, // Dados de entrada de largura N
    output wire [N-1:0] Q // Saída 
);

reg [N-1:0] op_reg; 

always @(posedge clk or posedge rst) begin
    if (rst) begin
        op_reg <= 0; // Reiniciar o registrador
    end else begin
        op_reg <= D; // Atribuir D ao registrador na borda de subida do clock
    end
end

// Saída é o conteúdo do registrador
assign Q = op_reg;

endmodule