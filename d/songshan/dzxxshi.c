// Room: /d/songshan/dzxxshi.c

inherit ROOM;

void create()
{
	set("short", "��Ϣ��");
	set("long", @LONG
���������������ʮ���Ŵ�����ʰ�øɸɾ������������ˣ���������
�����С˯һ�����
LONG);
	set("exits", ([
            "south" : __DIR__"csshi",
        ]));
        set("no_fight", 1);
        set("sleep_room", 1);
	setup();
}
