// Room: /d/taishan/.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�˴�������أ����������ƥ�Ѳ�����ǰ������˵������������̩ɽ��
������������������ʣ������˰���Ҫ�ĳ�С����ɽ��
LONG
        );

        set("exits", ([
                "northup" : __DIR__"ertian",
                "southdown" : __DIR__"shijin",
        ]));

        set("objects",([
		__DIR__"npc/jian-ke2" : 1,
        ]));
        set("outdoors", "̩ɽ");
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir=="northup" ) {
		if(me->query("can_ride"))
			return 0;
	        if(me->query_temp("ride_horse"))
			return notify_fail("��λ" + RANK_D->query_respect(me) + "����������������ɽ�ɣ�\n");
        }
        return ::valid_leave(me, dir);
}
