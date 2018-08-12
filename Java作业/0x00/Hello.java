public class Hello {
	public static void revMultTable() {
		for (int i = 9; i >= 1; --i) {
			for (int j = 1; j <= i; ++j)
				System.out.printf("%d * %d = %d\t", j, i, i * j);
			System.out.println();
		}	
	}
	public static void intro() {
		System.out.println("11711918 吴烨昌");
		System.out.println("0x00 来自福建福州 爱好搞事 乱点技能树");
		System.out.println("0x01 初一开始编程 写过一个锁屏挂机的小程序");
		System.out.println("0x02 初二接触AE 参加NOIP");
		System.out.println("0x03 初三接触Python 第一个Py项目是百度贴吧的爬虫 后来就一直拿来作数学题。。");
		System.out.println("0x04 高一的时候写了一个点歌台的服务端和客户端 放在竞赛机房提供点歌服务（被拿来放pump it=。=）");
		System.out.println("0x05 高二的时候自己做了一台3D打印机 打印了一些东西参加了当时学校的XX模型大赛");
		System.out.println("0x06 高三的时候开始学习Nodejs");
		System.out.println("0x07 高三毕业的暑假回校带信息学夏令营 用Nodejs作后端写了一个提交代码用的服务器");
		System.out.println("0x08 高二的时候入树莓派的坑 在上面搭了NAS和Xware=。=");
		System.out.println("0x09 高二的时候又入了Ardunio的坑 做过无线键盘 温湿度计这样的东西");
		System.out.println("0x0A PS。。基本操作什么的。。裁图还是会的");
		System.out.println("0x0B 其实也就是会乱搞又不怕采坑。。");
		System.out.println("0x0C 作为一名信息竞赛划水玩家 研究和修改网上的代码(搜题解和抄标程)当然不在话下");
		System.out.println("0x0D 希望在AIers能学到stm32。。");
		
	}
    public static void main(String[] args){
        System.out.println("Hello World!");
        revMultTable();
        intro();
    }
}