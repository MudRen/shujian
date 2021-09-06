#include <room.h>
#include <ansi.h>
inherit ROOM;
#define QUESTDIR1 "quest/�����˲�/�貨΢��ƪ/"
void create()
{
         set("short", HIC"���׽���"NOR);
         set("long",@LONG
������ɽ���ߵ����׽��ߣ������������յñ����Ľ�������������һ��
�ƽ�һ�㣬׳���ޱȣ���վ���������ʲôҲ��Ը���룬ֻϣ���������쳤
�ؾã�ʱ�����㡣
LONG
 );

        set("exits",([
             "eastup" : __DIR__"gaoshan",
]));
        
	set("outdoors", "����");
	setup();
}

void init()
{
	object me = this_player();
      
	if (me->query_temp(QUESTDIR1+"yingjiu")&& me->query(QUESTDIR1+"pass_shanlu")) {
		me->set_temp("wait", 1);
		tell_object(me,HIC"\n���������ߣ�˼ӿ�糱������˼����ǧ��\n"NOR);
		call_out("do_wait", 20 + random(10), me);
	}
	add_action("do_jump", "jump");
	add_action("do_look", "look");
}

void do_wait(object me)
{

if(!me) return;
	if(environment(me) && me->query_temp("wait")) {
		tell_object(me,HIY"\n���������ߣ�˼ӿ�糱������˼����ǧ��ͻȻ�۽�Ƴ��������ʮ����һ�����ʯ��yan)���ƺ���Щ�Ź֡�\n"NOR);
		me->delele_temp("wait");
		me->set_temp("yan1",1);
	}
}

int do_look(string arg)
{
	object me = this_player();

	if (!me->query_temp("yan1")) {
		set("long", @LONG
������ɽ���ߵ����׽��ߣ������������յñ����Ľ�������������һ��
�ƽ�һ�㣬׳���ޱȣ���վ���������ʲôҲ��Ը���룬ֻϣ���������쳤
�ؾã�ʱ�����㡣
LONG
);
		me->look(arg);
	}
	else {
		if (!arg) {
			set("long", @LONG
������ɽ���ߵ����׽��ߣ������������յñ����Ľ�������������һ��
�ƽ�һ�㣬׳���ޱȣ���վ���������ʲôҲ��Ը���룬ֻϣ���������쳤
�ؾã�ʱ�����㡣���������ߣ�˼ӿ�糱������˼����ǧ��ͻȻ�۽�Ƴ������
��ʮ����һ�����ʯ��yan)���ƺ���Щ�Ź֡�
LONG
);
			me->look(arg);
		}
		else if (arg == "rock" || arg == "yanshi" || arg == "yan") {
			tell_object(me,HIR"һ����ң���֪���ɲ���������ȥ��\n"NOR);
			me->set_temp("yan2", 1);
			return 1;
		}
       }		
}

int do_jump(string arg)
{
	object me;
	me = this_player();

	if (arg !="yan"|| !me->query_temp("yan2")) 
		return notify_fail("��Ҫ������ȥ��\n");

	if (me->query_skill("dodge",1) < 80)
		tell_object(me,WHT"�����������ʯ����֮��ľ��룬�ƺ�̫Զ�ˣ�ֻ�����ա�\n"NOR);
	else {
		tell_object(me,HIR"��һ������������������ʯ�ϡ�\n"NOR);
		message("vision", me->name() + "һ���������˼�ʮ��Զ�Ĵ���ʯ�ϡ�\n", environment(me), ({me}) );
		me->delete_temp("wait");
		me->delete_temp("yan1");
		me->delete_temp("yan2");     
		me->move(__DIR__"yan");
		message("vision", me->name() + "������Ծ��������\n", environment(me), ({me}) );
	}
	return 1;
}

int valid_leave(object me,string dir)
{
	if (me->query_temp("wait"))
		me->delete_temp("wait");
	me->delete_temp("yan1");
	me->delete_temp("yan2");     
        return ::valid_leave(me,dir);
}
