// Room: /d/fuzhou/biaoju.c
// Lklv modify 2001.9.10
inherit ROOM;

void create()
{
	set("short", "�����ھ�");
	set("long", @LONG
������һ���ṹ��ΰ�Ľ���ǰ������ʯ̳�ϸ�����һ�����ɶ�ߵ���ˣ�
��������Ʈ����������ý�������һͷ������צ��ʨ�ӣ�ʨ����ͷ��һֻ��
����衣����������д�š������ھ֡��ĸ����֣������������վ��Ƿ������
�������������ʣ�������ͷ���Ű��ء�����ͷ��������˵Ц��
LONG
	);
	set("exits", ([
		"south" : __DIR__"zhengting",
        	"north" : __DIR__"xijie",
        	"east" : __DIR__"zhangfang",
	]));
	set("objects", ([
		__DIR__"npc/linpingzhi" : 1,
		__DIR__"npc/zhang_bt" : 1,
		__DIR__"npc/xu_bt" : 1,
	]));
	setup();
}
