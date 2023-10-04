import java.util.concurrent.Semaphore;
// why does it goes wrong? Because the Print does a little ENGASGADA
// e é mais provável de dar pau sem o Print, pois não há a engasgada.
// O count fica com valor inconsistente
// Devemos criar um semáforo

public class Main
{
	public static void main(String[] args) throws Exception{
		System.out.println("Hello World");
	  Buffer b= new Buffer(5);

		Thread th1 = new Thread(new Produtor(b));
		Thread th2 = new Thread(new Consumidor(b));
		
		th1.start();
		th2.start();

		try {
		   th1.join();
		   th2.join();
		} catch(Exception e) {
		
		}
	}
}

class Produtor implements Runnable{
    Buffer b;

    public Produtor(Buffer _b){
        b= _b;
    }
    
    public void run(){
        for (int i= 0; i<1000;i++){
            b.produz(i);
           // System.out.println("produziu "+ i);
        }
    }
}

class Consumidor implements Runnable{
    Buffer b;

    public Consumidor(Buffer _b){
        b= _b;
    }
    
    public void run(){
        int temp;
        for (int i= 0; i<1000;i++){
            temp= b.consome();
           // System.out.println("consome "+ temp);
        }
    }
}



class Buffer {
    
    volatile int count;
    volatile int buffer[];
    int in;
    int out;
    int n;
    Semaphore s;
    public Buffer(int _n){
        n= _n;
        buffer= new int[n];
        count=0;
        in=0;
        out=0;
        s= new Semaphore(1);
    }
    
    public void produz(int value){
        while (count ==n);
        
        
        buffer[in]= value;
        in= (in+1)% n;

        count++;
        
        
    }
    
    public int consome(){
        while (count ==0);
        
        int temp= buffer[out];
        out=(out+1)%n;
        count--;
        return temp;
    }
    
}



