import java.math.BigInteger;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;

public class KBasedNumbers2{
    public static void main(String args[]){
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = 1, K = 1;
        try{
            N = Integer.parseInt(in.readLine()); K = Integer.parseInt(in.readLine());
        }catch(IOException e){
            System.out.println("m8 pls");
        }

        BigInteger ONE = new BigInteger("1");

        BigInteger n = new BigInteger( Integer.toString(N) );
        BigInteger k = new BigInteger( Integer.toString(K) );
        BigInteger dp[] = new BigInteger[N];

        dp[0] = k.subtract(ONE);
        dp[1] = dp[0].multiply(k);

        for(int i=2; i<N; i++){
            dp[i] = ( dp[i-1].add(dp[i-2]) ).multiply( k.subtract(ONE) );
        }

        System.out.println(dp[N-1].toString());
    }
}
