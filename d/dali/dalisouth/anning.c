// Room: /d/dali/anning.c
// bbb 1997/06/10 
// cool update 98.3.17
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "������Ȫ");
	set("long", @LONG
����λ����������Լ��ʮ�����봨�ϡ�����ɽ�͵��䡢ɭ��ï�ܡ�����
���¡���Ȼ������������봨��ˮ��Ȫ������Ȫˮ�ʵ�������ˮ���ʵ�������
������ּ����Ϻ���Ч�ĸ���΢��Ԫ�أ�����Ϊ�����µ�һ������
LONG
	);
        set("outdoors", "����");

	set("exits", ([
          "west" : __DIR__"xgf",
	]));
        set("objects", ([
	      __DIR__"npc/caihuashe" : 1,
              __DIR__"npc/daxia" : 1,
              __DIR__"npc/dayetu" : 1,
	]));

	set("coor/x",-300);
  set("coor/y",-490);
   set("coor/z",-10);
   setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
       me->set_temp("dali_xc/anning",1);
      }
}
