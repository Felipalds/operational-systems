import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

// we can use Runnable interface
// java does not have multiple herance
class Main {
  public static void main(String[] args) { 
     // an interface is a contract (abstraction)
     Thread t1, t2;
     Buffer b = new Buffer();
     t1= new Thread(new ThreadInterface(b));
     t2= new Thread(new ThreadInterface(b));

     t1.start();

     t2.start();

        // System.exit(0);
        // exit mata o processo e todas as threads
        // return deixa as threads continuando a executar
      
    try {
      t1.join();
      t2.join();
    }catch (Exception e){
      
    }
  
  }
  
}
