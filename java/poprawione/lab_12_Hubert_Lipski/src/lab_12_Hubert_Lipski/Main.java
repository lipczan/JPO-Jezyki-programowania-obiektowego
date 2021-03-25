package lab_12_Hubert_Lipski;

// Ciagi znakow (13.4) - brak, _ (max. +)
// Stosy (13.5) - uwagi w tekscie; ponadto, wypadaloby skompaktyfikowac kod dotyczacy dzialan
// na stosie (mozna bylo w tym celu przechowac stosy w jednej kolekcji, np. mapie) 
// + i 1/2+ (max. +++)

import java.util.*;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;


import java.io.IOException;
import java.io.File;
import java.io.FileWriter;
import java.io.FileNotFoundException;

//nie u¿y³em metody finilize ze wzglêdu na problemy ze zwolnieniem wykorzystywanych zasobów
//wiêcej na: https://devcave.pl/effective-java/unikaj-finalizerow-i-cleanerow

//OUTPUT//////
//dane wyjsciowe pojawiaja sie w pliku plik2.txt oraz na wyjsciu w konsoli

class WriteToFile {
    static List<String> dane=new ArrayList<>(); // bardzo dziwny pomysl; dlaczego pole statyczne?
                                                // taka lista pownna byc zwiazana z kazdym stosem
                                                // typu ArrayList
    
    WriteToFile(String prompt){
        
        dane.add(prompt);
        try {
          FileWriter myWriter = new FileWriter("plik2.txt");
          for(String str: dane) {
              myWriter.write(str + System.lineSeparator());
            }
          myWriter.close();
          

        } catch (IOException e) {   
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
        
        
    }
}

interface Stos{
    public void top();
    public void pop();
    public void push(int el);
    public void finalize();
}

class Stos_Tablica implements Stos{
    String name;
    static int r=5;
    static int ile_obiektow=0;
    static int ilosc=0;
    
    int[] tablica = new int[5];  // a nie r?
    
    Stos_Tablica(String name){
        this.name=name;
        ile_obiektow++;
    }
    
    public void top(){
        int sw=0;
        for(int i=0;i<r;i++){
            if(tablica[i]<=r && tablica[i]>=0)
                sw=1;
        }
        if(sw!=0){
            System.out.println("Szczytowy element "+name+": "+tablica[r-1]);
            WriteToFile input_tablica_1=new WriteToFile("Szczytowy element "+name+": "+tablica[r-1]);
        }
        else{
            System.out.println("Stos "+name+" pusty!");
            WriteToFile input_tablica=new WriteToFile("Stos "+name+" pusty!");
        }
    }
    
    public void pop(){
        int tmp=ilosc;
        //tmp=lista.size();
        if(tmp!=0){
            ilosc--;
            //lista.remove(tmp-1);
        }
        else{
            System.out.println("Stos "+name+" pusty!");
            WriteToFile input=new WriteToFile("Stos "+name+" pusty!");
        }
    }
    
    public void push(int el){
        int tmp;
        int tmp_2=0;
        tmp_2++;
        if(tmp_2<=r){
            tmp=ile_obiektow-1;
            tablica[tmp]=el;
            ilosc++;
            
        }
        else{
            System.out.println("Stos "+this.name+" pelny!");
            tmp_2--;
            WriteToFile input=new WriteToFile("Stos "+name+" pelny!");
        }
    }
    
    public void finalize(){  // jest finalize!
        String className = this.getClass().getSimpleName();
        System.out.println("Obiekty "+className+": "+ile_obiektow);
        WriteToFile input_tablica_2=new WriteToFile("Obiekty "+className+": "+ile_obiektow);
    }
}

class Stos_Lista implements Stos{
    String name;
    static int r=5;
    static int ile_obiektow=0;
    
    List<Integer> lista=new ArrayList<>();
    
    Stos_Lista(String name){
        this.name=name;
        ile_obiektow++;
    }
    
    public void top(){
        if(lista.size()!=0){
            System.out.println("Szczytowy element "+name+": "+lista.get(lista.size()-1));
            WriteToFile input_lista=new WriteToFile("Szczytowy element "+name+": "+lista.get(lista.size()-1));
        }
        else{
            System.out.println("Stos "+name+" pusty!");
            WriteToFile input_lista=new WriteToFile("Stos "+name+" pusty!");
        }
    }
    
    public void pop(){
        int tmp;
        tmp=lista.size();
        if(tmp!=0){
            lista.remove(tmp-1);
        }
        else{
            System.out.println("Stos "+name+" pusty!");
            WriteToFile input=new WriteToFile("Stos "+name+" pusty!");
        }
    }
    
    int ile_el=0;
    public void push(int el){
        
        ile_el++;
        if(ile_el<=r){
            lista.add(el);
            
        }
        else{
            System.out.println("Stos "+this.name+" pelny!"); // tutaj trudno o przepelnienie...
            ile_el--;
        }
    }
    public void finalize(){
        String className = this.getClass().getSimpleName();
        System.out.println("Obiekty "+className+": "+ile_obiektow);
        WriteToFile input_tablica_2=new WriteToFile("Obiekty "+className+": "+ile_obiektow);
    }
}


public class Main
{
	public static void main(String[] args) throws FileNotFoundException{
	    
	    System.out.println("Wybor zadania: ");
	    System.out.println("1. Stos obs³uga wyjatkow");
	    System.out.println("2. Stos iplementacja interfejsu i obsluga wyjatkow");
	    System.out.println("3. Zadanie dodatkowe lab_12 zadanie 6");
	    
	    Scanner obj = new Scanner(System.in);
	    int nr;
	    nr = obj.nextInt();
	    
	    switch (nr){
	        case 1:{
	            int[][] lista = new int[10][2];
		
        		Scanner scan = new Scanner(System.in);
        		
        		//System.ou2t.print("Ciag a: ");
                //String a = scan.nextLine();
                //String a="nana";
                //String a="abaaaaaaaaaaaaaaaaaaaaaaaaaa";
                String a="aba";
                //System.out.println(a);
                
                //System.out.print("Ciag b: ");
                //String b = scan.nextLine();
                String b="ababakjabsabagab";
                //String b="banananana";
                //System.out.println(b);
                
                if(a.length()>b.length()){
                    System.out.println("Operacja niewykonalna - d³ugosc(a) > d³ugosc(b)");
                    break;
                }
                
                int tmp=0;
                int j=0;
                int l=0;
                int tmp_2=0;
                
                for(int i=0;i<b.length();++i){
                    tmp=0;
                    for(int k=0;k<a.length();++k){
                        if(b.charAt(i+k) == a.charAt(k)){
                            
                            //System.out.println("tutaj");
                            //System.out.println(i);
                            //System.out.println(k);
                            //System.out.println("tutaj");
                             tmp++;
                        }
                    }
                    
                    if(tmp==a.length()){
                        //tmp_2=i++;
                        lista[j][l]=i+1;
                        lista[j][l+1]=i+a.length();
                        //System.out.println("tutaj");
                        System.out.print(lista[j][l]+"  ");
                        System.out.println(lista[j][l+1]);
                        //System.out.println(lista[1][0]);
                        //System.out.println(lista[1][1]);
                        l=0;
                        j++;
                            
                    }
                }
	            break;
	        }
	        case 2:{
	            //nazwy obiektów
	            //program przyjmuje nazwy obiektów np. OB1, OB2 itp. 
	            //oraz liczby calkowite mniejsze niz 10
	            
	            String name1="OB1";
	            String name2="OB2";
	            String name3="OB3";
	            
	            Stos_Tablica Ob1=new Stos_Tablica(name1);
	            Stos_Lista Ob2= new Stos_Lista(name2);
	            Stos_Lista Ob3= new Stos_Lista(name3);
	           
	           String PU="PU";
	           String TO="TO";
	           String PO="PO";
	            
	            File file = new File ("plik1.txt");
                Scanner scan = new Scanner(file);
	            
	            while(scan.hasNextLine()){
	                String data =scan.nextLine();
	                //warunek dla PU
	                if(data.charAt(0) == PU.charAt(0) && data.charAt(1) == PU.charAt(1)){
	                    //warunek dla OB1
	                    if(data.charAt(3) == name1.charAt(0) && data.charAt(4) == name1.charAt(1) && data.charAt(5) == name1.charAt(2)){
	                        //System.out.println(data);
	                        int a=Character.getNumericValue(data.charAt(7));  
	                        Ob1.push(a);
	                    }
	                    //warunek dla OB2
	                    if(data.charAt(3) == name2.charAt(0) && data.charAt(4) == name2.charAt(1) && data.charAt(5) == name2.charAt(2)){
	                       int a=Character.getNumericValue(data.charAt(7));  
	                       Ob2.push(a);
	                    }
	                    //warunek dla OB3
	                    if(data.charAt(3) == name3.charAt(0) && data.charAt(4) == name3.charAt(1) && data.charAt(5) == name3.charAt(2)){
	                       int a=Character.getNumericValue(data.charAt(7));  
	                       Ob3.push(a);
	                    }
	                }
	                //warunek dla TO
	                if(data.charAt(0) == TO.charAt(0) && data.charAt(1) == TO.charAt(1)){
	                     if(data.charAt(3) == name1.charAt(0) && data.charAt(4) == name1.charAt(1) && data.charAt(5) == name1.charAt(2)){
	                        Ob1.top();
	                    }
	                    if(data.charAt(3) == name2.charAt(0) && data.charAt(4) == name2.charAt(1) && data.charAt(5) == name2.charAt(2)){
	                       Ob2.top();
	                    }
	                    if(data.charAt(3) == name3.charAt(0) && data.charAt(4) == name3.charAt(1) && data.charAt(5) == name3.charAt(2)){
	                       Ob3.top();
	                    }
	                }
	                //warunek dla PO
	                if(data.charAt(0) == PO.charAt(0) && data.charAt(1) == PO.charAt(1)){
	                    if(data.charAt(3) == name1.charAt(0) && data.charAt(4) == name1.charAt(1) && data.charAt(5) == name1.charAt(2)){
	                        Ob1.pop();
	                    }
	                    if(data.charAt(3) == name2.charAt(0) && data.charAt(4) == name2.charAt(1) && data.charAt(5) == name2.charAt(2)){
	                        Ob2.pop();
	                    }
	                    if(data.charAt(3) == name3.charAt(0) && data.charAt(4) == name3.charAt(1) && data.charAt(5) == name3.charAt(2)){
	                       Ob3.pop();
	                    }
	                }
	           
	            }
	            Ob1.finalize();
	            Ob2.finalize();
	           
	            break;
	        }
	        case 3:{
	            int n=1000;
	            System.out.println("Czas tworzenia list: ");
	            long startTime=System.nanoTime();
	                int tablica[]= new int[n];
	            long estimatedTime=System.nanoTime() - startTime;
	            System.out.println("(a) tablica "+estimatedTime+" ns");
	            
	            startTime=System.nanoTime();
	                List<Integer>lista=new ArrayList<>();
	            estimatedTime=System.nanoTime() - startTime;
	            System.out.println("(b) kolekcji ArrayList "+estimatedTime+" ns");
	            
	            startTime=System.nanoTime();
	                List<Integer>lista_2=new ArrayList<>(n);
	            estimatedTime=System.nanoTime() - startTime;
	            System.out.println("(c) kolekcji ArrayList dla max. "+estimatedTime+" ns");
	            
	            startTime=System.nanoTime();
	                LinkedList<Integer> object = new LinkedList<>(); 
	            estimatedTime=System.nanoTime() - startTime;
	            System.out.println("(d) kolekcji LinkedList "+estimatedTime+" ns");
	            break;
	        }
	        default:{
	            
	            System.out.println("Niepoprawny numer zadania!");
	            break;
	        }
	    }
	}
}
