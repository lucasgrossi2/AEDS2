package TP1;

import java.util.Scanner;

public class Parentesis {
    // Method to check if the input string is "FIM"
    private static boolean isFim(String palavra) {
        return palavra.equals("FIM");
    }

    // Method to check the balance of parentheses in a given string
    private static void parCheck(Scanner scanner) {
        String input = scanner.nextLine();
        
        // Check if the input is "FIM", if so, end the recursion
        if (isFim(input)) {
            return;
        } else {
            int firstPar = 0; // 0: no parenthesis found yet, 1: first is ')', 2: first is '('
            boolean firstCheck = false;
            
            // Determine the type of the first parenthesis
            for (int i = 0; i < input.length() && !firstCheck; i++) {
                if (input.charAt(i) == ')') {
                    firstPar = 1;
                    firstCheck = true;
                } else if (input.charAt(i) == '(') {
                    firstPar = 2;
                    firstCheck = true;
                }
            }
            
            // Print "incorreto" if the first parenthesis is ')'
            if (firstPar == 1) {
                System.out.println("incorreto");
            } else {
                int balance = 0;
                
                // Calculate the balance of parentheses
                for (int j = 0; j < input.length(); j++) {
                    if (input.charAt(j) == ')') {
                        balance--;
                    } else if (input.charAt(j) == '(') {
                        balance++;
                    }
                }
                
                // Print "correto" if balance is zero, otherwise "incorreto"
                if (balance == 0) {
                    System.out.println("correto");
                } else {
                    System.out.println("incorreto");
                }
            }
            
            // Recursive call
            parCheck(scanner);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        parCheck(scanner);
        scanner.close();
    }
}
