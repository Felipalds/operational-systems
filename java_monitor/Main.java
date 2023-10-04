import java.util.concurrent.*;

/**
*   Testa a classe SerialNumberGenerator
*
* @version 0.1
* @author POS-UNIOESTE
**/
public class Main {
  private static final int SIZE = 10;
  private static CircularSet serials = new CircularSet(1000);
  private static ExecutorService exec =   Executors.newCachedThreadPool();
  private static int waitTime= 10; 
  
  /* Classe anonima, que solicita numeros para o SerialNumberGenerator, e verifica se o valor retornado já foi obtido por alguma Thread */
  static class SerialChecker implements Runnable {
    public void run() {
      while(true) {
        int serial =
          SerialNumberGenerator.nextSerialNumber();
        if(serials.contains(serial)) {
          System.out.println(Thread.currentThread().getName()+ " Duplicate: " + serial);
          System.exit(0);
        }
        serials.add(serial);
      }
    }
  }
  
  public static void main(String[] args) throws Exception {
    for(int i = 0; i < SIZE; i++)
      exec.execute(new SerialChecker());
    
    exec.shutdown();
    
    TimeUnit.SECONDS.sleep(waitTime);
    System.out.println("Nenhum número duplicado detectado");
    System.exit(0);
    
  }
} 


/**
* A classe CircularSet é um conjunto de tamanho limitado, utilizado para armazenar os números obtidos pelas Threads.
*
* @version 0.1
* @author POS-UNIOESTE
**/
class CircularSet {
  private int[] array;
  private int len;
  private int index = 0;
  public CircularSet(int size) {
    array = new int[size];
    len = size;
    /* Inicializa o conjunto com valores -1 */
    for(int i = 0; i < size; i++)
      array[i] = -1;
  }
    /** 
    * Adiciona um elemento no conjunto
    * @param Valor a ser inserido
     **/
  public synchronized void add(int i) {
    array[index] = i;
    // Começa a sobrepor os elementos quando o tamanho máximo é alcançado
    index = ++index % len;
  }
  
    /** 
    * Verifica se um dado valor está contido no conjunt
    * @param Valor a ser pesquisado
     * @return False se não encontrou ou True se encontrou
     **/
  public synchronized boolean contains(int val) {
    for(int i = 0; i < len; i++)
      if(array[i] == val) return true;
    return false;
  }

}


class SerialNumberGenerator {
    
  private static int serialNumber = 0;
  
    /** 
    * Retorna um novo identificador 
    * @return retorno o novo identificador único
     **/

  public synchronized static int nextSerialNumber() {
    return serialNumber++; 
  }
}



