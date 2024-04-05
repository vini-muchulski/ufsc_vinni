module ex0_1 (a, b, c, d, outt);
  input a, b, c, d;
  output wire outt; // Changed to output wire

  // Declaração dos fios
  wire w1, w2, w3;

  // Lógica combinacional
  assign w1 = a & ~b;
  assign w2 = b & c;
  assign w3 = w1 | w2;

  // Lógica sequencial (se necessário)
 

  // Atribuição final à saída
  assign outt = w3; // Assuming w3 is the final result

endmodule