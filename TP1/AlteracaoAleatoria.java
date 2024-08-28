package TP1;

import java.util.Random;
import java.util.Scanner;

public class AlteracaoAleatoria {

    private static final Random random = new Random(4);

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        altAl(scanner);
    }

    private static boolean isFim(String str) {
        return "FIM".equals(str);
    }

    private static void altAl(Scanner scanner) {
        String input = scanner.nextLine();
        
        if (isFim(input)) {
            return;
        } else {
            char letter1 = (char) ('a' + random.nextInt(26));
            char letter2 = (char) ('a' + random.nextInt(26));

            StringBuilder result = new StringBuilder();
            for (char c : input.toCharArray()) {
                if (c == letter1) {
                    result.append(letter2);
                } else {
                    result.append(c);
                }
            }

            System.out.println(result.toString());
            altAl(scanner);
        }
    }
}
