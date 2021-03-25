package lab_13_Hubert_Lipski;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.Random;

class Chlopiec implements Runnable {
    private static final int ile_kawalkow = 4;
    protected BlockingQueue kolejka;
    
 // calkiem nieoczekiwane, poprawne rozwiazanie; mozna mu co najwyzej zarzucic, ze labedzie konsumuj¹ chleb w zawsze w stalej kolejnosci
 // mam nadzieje, ze to samodzielne rozwiazanie - podobne widzialam u p. Kedziory;
 // +++ (max. +++)


    public Chlopiec(BlockingQueue kolejka) {
        this.kolejka = kolejka;
    }
    @Override
    public void run() {
        Random generator = new Random();
        while(true){
            try {
                Thread.sleep(800);
                int tmp_bread = generator.nextInt(ile_kawalkow) + 1;
                for(int i = 0; i < tmp_bread; i++){
                    int breadUniqueNumber = generator.nextInt(100);
                    kolejka.put(breadUniqueNumber);
                    System.out.println("Chlopiec wyrzucil kawalek chleba o numerze: " + breadUniqueNumber);
                }
            } 
            catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class Ptak implements Runnable {
    protected BlockingQueue kolejka;
    private long id;

    public Ptak(long id, BlockingQueue kolejka) {
        this.id = id;
        this.kolejka = kolejka;
    }
    @Override
    public void run() {
        while (true){
            try {
                Thread.sleep(1500);
                System.out.println("Labedz: " + this.id + " zabral chleb o numerze: " + kolejka.take());
            } 
            catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class Main {
    private static final int ile = 4;

    public static void main(String[] args){
        BlockingQueue queue = new ArrayBlockingQueue(5);

        Chlopiec chlop = new Chlopiec(queue);
        new Thread(chlop).start();

        Ptak[] ptaki = new Ptak[ile];
        for(int i = 0; i < ile; i++){
            ptaki[i] = new Ptak(i, queue);
            new Thread(ptaki[i]).start();
        }
    }
}
