// Room: /d/nanyang/yidao.c
// Lklv Modify 2001.10.10

inherit ROOM;
void create()
{
	set("short", "���");
	set("long", @LONG
�������������ڵ�һ�������·���������������������ʱ���������
��ɳ۶���������һ·���������ϵ��˸������ž�װ���¼��������еĻ�����
����ŵ�������������Щϰ��Ľ����ˡ���·��������������������֡�����
����һֱ�߾����������ˡ�
LONG
	);
	set("outdoors", "����");
	set("exits", ([
	        "south" : "/d/xiangyang/henanroad2",
		"north" : __DIR__"yidao1",
		"east" : __DIR__"xiaolu2",
	]));
        set("objects", ([
                NPC_D("poorman") : 1,
	]));
	setup();
}
