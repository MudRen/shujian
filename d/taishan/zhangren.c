// Room: /d/taishan/.c
// Date: pishou 97/6

inherit ROOM;

void create()
{
	set("short", "���˷�");
	set("long", @LONG
����λ����ʶ���������ĵط�����״����һ�����͵����ˡ������лƻ�
������·��ΪΣ�գ������ڽ�·��д�ϡ��س��ҡ��������������߱���᷶�
�ı����š�
LONG
	);

	set("exits", ([
		"east" : __DIR__"yuhuang",
		"northup" : __DIR__"beitian",
	]));

        set("objects",([
                __DIR__"npc/yuqingzi" : 1,
        ]));

        set("outdoors", "̩ɽ");
	setup();
}
