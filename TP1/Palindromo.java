import java.util.Scanner;

public class Palindromo {
     // Checks if the given word is "FIM"
     private static boolean isFim(String palavra) {
        return palavra.equals("FIM");
    }

    // Checks if the given string is a palindrome
    private static boolean isPal(String palavras) {
        int len = palavras.length();
        int n = len / 2;
        boolean resp = true;
        for (int i = 0; i < n; i++) {
            if (palavras.charAt(i) != palavras.charAt(len - i - 1)) {
                resp = false;
                break;
            }
        }
        return resp;
    }

    // Prints whether each string in the array is a palindrome
    private static void imprimePal(String[] palavras, int entrada) {
        for (int i = 0; i < entrada; i++) {
            if (isPal(palavras[i])) {
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] palavras = new String[1000];
        int entrada = 0;

        // Read input until "FIM" is encountered
        while (scanner.hasNextLine()) {
            String input = scanner.nextLine();
            if (isFim(input)) {
                break;
            }
            palavras[entrada++] = input;
        }
        scanner.close();

        // Print results
        imprimePal(palavras, entrada);
    }


}
