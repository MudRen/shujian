// Room: /d/fuzhou/zhengting.c

inherit ROOM;

void create()
{
	set("short", "�ھ�����");
	set("long", @LONG
�����Ǹ����ھֵ���������ֻ̫ʦ��һ���ſ�����������������ͷ���ֳ�
�̴������ڱ�Ŀ��˼��ǽ�Ϲ��ż����ֻ���һ�ѱ�����
LONG
	);
	set("exits", ([
		"north" : __DIR__"biaoju",
	]));
	set("no_fight",1);
	set("objects", ([
        	__DIR__"hubiao/linzhennan" : 1,
	]));
	setup();
}
