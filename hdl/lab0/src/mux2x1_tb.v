module mux2x1_tb;
  reg r_a,r_b,r_sel;
  wire w_q;
  
  
mux2x1 U0

(
.a(r_a),
.b(r_b),
.sel(r_sel),
.q(w_q)
);

initial 
begin
#5;
r_a =0;
r_b = 1;
r_sel =0;

 // Imprimir o valor de w_q após a primeira mudança de entradas
 //   $display("Saída do mux: %b", w_q);

    #5;
    r_sel = 1;

    // Imprimir o valor de w_q após a segunda mudança de entradas
    //$display("Saída do mux: %b", w_q);
    
    
   


#20
$stop; 
end
  
  
   always @(w_q)
    begin
      $display("Saída do mux: %b", w_q);
    end
    
    
endmodule
