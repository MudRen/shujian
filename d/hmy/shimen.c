// /d/hmy/shimen.c
// By Spiderii@ty ��������,srf�������½�˶��ͨ��
#include <ansi.h>
#include <wanted.h>
inherit ROOM;

string *ps = ({
	"�����ĳ���£�һͳ����",
	"����ǧ�����أ�һͳ����",
	"��������Ϊ������������",
	"������ּӢ���������Ų�",
	"�����������£��츣����",
	"����ս�޲�ʤ�����޲���",
	"��������ĳ���¡�����Ӣ��",
	"��������ʥ�̣��󱻲���",
});

void set_pass()
{
	set("pass", ps[random(sizeof(ps))]);
}

string get_pass()
{
	return query("pass");
}

void create()
{
	set("short", "ʯ��");
        set("long", "
    �ߵ�һ����ʯ��ǰ��ֻ�����Կ������д��֣������ǡ��ĳ���¡�������
�ǡ�����Ӣ����������Ͽ���

                     "HIR"��   ��   ��   ��"NOR"

�ĸ�����֡�\n");
	set("outdoors", "��ľ��");
	set("exits", ([
	"eastdown" : __DIR__"shijie2",
]));
	set("time", time());
	set("objects", ([
	  __DIR__"npc/jiabu" : 1,
]));

	setup();
	set_pass();
}
void init()
{
	int day = 86400;

	if (time() - query("time") > day) {
		set("time", time());
		set_pass();
	}
        add_action("do_say", "whisper");
}

int do_say(string arg)
{
	object me = this_player();
	object ob;
	string dest, msg;

	if (!arg || sscanf(arg, "%s %s", dest, msg)!=2 )
		return notify_fail("��Ҫ��˭����Щʲô��\n");

        dest = lower_case(dest);
	ob = present(dest, environment(me));

	if (!ob || !ob->is_character() )
		return notify_fail("��Ҫ��˭���\n");
	if (ob->query("id") == "jia bu") {
		write( GRN "����" + ob->name() + "���˸����ƣ��������" + msg + "��\n" NOR);
		tell_room( environment(me), me->name() + "��ָ�Զ���������" + ob->name()
			+ "����˵��Щ����\n", ({ me, ob }) );
		if(is_wanted(me)){

        	        write("�ֲ�����ü�����˿���������·�����ֵܣ��㻹�ǰѹٸ��������˽��˵İɡ�\n");
        	        return 1;
		}
	        if( msg == get_pass()) {
        	        write("ֻ���ֲ�˵�������š����Ǳ����ֵܰɣ�������ɡ�\n");
                	message("vision", "�ǵ���ʯ�Ż������˿�����һ�����½�ͽ˵�������������\n", this_player());
	                set("exits/westup", __DIR__"ryping");

        	        remove_call_out("close");
                	call_out("close", 5, this_object());
        	}
        	else
        		write("�ֲ�����üͷ������û��˵����\n");
      		return 1;
	}
	write( GRN "����" + ob->name() + "�Ķ�������˵����" + msg + "\n" NOR);
	tell_room( environment(me), me->name() + "��" + ob->name()
		+ "����С����˵��Щ����\n", ({ me, ob }) );
	if( !userp(ob) ) ob->relay_whisper(me, msg);
	else
		tell_object( ob, GRN + me->name() + "����Ķ�������˵����" + msg + "\n" NOR);
	return 1;
}

void close(object room)
{
        message("vision","ֻ���Ǵ�ʯ��ƹ�ع����ˡ�\n", room);
        room->delete("exits/westup");
}
int valid_leave(object me, string dir)
{
       if (dir != "eastdown" && me->query_condition("killer"))
          return notify_fail(YEL"�������ٸ�ͨ��,ĪҪ��׷��������\n"NOR);	
       return ::valid_leave(me, dir);
}
