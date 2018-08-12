public class Computer {
	public static void print(String s) {
		System.out.println(s);
	}
	public enum Brand{
		DELL("Inter i3", "Windows 10", "4G"),
		LENOVO("I5-7200U", "Windows 10", "8G"),
		MACBOOKPRO("Inter i5", "Mac OS", "8G");
		private final String cpu;
		private final String system;
		private final String mainMemoryCapacity;
		Brand(String cpu,String system, String main){
			this.cpu = cpu;
			this.system = system;
			mainMemoryCapacity = main;
		}
		public String getCpu() {
			return cpu;
		}
		public String getSystem() {
			return system;
		}
		public String getMainMemoryCapacity() {
			return mainMemoryCapacity;
		}
		public String toString() {
			return getCpu() + " " + getSystem() + " " + getMainMemoryCapacity();
		}
	}
	public static void main(String[] args) {
		Brand[] brand = Brand.values();
		for(Brand computer:brand) 
			print(computer.toString());
		print("");
		for(Brand computer:brand) 
			if(computer.mainMemoryCapacity == "8G")
				print(computer.toString());
	}
}
