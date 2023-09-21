class ThreadInterface implements Runnable {

  Buffer b;
  public ThreadInterface(Buffer _b) {
    b = _b;
  }

  public void run(){
     for (int i= 0; i < 5 ; i++){
       b.i++;
       System.out.println(Thread.currentThread().getName()+"  "+ i + " b:" + b.i);
       System.out.flush();
     }
     System.out.println("");
    
  }
}
