// Room: /d/dzd/caodi3.c

inherit __DIR__"dzd_room";

void create()
{
	set("short","�ݵ�");
	set("long",@LONG
������һƬˮ�ݽ�����ʪ�ء�������Ţ���С����紵�������쳤��֮���ֳ������ŵ�����
�׹ǣ��ƺ��������㣬�˴���Ȼ�ƺ��ž����ˣ�ȴ�ǰ���ɱ�����������������ٲ���������
LONG
	);
	set("outdoors","���ǵ�");
	set("exits",([		
		"east" : __DIR__"xiliu3",
		"south" : __DIR__"caodi2",
		"northeast" : __DIR__"pubu",
	]));
	set("objects",([
		__DIR__"npc/snake" : 1,
	]));
	setup();
}