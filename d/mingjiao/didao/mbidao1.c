// /d/mingjiao/diechong1.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short","�ص�");
       set("long", @LONG
�����������ص������ƺ���ʧ�˷�����ûͷ��Ӭ�㵽���Ҵ���
LONG
     );
    
	set("exits", ([
		"east" : __DIR__"mbidao"+(random(5)+1),			
		"south" : __DIR__"mbidao"+(random(5)+1),
		"west" : __DIR__"mbidao2",
		"north" : __DIR__"mbidao"+(random(5)+1),
	]));    
	
        setup();

}

void init()
{
	object me,room;
	me=this_player();
	room=this_object();
	message_vision(YEL"\n$Nһ��С�ģ����ص�����·�ˣ�����Ҫ�߳�ȥҪ���ܶ�ʱ�䡣\n\n"NOR,me);
}
