
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIW "����" NOR);
	set("long", @LONG
 ���������ׯ������,��Χ��ǽ�Ϲ��ż����ֻ�,�ƺ����������ֱʣ�����
��ɨ�ĺܸɾ�������һ�����Ű�������ȴ����ɽկģ����
LONG);
	set("outdoors", "lanzhou");
        set("no_get_from", 1); 
     set("no_fight", 1);
        set("no_sleep_room", 1);
         set("objects", ([
                 __DIR__"npc/miaorenfeng" : 1,
         ]));
	set("exits", ([ 
	  "south" : __DIR__"qianting",
	  "north" : __DIR__"houyuan",
]));
            set("quest",1);
	setup();
}

void init()
{
	object me=this_player();
        if(me->query_condition("killer"))
	{
  	 message_vision(HIC"\nͻȻ����֪�������ﴫ��һ�������������ﲻ��ӭ$N��\n"NOR,me); 
		 tell_object(me,HIR"���ţ���֪����������һֻ��ŷ���һ�ţ�����һ���߷ɳ�ȥ��\n"NOR);
		 tell_room(environment(me),HIR"\n��֪����������һֻ��ŷ���һ�ţ���"+ me->name()+ "�߷ɳ�ȥ��\n"NOR, ({ me }));
		 if(random(2)) me->move("/d/lanzhou/lanzhou");
		 else me->move("/d/lanzhou/zhengmen");
		 tell_room(environment(me), HIR"\nֻ��"+ me->name()+ "���һ���ɹ�����ˤ�˸�����ʺ����˧Ŷ~~~~~~~~\n"NOR, ({ me }));
		 me->start_busy(1);
	   return;
	}
}
