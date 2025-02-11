package org.musical;

import java.util.Random;
import java.util.concurrent.Semaphore;

class Stage {
  private final Semaphore semaphore = new Semaphore(3);

  void useStage(Performer performer) {
    Random rnd = new Random();
    try {
      semaphore.acquire();
      performer.perform();
      performer.performing = true;
      Thread.sleep(rnd.nextInt(3, 9));
      performer.performing = false;
      System.out.println(performer.name + " finished performing");
    } catch (InterruptedException e) {
      Thread.currentThread().interrupt();
    } finally {
      semaphore.release();
    }
  }
}
