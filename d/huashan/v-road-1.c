// Room: /d/huashan/v-road-1.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
������Χ���ǹ�ľ(guanmu)�����ϵķ���Ͷ�����ķ����ƺ����߹�ȥ��
LONG);
	set("item_desc",([
	"guanmu" : "��ľ�Ժ�����Լ��ʲô������\n",
]));
        set("exits", ([ 
                "northeast"     : __DIR__"v-road-2",
	              "southeast"     : __DIR__"v-road-5",
                "southwest"     : __DIR__"shentan",
        ]));
/*
         set("objects",([
                __DIR__"npc/sword/chengbuyu" : 1,
                __DIR__"npc/sword/chongbuqi" : 1,
                __DIR__"npc/sword/fengbuping" : 1,
        ]));
*/
        set("outdoors", "��ɽ");
        set("coor/x",40);
  set("coor/y",80);
   set("coor/z",-10);
   setup();
}
void init()
{
	add_action("do_bo", "bo");
}

int do_bo(string arg)
{
	
	object me;
	me = this_player();
	if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
	return notify_fail("����æ���ģ�\n");

	if ( arg=="" || arg!="guanmu"|| !arg) 
	return notify_fail("��Ҫ��ʲô��\n");

	if ( arg == "guanmu") {
	write("�㲦��һƬƬ��ľ�ԣ�ͻȻ��ǰһ����\n", me);
	me->move(__DIR__"maowu");
	return 1;
	}
}
