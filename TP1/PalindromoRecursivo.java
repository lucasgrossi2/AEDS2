import java.util.Scanner;

public class PalindromoRecursivo {
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

    // Recursive method to print whether each string in the array is a palindrome
    private static void imprimePal(String[] palavras, int index) {
        if (index >= 0) {
            if (isPal(palavras[index])) {
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }
            imprimePal(palavras, index - 1);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] palavras = new String[1000];
        int entrada = 0;

        // Recursive input reading
        entrada = readInput(scanner, palavras, entrada);

        scanner.close();

        // Print results using recursion
        imprimePal(palavras, entrada - 1);
    }

    // Recursive method to read input until "FIM" is encountered
    private static int readInput(Scanner scanner, String[] palavras, int entrada) {
        if (scanner.hasNextLine()) {
            String input = scanner.nextLine();
            if (isFim(input)) {
                return entrada;
            }
            palavras[entrada] = input;
            return readInput(scanner, palavras, entrada + 1);
        }
        return entrada;
    }
}
