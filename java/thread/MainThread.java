class LiftOff implements Runnable {
	int countDown = 10;
	private static int taskCount = 0;
	private final int id = taskCount++;
	public LiftOff() {}
	public LiftOff(int countDown) {
		this.countDown = countDown;
	}

	public String status() {
		return "#" + id + "(" + 
			(countDown > 0 ? countDown: "LiftOff!") + ").";
	}

	public void run() {
		System.out.println("run");
		while(--countDown > 0) {
			System.out.print(status());
			Thread.yield();
		}
	}
}

public class MainThread {
	public static void main(String[] args) {
		LiftOff launch = new LiftOff();
		launch.run();
		System.out.println("");
	}
}
