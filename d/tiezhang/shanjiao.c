// Room: /u/zqb/tiezhang/shanjiao.c

inherit ROOM;

void create()
{
        set("short", "ɽ����");
        set("long", @LONG
�����ѵ���ɽ���£��˴���������������ɽ����أͻŭ��ȷ�������ָ��
���ڰ��֮�С�����һ���ȼ�ͦ�Σ�����ָ�죬�����Ʊ��������ɽ����
��һƬ���֣�������ѩ������������������������缫�ҡ�
LONG
        );

        set("outdoors", "tiezhang");

        set("exits", ([ 
              "northup" : __DIR__"shanmen",
              "southeast" : __DIR__"road-3",
        ]));

           set("objects",([
           __DIR__"npc/keshang":1,
           ]));
        set("no_clean_up", 0);
        set("coor/x",-330);
  set("coor/y",-300);
   set("coor/z",-20);
   setup();
}

int valid_leave(object me, string dir)
{
        if(dir=="northup" ){
        if(me->query("can_ride")){
          return 0;
          }       
        if(me->query_temp("ride_horse"))
        return notify_fail("ɽ�Ͼ�����������������ɽ��\n");
        }
        return ::valid_leave(me, dir);
}

