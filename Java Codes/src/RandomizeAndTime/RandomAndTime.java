package RandomizeAndTime;

import java.util.Random;

public class RandomAndTime {
    public static void main(String[] args) {
        Random rd = new Random();
        rd.setSeed(42696);

        long currentTime = System.currentTimeMillis();
        System.out.println(rd.nextFloat());
        System.out.println(rd.nextInt(10));
        System.out.println(rd.nextGaussian());

        System.out.println(System.currentTimeMillis() - currentTime + " ms taken");


    }
}
