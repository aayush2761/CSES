import java.util.Scanner;

public class Repetitions {
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
    int n = s.length();
    int answer=1;
    int temp=1;
    for(int i=1;i<n;i++){
        if(s.charAt(i)==s.charAt(i-1)){
            temp++;
            answer= Math.max(answer, temp);
        }
        else{
            temp=1;
        }
    } 
    System.out.println(answer);
        sc.close();
    }
}
