let add x y = x + y

let subtract x y = x - y

let multiply x y = x * y

let divide x y =
  if y = 0 then
    "Division by zero is not allowed!"
  else
    string_of_float (float_of_int x /. float_of_int y)

let calculator () =
  Printf.printf "Simple Calculator\n";
  Printf.printf "-----------------\n";
  Printf.printf "Enter the first number: ";
  let num1 = read_int () in
  Printf.printf "Enter the operation (+, -, *, /): ";
  let operator = read_line () in
  Printf.printf "Enter the second number: ";
  let num2 = read_int () in
  match operator with
  | "+" -> Printf.printf "Result: %d\n" (add num1 num2)
  | "-" -> Printf.printf "Result: %d\n" (subtract num1 num2)
  | "*" -> Printf.printf "Result: %d\n" (multiply num1 num2)
  | "/" -> Printf.printf "Result: %s\n" (divide num1 num2)
  | _ -> Printf.printf "Invalid operator\n"

let _ = calculator ()
