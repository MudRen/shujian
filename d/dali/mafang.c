// mafang.c
// bbb 1997/06/11
// Modify By River 98/12/
inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "��");
	set("long", @LONG
��������վ�ڴ�������ߵ�һ����������������Ͳ��Ǻܿ��䣬��
���������г�����������ԭ�����˺�Ҫȥ��ԭ����������������ѡһƥ����
�����ſڵĵط�����һ��ľ��ɵ�����(sign)��
LONG
	);

	set("item_desc", ([
		"sign": (: look_sign :),
	]) );
	
	set("exits", ([
           "east" : __DIR__"qsjie2",
        ]));

        set("objects", ([
            __DIR__"npc/mafu" : 1,
        ]));

	set("coor/x",-320);
  set("coor/y",-450);
   set("coor/z",-20);
   set("coor/x",-320);
  set("coor/y",-450);
   set("coor/z",-20);
   setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
      me->set_temp("dali_xc/mafang",1);
      }
}

string look_sign(object me)
{
	if( wizardp(me) )
	return "����д����ר��ĸ��\n";
	else
	return "����д����ר������\n";
}
