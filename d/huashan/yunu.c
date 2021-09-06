// Room: /d/huashan/yunu.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
	set("short", "��Ů��");
	set("long", @LONG
�����ǻ�ɽ���з壬��Ů�塣��Ů�������Ϊƽ�������������ķ��ǰ���
���������Ϻպ������Ļ�ɽ���ɾ��ڴ˴�����������СС������Ǿ�����Ů
���ˡ�����ϡϡ������ʮ���䷿�ӣ������ǻ�ɽ�ɵĵط��������ο���ñ���
��ȥ��
LONG
	);
	set("exits", ([
		"northdown" : __DIR__"zhenyue",
		"northwest" : __DIR__"xiaolu1",
		"east" : __DIR__"yunuci",
		"south" : __DIR__"shanlu1",
		"west" : __DIR__"pubu",
	]));
	set("objects", ([
		NPC_D("youke") : 1,
		NPC_D("caiyaoren") : 1,
	]));
	set("outdoors", "��ɽ" );
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir=="south" ){
        if(me->query("can_ride")) {  return 0;  }

	if(me->query_temp("ride_horse"))
		return notify_fail("��λ" + RANK_D->query_respect(me) + "�������������ٽ�ȥ�ɣ�\n");
        }
        return ::valid_leave(me, dir);
}


