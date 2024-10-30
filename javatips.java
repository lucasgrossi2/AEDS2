import java.util.*; //import principal, necessário sempre

public class javatips { //o programa inteiro fica dentro dessa classe
    
    public static void main(String[] args){ //como a int main() em C, o método

        Scanner sc = new Scanner(System.in); //cria o objeto scanner

        int num = sc.nextInt(); //lê o proximo inteiro do buffer e joga ele em num
        char letra = sc.next().charAt(0); //lê o proximo caracter no buffer
        sc.nextLine();//limpa o buffer para a proxima leitura não ler o \n causado pelo enter
        String str = sc.nextLine(); //lê a linha (string) inteira

        System.out.println("aqui voce coloca texto. num = "+num+", depois voce continua o texto e char: "+letra+", e finaliza com a string: "+str); //"println" coloca um \n no final, "print" não.

        sc.close(); //fecha o scanner no fim do programa
    }

}
