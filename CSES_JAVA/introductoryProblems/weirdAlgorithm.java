import java.util.Scanner;

public class weirdAlgorithm{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        sc.close();
        while(n!=1){
            System.out.print(n + " ");
            if(n%2==0) n/=2;
            else n= n*3+1;
        }
        System.out.print(1);

    }
}