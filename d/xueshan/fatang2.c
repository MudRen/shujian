// Room: fatang2.c
// tangfeng@SJ 2004

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "���ö�¥");
	set("long", @LONG
�����Ǵ��������ž������������ģ�����֤������������ǣ�
    Ϸ������ɽǰ�£��������������ӡ�
    ��Ȼ���������д�һ¥�㡣
    �����⣬Ⱥɽ���֣�������ء�
    �����⣬¥̨���䣬�������С�
LONG
	);

	set("exits", (["down" : __DIR__"fatang",]));
        set("objects", ([CLASS_D("xueshan") + "/jiumozhi" : 1,]));
	setup();
}
void init()
{
        add_action("do_push", "push");
        add_action("do_look", "look");
}
int do_look(string arg)
{
	object me = this_player();

	if (!me->query_temp("quest/�����˲�/����Ӫ��ƪ/askzhi")) {
		set("long", @LONG
�����Ǵ��������ž������������ģ�����֤������������ǣ�
    Ϸ������ɽǰ�£��������������ӡ�
    ��Ȼ���������д�һ¥�㡣
    �����⣬Ⱥɽ���֣�������ء�
    �����⣬¥̨���䣬�������С�
LONG
);
		me->look(arg);
	}
	else {
		if (!arg) {
			set("long", @LONG
�����Ǵ��������ž������������ģ�����֤������������ǣ�
    Ϸ������ɽǰ�£��������������ӡ�
    ��Ȼ���������д�һ¥�㡣
    �����⣬Ⱥɽ���֣�������ء�
    �����⣬¥̨���䣬�������С�
    
ֻ������ϸ�ع۲������ܣ����ֱ���ǽ�ߣ�wall���ƺ����л��
LONG
);
			me->look(arg);
		}
		else if (arg == "wall") {
			tell_object(me,HIR"����ϸ�ع۲������ܣ�����ǽ�߿����ƿ���push����\n"NOR);
			return 1;
		}
 }		
}

int do_push(string arg)
{
		object me = this_player();
    if (!me->query_temp("quest/�����˲�/����Ӫ��ƪ/askzhi")) return 0;
	      if( arg == "wall" || arg == "ǽ" || arg == "ǽ��")
        {
        message_vision("$N�ƿ����ǽ����������ͨ��һ�����ҡ�\n", this_player());
        if( !query("exits/north") ) {
        set("exits/north", __DIR__"anshi");
        remove_call_out("close_path");
        call_out("close_path", 15);
        }
        return 1;
        }
}
void close_path()
{
        if( !query("exits/north") ) return;
        message("vision","һ��ᣬ�̵�һ����ǽ�ָֻ�ԭ����\n", this_object() );
        delete("exits/north");
}
int valid_leave(object me, string dir)
{
     if (dir == "north" && present("jiumo zhi", environment(me)))
     return notify_fail("�Ħ�Ǻȵ�������ʲô����λ��ʦ��أ�\n");    
     if (dir == "north" && me->query_condition("killer"))
     return notify_fail("�㷢���ƺ��й�����ά��������޷����룡\n");
     return ::valid_leave(me, dir);
}
