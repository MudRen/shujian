// Room: /d/village/minfang1.c

inherit ROOM;

void create()
{
        set("short", "��");
	set("long", @LONG
����һ�������вݶ�����񷿣��ɼ����ݵ����˲�����ʮ�ָ�ԣ�����Ӳ�
�󣬿�ǽ�����Ŵ󴲣���ͷ�и�С��ױ̨��
LONG
        );
        set("exits", ([
	"east" : __DIR__"shilu1",
	]));
        set("objects", ([
                __DIR__"npc/cuihua": 1 
	]) );
        set("no_clean_up", 0);

	setup();
}
