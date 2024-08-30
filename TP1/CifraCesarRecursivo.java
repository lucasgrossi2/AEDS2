package TP1;

import java.util.Scanner;

public class CifraCesarRecursivo {

    public static boolean isFim(String palavra) {
        return palavra.equals("FIM"); // se for FIM, retorna true, se não for FIM, retorna false
    }

    public static void cifra(Scanner scanner) {
        String string = scanner.nextLine();

        if (isFim(string)) {
            return;
        } else {
            StringBuilder cifrada = new StringBuilder();
            for (int i = 0; i < string.length(); i++) {
                int ASCII = (int) string.charAt(i);
                cifrada.append((char) (ASCII + 3));
            }
            System.out.println(cifrada.toString());
            cifra(scanner); // Chamada recursiva
        }
    }

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            cifra(scanner);
        }
    }
}


