import java.util.*;
import java.io.*;

public class increasingArray {
    public static void main(String[] args) throws IOException {
        // Your code goes here
        Scanner sc= new Scanner(System.in);
            int n = sc.nextInt();
        Vector<Long> v = new Vector<>(n);
        for(int i=0;i<n;i++){
                v.add(0L);
                long x = sc.nextLong();
            v.set(i,x);
        }
        long answer =0;
        for(int i=1;i<n;i++){
            if(v.get(i-1)>v.get(i)){
                answer+= v.get(i-1)-v.get(i);
                v.set(i,v.get(i-1));
            }
        }
        System.out.println(answer);

    }
}