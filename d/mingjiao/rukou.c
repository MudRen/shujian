// rukou.c  �������
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",HIR"�������"NOR);
       set("long", @LONG
���������̵ĵ��¼�������ڴ������̵�ִ����վ����������ޱȣ���
�˲������ӡ���ڴ���һ�ȴ�����(men)�����Ŵ���һ������ס��
LONG);    
	set("exits", ([		
		"northwest" : __DIR__"jinqi",
                "southwest" : __DIR__"zl7",
	]));  
        set("item_desc", ([
                "men" : "һ�ȴ����ţ�����ȥʮ���ι̡�\n"
        ]));                       
	set("objects",([
                __DIR__"npc/dizi1" : 1,
                __DIR__"npc/dizi4" : 1,
                CLASS_D("mingjiao") + "/leng" : 1,
	]));
        set("coor/x",-260);
  set("coor/y",220);
   set("coor/z",120);
   set("coor/x",-260);
 set("coor/y",220);
   set("coor/z",120);
   setup();
}

void init()
{
        object me = this_player();
        if(me->query_temp("mj/xunluo") && !me->query_temp("mj/rukou"))
           me->set_temp("mj/rukou",1);
}
