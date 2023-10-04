import java.util.concurrent.ExecutorService;
// wait() e notify()
/**
 *
 * @author marcio
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Buffer b= new Buffer();
        Thread t1= new Thread(new Waiting(b));
        Thread t2= new Thread(new Waiting(b));
        Thread t3= new Thread(new Waiting(b));
        Thread t4= new Thread(new Notifier(b));
        t1.start();
        t2.start();
        t3.start();
        t4.start();
    }
    
}


 class Waiting implements Runnable{
    Buffer b;
    public Waiting(Buffer _b){
        b=_b;        
    }
    
    public void run(){
        try {
            b.waiting();
        } catch (InterruptedException ex) {
           
        }
        
        
        
    }
    
}



/**
 *
 * @author marcio
 */
class Notifier implements Runnable{
    Buffer b;
    public Notifier(Buffer _b){
        b=_b;
        
    }
    public void run(){
        try {
           Thread.sleep(1000);
            b.notifying();
        } catch (InterruptedException ex) {
           
        }
        
    }
    
}

class Buffer {
    public synchronized void waiting() throws InterruptedException{
        wait();
        System.out.println("Unblocked");

        
        
    }
    public synchronized void notifying() throws InterruptedException{
 
        notify();
    }
    
}


