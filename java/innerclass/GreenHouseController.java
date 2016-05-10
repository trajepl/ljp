import java.util.*;

abstract class Event {
	private long eventTime;
	protected final long delayTime;

	public Event(long delayTime) {
		this.delayTime = delayTime;
		start();
	}

	public void start() {
		eventTime = System.nanoTime() + delayTime;
	}
	
	public boolean ready() {
		return System.nanoTime() >= eventTime;
	}
	public abstract void action();
}

class Controller {
	private List<Event> eventList = new ArrayList<Event>();
	public void addEvent(Event c) {
		eventList.add(c);
	}

	public void run() {
		while(eventList.size() > 0) {
			for (Event e: new ArrayList<Event>(eventList)) {
				if (e.ready()) {
					System.out.println(e);
					e.action();
					eventList.remove(e);
				}
			}
		}
	}
}

class GreenHouse extends Controller {
	private boolean light = false;
	public class LightOn extends Event {
		public LightOn(long delayTime) {
			super(delayTime);
		}

		public void action() {
			light = true;
		}
		public String toString() {
			return "Light is on.";
		}
	}
	public class LightOff extends Event {
		public LightOff(long delayTime) {
			super(delayTime);
		}

		public void action() {
			light = false;
		}
		public String toString() {
			return "Light is off.";
		}
	}
}
public class GreenHouseController {
	public static void main(String[] args) {
		GreenHouse gc = new GreenHouse();
		Event[] eventList = {
			gc.new LightOn(200),
			gc.new LightOff(400)
		};
		// System.out.println(System.nanoTime());
		for (Event e: eventList)
			gc.addEvent(e);
		gc.run();
	}
}
