import java.util.Scanner;

public class missingNumber{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int x=0;
        for(int i=1;i<=n;i++){
            // int p = sc.nextInt();
            x^=(i);
        }
        for(int i=1;i<n;i++){
            int p = sc.nextInt();
            x^=(p);
        }
        System.out.println(x);


    }
}