package io.trajepl.util;
import java.io.*;

public class Print {
	public static void print(Object... objs) {
		for (Object obj: objs)
			System.out.print(obj);
	}

	public static void println(Object... objs) {
		for (Object obj: objs)
			System.out.println();
	}

	public static PrintStream  printf(String format, Object... args) {
		return System.out.printf(format, args);
	}
}
