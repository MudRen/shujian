
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIM"��Ժ" NOR);
	set("long", @LONG
��������ҵ���Ժ����ɨ�ķǳ��ɾ�����������ķ��ż������Ρ�һ����
��ֲ�Ÿ��ֻ��ݣ�ֻ���ƺ��ܾ�û�˹�����Щ���ҡ��ϱ���������
LONG
	);
	//set("outdoors", "");
	set("exits", ([ 
	  "south" : __DIR__"zhenting",
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
