// Room: /d/dzd/caodi1.c

inherit __DIR__"dzd_room";

void create()
{
	set("short","�ݵ�");
	set("long",@LONG
������һƬˮ�ݽ�����ʪ�ء�������Ţ���С����紵�������쳤��֮���ֳ������ŵ�
���۰׹ǣ��ƺ��������㣬�˴���Ȼ�ƺ��ž����ˣ�ȴ�ǰ���ɱ��������ͱ�����һ��Ϫ
�����Ѷ�����
LONG
	);
	set("outdoors","���ǵ�");
	set("exits",([
		"north" : __DIR__"caodi2",
		"east" : __DIR__"xiliu1",
		"southeast" : __DIR__"haitan1",
	]));
	set("objects",([
		__DIR__"npc/snake" : 1,
	]));
	setup();
}