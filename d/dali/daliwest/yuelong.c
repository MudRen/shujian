// Room: /d/dali/yuelong.c
// bbb 1997/06/10 
//cool 98.3.17
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "����ѩɽ");
	set("long", @LONG
ȫɽʮ���壬����������ƴ�ѩ����һ�������������죬���������ڽ�ɳ
����������һ���ý����������ӱ̿����Ѷ�������Ծ�ڽ�����֮�ϡ�������
���磬������һ�����桢׳�������� 
LONG
	);
        set("outdoors", "����");

	set("exits", ([
             "northdown" : __DIR__"ninglang",
	]));

	set("coor/x",-380);
  set("coor/y",-450);
   set("coor/z",0);
   setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
       me->set_temp("dali_xc/yuelong",1);
      }
}
