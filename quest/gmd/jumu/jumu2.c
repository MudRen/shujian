#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIG"��ľ��"NOR);
       set("long", @LONG
�����Ǿ�ľ������ڵء�������Ÿ��ָ����Ŀ������ߺ�һ�����Ĵ���ľ��
�������м��������ľ��ľ׮����������౻�ƻ����ĺۼ���Ϊ���е���ƽʱ
����֮�á����в��������������ţ�����ָ��֣���������ܹ��ɽ���������
�ĺ��Ľ������ǳ��Ա���֮�֡���Ϊ���������ڸ߳������������ǹ�������
��һ�����ߣ�������һ�򵱹����Ī��֮�ơ�������һƬ��ɭ�Ĵ����֡�
LONG);    
        set("outdoors", "���̹�����");

	set("exits", ([
                "west" :  __DIR__"jumu"+(random(4)+1),
                "south" : __DIR__"jumu"+(random(2)+3),
                "east" :  __DIR__"jumu1",
                "north" : __DIR__"jumu"+(random(3)+2),
        ]));

	setup();
}

void reset()
{
set("exits", ([
                "west" :  __DIR__"jumu"+(random(4)+1),
                "south" : __DIR__"jumu"+(random(2)+3),
                "east" :  __DIR__"jumu1",
                "north" : __DIR__"jumu"+(random(3)+2),
        ]));
}
void init()
{      object ob, me;
       int j;
	me= this_player();
	
     
	if (random(me->query("kar")) == 2)
		{
			me->apply_condition("neishang", 3 * me->query_kar());
;
		message_vision(HIG"\n$Nһ��С�ģ���������һֻ��ľ׮��ײ�ڵ��ء�\n\n"NOR, me);
	}
        

   
}

//�Ǿ���
int is_mirror() { return 1; }