package lab_11_Hubert_Lipski;

//Statki (13.1, 13.2, 13.3) - wyniki poprawne, uwagi w tekscie;
//++ (max. +++)


import java.util.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import java.io.File;
import java.io.FileNotFoundException;

import java.util.regex.Pattern;
import java.util.regex.Matcher;

///////////////////UWAGA//////////////////////////////////
//nie wiem co oznacza metoda finilze, wiec jej nie umiescilem
//wyswietlanie wszystkich danych o statku wraz z towarami zamiescilem w metodzie print_all()
//wszystkie operacje zrealizowalem wprowadzajac statycznie wartosci aby zaprezentowac dzialanie metod w szybszy sposob
/////////////////////////////////////////////////////////

class Data{
        String nazwa_lad;
        int liczba;
        int masa;
        
        public Data(String nazwa_lad,int liczba, int masa){
            this.nazwa_lad=nazwa_lad;
            this.liczba=liczba;
            this.masa=masa;
        }
       
        public String getNazwa(){
            return nazwa_lad;
        }
        
        public int getLiczba(){
            return liczba;
        }
        
        public int getMasa(){
            return masa;
        }
}
    
class Statek{
    String ms;
    int lad;
    static int ile=0;
    
    List<Data> tow;
    
    //Map<String, Data>tow=new HashMap<>();  //??
    //List<Data> tow = new ArrayList<Data>();
    
    public Statek(String ms, int lad){
        this.ms=ms;
        this.lad=lad;
        this.tow = new ArrayList<Data>();   // a miala byc mapa...
        System.out.println("#########################################################");
        System.out.println("Nazwa statku: "+this.ms);
        System.out.println("Ladownosc: "+this.lad+" ton");
        //System.out.println("#########################################################");
        
    }
    
    public void zal(String nazwa_lad,int liczba,int masa){
        int tmp=0;
        int tmp_2=0;
        tmp=liczba*masa;
        
        tmp_2=ile+tmp;
        if(tmp<=this.lad*1000 && tmp_2<=this.lad*1000){
            tow.add(new Data(nazwa_lad,liczba,masa));
            ile+=tmp;
            //this.print_all();
        }
        else{
            //System.out.println("    ========================================================");
            //System.out.println("    Ladunek: "+nazwa_lad+" nie moze zostac zaladowany.Masa towaru przekracza ladownosc statku!");
            //System.out.println("    ========================================================");
            System.out.println("    "+nazwa_lad+": przekraczakroczenie ladownosci");
            
        }
            
    }
    
    public void wyl(String nazwa_lad, int liczba){
        int remove,masa_tmp,liczba_tmp;
        for(int i = 0; i < tow.size(); i++) {
            //System.out.println("iteracja"+i);
            if(tow.get(i).getLiczba()==liczba){
                this.cwyl(nazwa_lad);
                break;
            }
            //if(tow.get(i).getNazwa()==nazwa_lad && liczba<tow.get(i).liczba){
            if(Objects.equals(tow.get(i).nazwa_lad, new String(nazwa_lad)) && liczba<=tow.get(i).liczba){
            
               masa_tmp=tow.get(i).getMasa();
               
               remove=liczba*tow.get(i).getMasa();
               ile-=remove;
               
               liczba_tmp=tow.get(i).getLiczba();
               liczba_tmp-=liczba;
               
               tow.remove(i);

               tow.add(i,new Data(nazwa_lad,liczba_tmp,masa_tmp));
               System.out.println(" Wyladowano towar o podanej ilosci "+liczba);
           }
           else if(liczba>tow.get(i).liczba && Objects.equals(tow.get(i).nazwa_lad, new String(nazwa_lad))){
               System.out.println("    "+tow.get(i).nazwa_lad+":   za malo towaru");
               
           }
        }
    }
    
    public void cwyl(String nazwa_lad){
        int remove;
        for(int i = 0; i < tow.size(); i++) {
            //if(tow.get(i).nazwa_lad==nazwa_lad){
            if(Objects.equals(tow.get(i).nazwa_lad, new String(nazwa_lad))){
                remove=tow.get(i).getLiczba()*tow.get(i).getMasa();
                ile-=remove;
                
                //System.out.println("    Wyladowano caly towar: "+tow.get(i).getNazwa()+" w ilosci "+tow.get(i).getLiczba()+" kazdy po "+tow.get(i).getMasa()+" kg.");
                
                tow.remove(i);
               
            }
        }
        //System.out.println("Rozmiar listy to: "+tow.size());
    }
    
    public void opr(){
        int remove;
        for(int i = 0; i < tow.size(); i++) {
            remove=tow.get(i).getLiczba()*tow.get(i).getMasa();
            ile-=remove;
        }
        this.tow.clear();
        //System.out.println("Rozmiar listy to: "+tow.size());
        if(this.tow.size()==0){
            System.out.println("    Wyladowano caly statek!");
        }
    }
    
    public void print_all(){
        System.out.println("Lista towarow na statku: ");
        if(tow.size()==0){
            System.out.println("Brak towarow!");
        }
        for(int i = 0; i < tow.size(); i++) {
            System.out.println("    ========================================================");
            System.out.println("    Nazwa ladunku: "+tow.get(i).getNazwa());
            System.out.println("    Ilosc: "+tow.get(i).getLiczba());
            System.out.println("    Masa pojedynczego ladunku: "+tow.get(i).getMasa()+" kg");
            System.out.println("    ========================================================");
        }
    }
    
    public void print_ile(){
        System.out.println("Masa towarow na wszystkich statkach: "+this.ile+" kg");
    }
}

class Stateczek extends Statek{
    static int ile_st=0;
    int masa_j;
    
     public Stateczek(String ms, int lad, int masa_j){
        super(ms,lad);
        this.masa_j=masa_j;
        System.out.println("Maksymalna waga pojedynczego ladunku: "+masa_j+" kg");
     }
     
     public void zal(String nazwa_lad, int liczba, int masa){
        int tmp=0;
        int tmp_2=0;
        tmp=liczba*masa;
        
        tmp_2=ile_st+tmp;
        if(tmp<=this.lad*1000 && tmp_2<=this.lad*1000 && masa<=this.masa_j){
            tow.add(new Data(nazwa_lad,liczba,masa));
            ile_st+=tmp;
            //this.print_all();
        }
        else if(masa>this.masa_j){
            //System.out.println("    ========================================================");
            System.out.println("    "+nazwa_lad+": za ciezka paczka");
            //System.out.println("    Ladunek przekracza mase jednostkowa ladunku lub ladownosc stateczku!");
            //System.out.println("    ========================================================");
            
        }
        else {
            System.out.println("    "+nazwa_lad+": przekroczenie ladownosci");
            //this.print_stan();
        }
     }
     
     public void stWyl(String nazwa_lad, int liczba){  // a po co po raz wtory definiowac te sama metode?
    	                                              // wystarczylaby odziedziczona po Statku
        int remove,masa_tmp,liczba_tmp;
        for(int i = 0; i < tow.size(); i++) {
            //System.out.println("iteracja"+i);
            if(tow.get(i).getLiczba()==liczba){
                this.cwyl(nazwa_lad);
                break;
            }
            //if(tow.get(i).getNazwa()==nazwa_lad && liczba<tow.get(i).liczba){
            if(Objects.equals(tow.get(i).nazwa_lad, new String(nazwa_lad)) && liczba<=tow.get(i).liczba){
            
               masa_tmp=tow.get(i).getMasa();
               
               remove=liczba*tow.get(i).getMasa();
               ile-=remove;
               
               liczba_tmp=tow.get(i).getLiczba();
               liczba_tmp-=liczba;
               
               tow.remove(i);

               tow.add(i,new Data(nazwa_lad,liczba_tmp,masa_tmp));
               //System.out.println("     Wyladowano towar o podanej ilosci "+liczba);
           }
           else if(liczba>tow.get(i).liczba && Objects.equals(tow.get(i).nazwa_lad, new String(nazwa_lad))){
               System.out.println("    "+tow.get(i).nazwa_lad+":   za malo towaru");
               
           }
        }
    }
     
     
    public void stOpr(){   // j.w.
        int remove;
        for(int i = 0; i < tow.size(); i++) {
            remove=tow.get(i).liczba*tow.get(i).masa;
            ile-=remove;
        }
        this.tow.clear();
        //System.out.println("Rozmiar listy to: "+tow.size());
    }
     
    public void print_stan(){
        //System.out.println("Stan: ");
        if(tow.size()==0){
            System.out.println("    Stateczek '"+ms+"' pusty");
            System.out.println("    Zaladowano lacznie "+ile_st+" kg");
        }
        for(int i = 0; i < tow.size(); i++) {
            //System.out.println("    ========================================================");
            System.out.println("    "+tow.get(i).nazwa_lad+":   "+tow.get(i).liczba+" "+tow.get(i).masa);
        }
        System.out.print("\n");
    }
}

class Lista{
    //plik.txt do lista
    List<String> lista=new ArrayList<>();
    
    public Lista(Stateczek st, String name) throws FileNotFoundException {
        File file = new File (name);
        Scanner scan = new Scanner(file);
        
        
        while(scan.hasNextLine()){
	       lista.add(scan.nextLine());
	    }
	            
        Pattern z=Pattern.compile("Z *");
        Pattern w=Pattern.compile("W *");
        Pattern c=Pattern.compile("C *");
        Pattern s=Pattern.compile("S *");
        Pattern o=Pattern.compile("O *");
        
        String txtNazwa;
        int txtLiczba;
        int txtMasa;
        
        int i=0;
        while(i<lista.size()){
            Matcher matcher_z=z.matcher(lista.get(i));
            Matcher matcher_w=w.matcher(lista.get(i));
            Matcher matcher_c=c.matcher(lista.get(i));
            Matcher matcher_s=s.matcher(lista.get(i));
            Matcher matcher_o=o.matcher(lista.get(i));
            
            if(matcher_z.matches()){
               //System.out.println("znalazlem z");
               txtNazwa=lista.get(i+1);
               txtLiczba=Integer.parseInt(lista.get(i+2));
               txtMasa=Integer.parseInt(lista.get(i+3));
               
               st.zal(txtNazwa,txtLiczba,txtMasa);
               i+=3;
            }
            if(matcher_w.matches()){
                txtNazwa=lista.get(i+1);
                txtLiczba=Integer.parseInt(lista.get(i+2));
                
                //System.out.println(txtLiczba); 
                
                st.stWyl(txtNazwa,txtLiczba);
                i+=2;
            }
            if(matcher_c.matches()){
                txtNazwa=lista.get(i+1);
                st.cwyl(txtNazwa);
                i++;
            }
            if(matcher_s.matches()){
                st.print_stan();
            }
            if(matcher_o.matches()){
                st.stOpr();
            }
            i++;
	    }
    }  
}

public class Main
{
	public static void main(String[] args) throws FileNotFoundException{
	    
	    Scanner myObj = new Scanner(System.in);
        int nr;
        System.out.println("Wybor zadania: "); 
        System.out.println("1. Statek"); 
        System.out.println("2. Stateczek"); 
        System.out.println("3. mojStatek"); 
        System.out.println("4. Korekta zaladunku(trudne)"); 
        
        System.out.print("Wybor: ");
        nr = myObj.nextInt();  
	    
	    switch(nr){
	        case 1:{
	            
	            //statek nr 1, proba dodania nadmiaru ladunku
        	    Statek s1=new Statek("tytanik",20);
        	    s1.zal("banany",100000,400);
        	    s1.zal("kiwi",20,400);
        	    s1.print_all();
        	    
        	    //statek nr 2 dodanie towaru i usuniecie okreslonej ilosci, proba usuniecia nieporpawnej ilosci 
        	    Statek s2=new Statek("dar pomorza",200);
        	    s2.zal("ogorki",80,200);
        	    s2.print_all();
        	    s2.wyl("ogorki",50);
        	    s2.print_all();
        	    s2.wyl("ogorki",50);
        	    s2.print_all();
        	    
        	    //statek nr 3, dodanie i oproznienie statku z towaru 
        	    Statek s3=new Statek("dar mlodzierzy",300); // mlodziezy...
        	    s3.zal("pomarancza",50,500);
        	    s3.zal("liczi",20,100);
        	    s3.print_all();
        	    s3.opr();
        	    s3.print_all();
        	    
        	    //statek nr 4, dodanie i calkowite wyladowani ladunku jednego rodzaju towaru  
        	    Statek s4=new Statek("US Navy",300);
        	    s4.zal("ananasy",60,700);
        	    s4.zal("cytryny",10,600);
        	    s4.print_all();
        	    s4.cwyl("cytryny");
        	    s4.print_all();
        	    
        	    //calkowita masa wszystkich towarow na statkach
        	    s1.print_ile();
	            
	            break;
	        }
	        case 2:{
	            Stateczek st1=new Stateczek("kutr",20,300);
	            st1.zal("dorsz",10,100);
	            st1.zal("losos",10,500);
	            st1.zal("sledz",101,140);
	            st1.print_all();
	            
	            System.out.println("Ca³kowita masa towarow na stateczkach: "+st1.ile_st+" kg");
	            break;
	        }
	        case 3:{
	            Stateczek st=new Stateczek("mojStatek",15,450);
	            Lista l=new Lista(st,"plik.txt");
	            
	            break;
	        }
	        default:{
	            System.out.println("Niepoprawny numer zadania!");
	            break;
	        }
	    }
	    
	}
}
