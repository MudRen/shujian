// Room: /qian.c
// bbb 1997/06/11
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "����Ǯׯ");
	set("long", @LONG
���Ǯׯ��˵��������ԭ��һλ��λ�߹������죬��ȫ�����ؿ��˲��ٷ�
�ꡣ��Ϊҥ�ԣ������й�һ�μ��ҷ糱��Ǯׯһһ�Ҹ�����Ƿ�ֺ����������
���𣬷��е���Ʊͨ��ȫ����
LONG
	);

	set("exits", ([
                "south" : __DIR__"beijie4",
	]));

	set("objects", ([
		__DIR__"npc/qian" : 1
	]));

	set("coor/x",-300);
  set("coor/y",-370);
   set("coor/z",-20);
   set("coor/x",-300);
  set("coor/y",-370);
   set("coor/z",-20);
   setup(); 
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
      me->set_temp("dali_xc/qian",1);
      }
}
