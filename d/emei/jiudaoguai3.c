// jiudaoguai3.c


inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIW "��ʮ�ŵ���" NOR);
	set("long", @LONG
���������ġ���ʮ�ŵ��ա�����·����������ǧ�۰ٻء���˵��ȥ���и�
������ķ�ɮ���ˣ���һ������·�������������������ǵ�֪�˴��о�����û
�󣬱���Ҳ���˸�������Ĳ�ľ�����ԡ����ӡ���֮���ɴ˶�����ǧ���֣���
����϶���
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"jiudaoguai2",
		"westup" : __DIR__"jiudaoguai4",
	]));

	set("outdoors", "����ɽ");
	setup();
}

void init()
{
       object me, room;
       me = this_player();
/*	if( ! ( room = find_object(__DIR__"shushang")))
       room = load_object(__DIR__"shushang");
       if(! (present("ju mang", room)));
       return; */
    if(!objectp(me)||!userp(me)||!living(me)) return;
      if (random((int)me->query("kar")) < 9 ) {
       if( ! ( room = find_object(__DIR__"shushang")))
       room = load_object(__DIR__"shushang");
       if(! (present("ju mang", room))) 
       return;
       message_vision(HIR"��Ȼһ���ȷ�Ϯ����һ�����������Դ��������£���$N�����ˡ�\n\n"NOR, me);              
       me->move(__DIR__"shushang");                                                            
       me->start_busy(3);	
    }      

}
