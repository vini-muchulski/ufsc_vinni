fn main() {
    let mut eps_float: f32 = 1.0;
    let mut eps_double: f64 = 1.0;

    // ----------------------- float -----------------------------
    while eps_float + 1.0 > 1.0 {
        eps_float /= 2.0;
        println!("Eps_float = {:.25}", eps_float);
    }
    println!("\nDados do tipo float: a máquina acha que {:.25} vale zero!", eps_float);

    // ----------------------- double -----------------------------
    while eps_double + 1.0 > 1.0 {
        eps_double /= 2.0;
        println!("Eps_double = {:.25}", eps_double);
    }
    println!("\nDados do tipo double: a máquina acha que {:.25} vale zero!", eps_double);
}
