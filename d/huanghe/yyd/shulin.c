// shulin.c ����
// zly 99.7.28

#include <room.h>
inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
������һƬïʢ�����֣�������ľ���죬�㵽�������ôҲ���������
Χ�ľ����ˡ�
LONG
     );
        set("outdoors", "�ƺ�");

	set("exits", ([
		"northeast" : __FILE__,
                "southeast" : __FILE__,
                "southwest" : __FILE__,
                "northwest" : __FILE__,
	]));
	setup();
}

void init()
{
        object ob;
        int jing, jing_cost;

        ob = this_player();
        jing = ob->query("jing");
        jing_cost = ob->query("kar")+random(20);
	jing_cost /= 2;

        ob->add("jing", -jing_cost);
}

int valid_leave(object me, string dir)
{
        if (random((int)me->query("kar")) >= 10)
                me->add_temp("mark/steps",1);

        if (random((int)me->query("kar")) < 10)
                me->add_temp("mark/steps",-1); 
        
        if (me->query_temp("mark/steps") == 3) {
                me->move(__DIR__"houshan");
                me->delete_temp("mark/steps");
             return notify_fail("�㵽�����ߣ���Ȼ��ǰһ������֪���������˺�ɽ��\n");
        }  

        if (me->query_temp("mark/steps") == -5) {
                me->move(__DIR__"houyuan");
                me->delete_temp("mark/steps");
                return notify_fail("��������ȥ����֪�����ֻص��˺�Ժ��\n");
        }
	return ::valid_leave(me, dir);
}
