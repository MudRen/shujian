// Room: /d/putian/road06.c
// Lklv 2001.9.11

inherit ROOM;
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
���ϵ�ɽ·������խ��һ�йžɵ�ʯ�׳���������¡�ʯ��ƽ�����ȣ���Щ��
��������̦����̤��������������Ǻܻ�����Զ�����Կ���һ��С��ͤ��
LONG
        );

        set("exits", ([
                "westdown" : __DIR__"road05",
                "southup" : __DIR__"road07",
        ]));

        set("objects",([
                NPC_D("youke") : 2,
        ]));

        set("outdoors", "����");
        setup();
}

int valid_leave(object me, string dir)
{
        if ((me->query("id") == "wu seng" || me->query("id") == "seng bing")
         && dir == "westdown") {
			return notify_fail("");
		}
        return ::valid_leave(me, dir);
}

