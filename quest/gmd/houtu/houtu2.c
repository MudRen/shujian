#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",YEL"������"NOR);
       set("long", @LONG
�����Ǻ����졣�����и��ָ����Ŀ������ߣ����е���һ������С��������
����һ��������������ڽ��������湦���������������������죬���컥��
�н�֮�ơ�
LONG);    

        set("outdoors", "���̹�����");

	set("exits", ([
                "west" :  __DIR__"houtu"+(random(4)+1),
                "south" : __DIR__"houtu"+(random(2)+3),
                "east" :  __DIR__"houtu1",
                "north" : __DIR__"houtu"+(random(3)+2),
        ]));

	setup();
}

void reset()
{
set("exits", ([
                "west" :  __DIR__"houtu"+(random(4)+1),
                "south" : __DIR__"houtu"+(random(2)+3),
                "east" :  __DIR__"houtu1",
                "north" : __DIR__"houtu"+(random(3)+2),
        ]));
}
void init()
{      object ob, me;
       int j;
	me= this_player();
	
      
	if (random(me->query("kar")) == 2)
		{
			me->start_busy(random(20));
		message_vision(YEL"\n$Nһ��С�ģ�������������֮�ڣ�һʱ�������ã��������´󺧡�\n\n"NOR, me);
	}
        

   
}

//�Ǿ���
int is_mirror() { return 1; }