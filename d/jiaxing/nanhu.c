// Room: /d/jiaxing/nanhu.c

inherit ROOM;

void create()
{
	set("short", "�Ϻ�");
	set("long", @LONG
�����Ǽ����Ϻ����ڽ������Ҷ���У����ⱥʵ��һ���������ת�ĸ�
����Ʈ����ˮ���ɵĺ����ϡ�Զ������������������С���ϲ�ʱ����������Ů
��Ц����
LONG
	);

	set("exits", ([
                "east" : __DIR__"hubian",
                "west" : __DIR__"dbianmen",
                "southeast" : __DIR__ "nanhu1",
	]));

	set("outdoors", "����");
	setup();
}
