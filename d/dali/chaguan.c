// Room: /d/dali/chaguan.c
// bbb 1997/06/11
inherit ROOM;

void create()
{
        set("short", "���");
	set("long", @LONG
һ�߽���������ŵ�һ������Ĳ��㣬���һ�Ƿ��źö�̳�ӣ�ȫװ����
��Ҷ���м�������������ϸϸ����ѡ��Ҷ���販ʿһ��΢Ц���к��������Ŀ�
�ˣ���ɫ������������Χ��ȴҲû�м������֡�
LONG
	);
	set("resource/water", 1);

	set("exits", ([
              "east" : __DIR__"beijie1",
	]));

	set("objects", ([
                    __DIR__"npc/chabox" : 1,
                    __DIR__"npc/chake" : 1,
                    "/clone/npc/yinggu" :1,
	]));

	set("coor/x",-340);
  set("coor/y",-380);
   set("coor/z",-20);
   setup(); 
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
      me->set_temp("dali_xc/chaguan",1);
      }
}
