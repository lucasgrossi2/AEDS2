import java.util.*;

public class elementar{

    public static int insertionSort(int[] array, int count) {
        for (int i = 1; i < array.length; i++) {
            int key = array[i];
            int j = i - 1;

            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                j = j - 1;
                count++;
            }
            array[j + 1] = key;
        }
        return count;
    }
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int instancias = sc.nextInt();

        for(int i = 0; i < instancias; i++){
            int len = sc.nextInt();
            int[] numline = new int[len];
            for(int j = 0; j < len; j++){
                numline[j] = sc.nextInt();
            }
            int count = 0;
            count = insertionSort(numline, count);
            System.out.println(count);
        }
        sc.close();
    }

}

