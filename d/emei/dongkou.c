//dongkou.c

inherit ROOM;
void create()
{
	set("short","���϶���");
	set("long",@long
����Ƕ��ҵ�һ�󶴣���������ޱȣ������Ѳ⡣��һ�߽������㷢����
�в涴�����Թ�������Ī�⣬�ƺ�����޵ס����ǿ���뿪�ɡ�
long);
	set("exits",([
	"out" : __DIR__"jiulaodong",
	"enter" : __DIR__"jiulaodong1",
]));
	setup();
}
