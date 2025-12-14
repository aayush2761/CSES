// import java.util.*;
// import java.io.*;

// public class Permutations {
//     public static void main(String[] args) throws IOException {
//         // Your code goes here
//         Scanner sc= new Scanner(System.in);

//         int n = sc.nextInt();
//         if(n==1){
//             System.out.println(1);
//             return;
//         }
//         if(n<4){
//             System.out.println("NO SOLUTION");
//             return;
//         }

//         // int [] arr = new int[n];

//        // print even numbers
//         for (int i = 2; i <= n; i += 2) {
//             System.out.print(i + " ");
//         }
//         // print odd numbers
//         for (int i = 1; i <= n; i += 2) {
//             System.out.print(i + " ");
//         }
//         sc.close();
//     }
// }


import java.io.*;

public class Permutations {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        if (n == 1) {
            System.out.println(1);
            return;
        }
        if (n < 4) {
            System.out.println("NO SOLUTION");
            return;
        }

        StringBuilder sb = new StringBuilder();

        for (int i = 2; i <= n; i += 2) {
            sb.append(i).append(" ");
        }
        for (int i = 1; i <= n; i += 2) {
            sb.append(i).append(" ");
        }

        System.out.print(sb.toString());
    }
}
