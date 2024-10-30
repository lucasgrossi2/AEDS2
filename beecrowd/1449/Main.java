import java.util.*;

public class Main {

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        int instancias = sc.nextInt();
        for(int i = 0; i < instancias; i++){
            int numPalavrasDic = sc.nextInt();
            int numLinhasMusica = sc.nextInt();
            String[] palavrasJap = new String[numPalavrasDic];
            String[] palavrasPort = new String[numPalavrasDic];
            for(int j = 0; j < numPalavrasDic; j++){
                palavrasJap[j] = sc.nextln();
                palavrasPort[j] = sc.nextln();
            }
            String[][] linhasMusica = new String[numLinhasMusica][];
            for(int k = 0; k < numLinhasMusica; k++){
                linhasMusica[k] = sc.nextln();
            }
            String[][] linhasMusicaSplit = new String[numLinhasMusica][];
            for(int l = 0; l < numLinhasMusica; l++){
                linhasMusicaSplit[i] = linhasMusica.split(" ");
            }
        }
        

    }
    
}