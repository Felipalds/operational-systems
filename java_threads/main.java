import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

// we can use Runnable interface
// java does not have multiple herance
class Main {
  public static void main(String[] args) { 
     // an interface is a contract (abstraction)
     Thread t1, t2;
     t1= new Thread(new ThreadInterface());
     t2= new Thread(new ThreadInterface());

     t1.start();
     t2.start();
    try {
      t1.join();
      t2.join();
    }catch (Exception e){
      
    }
  
  }
  
}
