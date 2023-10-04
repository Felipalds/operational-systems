import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Main {
    public static void main(String[] args) {
        ExecutorService executor = Executors.newCachedThreadPool();
        // a CachedThreadPool é dinâmica, vai criando threads e alocando memória
        // a FixedThreadPool é fixa, não pode criar mais threads do que o passado
        for (int i = 0; i < 10; i++){
            executor.execute(new ThreadInterface());
        }
        executor.shutdown();
    }
}
