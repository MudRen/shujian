// Room: /d/nanyang/xiaolu2.c
// Lklv Modify 2001.10.11

inherit ROOM;
void create()
{
	set("short", "��·");
	set("long", @LONG
����һ��Ƨ����С·��������ï�ܵĴ��֡�·����ϡ�ɼ������߹����µ�
�ۼ�����������������������������Ҽ������߷�������ͨ������������֮��
��һ�������
LONG
	);
	set("outdoors", "����");
	set("exits", ([
		"northeast" : __DIR__"xujiaji",
		"west" : __DIR__"yidao",
	]));
        set("objects", ([
                NPC_D("caiyaoren") : 1,
        ]));
	setup();
}
