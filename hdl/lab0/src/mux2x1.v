module mux2x1
 //declaracao de portas
(
a,b , sel, q
);

input a ,b , sel;
output reg q; // por conta do always usamos reg

//logica

always @(a or b or sel)
begin

if(sel == 1'b1) //'hab
q <=a;

else
q <=b;



end



endmodule
