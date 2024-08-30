package TP1;

import java.util.Scanner;

public class CifraCesar {
    
    public static boolean isFim(String palavra) {
        return palavra.equals("FIM");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] strings = new String[1000];
        int entrada = 0;

        do {
            strings[entrada] = scanner.nextLine();
        } while (!isFim(strings[entrada++]));
        entrada--; // Desconta a última entrada que é "FIM"

        for (int i = 0; i < entrada; i++) {
            StringBuilder criptografada = new StringBuilder();
            for (int j = 0; j < strings[i].length(); j++) {
                char caractere = strings[i].charAt(j);
                char criptografado = (char)(caractere + 3);
                criptografada.append(criptografado);
            }
            System.out.println(criptografada.toString());
        }

        scanner.close();
    }
}
