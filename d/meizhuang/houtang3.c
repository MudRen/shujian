// Room: /d/meizhuang/houtang3.c
// By Lklv

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ����ã����ڼ򵥰ڷ��ż����Ҿߣ�������λ����һ�źܴ�ķ���
�ӣ������߷��˼���̫ʦ�Σ�ǽ�Ϲ���һ�����ᣬ��Ϊ����ģ�����������ǵ�
���Ƿ������Ƿ��֡�����ɫ���������·�ܹžɵ����ӡ�
LONG
	);
	set("exits", ([
		"north" : __DIR__"huilang13",
	]));
	setup();
}