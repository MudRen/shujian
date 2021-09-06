// Room: /d/huashan/hole-2.c
// Date: Look 99/03/25

inherit ROOM;

#include <ansi.h>

int init();
int do_use(string arg);
void close_out();
int do_study(string arg);

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
���ﾲ���ĵģ�����һƬ��ڣ���ʲôҲ��������ʲôҲ��������
LONG	);
	set("no_clean_up", 0);
	setup();
}
 
int init()
{
	add_action("do_use","use");
	add_action("do_study","study");
}

int do_use(string arg)
{
	object me, room, fire;
	me = this_player();
        if (!(fire=present("fire", me)))  return 0;
	if ( !arg || arg =="") return 0;
	if ( arg != "fire" ) return 0;
	write(	"  ���ȼ�˻��ۣ�������ǰ��һ������Ķ���������µ�ǧ��֮�ڡ�\n"
		"����������ɽ���ıڲ쿴��ʯ���Ͽ���һЩͼ�κ����֣����ִ���\n"
		"���������ɵ�ǰ������ħ�̳����ڴˣ���ħ�̳�����ɱ��ħ�̳��ϱ�\n"
		"���ڴˣ��������޶�������Щͼ����ħ�̳��ϻ����������ɵ�ǰ����\n"
		"�е�ͼ�Ρ�\n");
	if ( !(room == find_object(__DIR__"hole-1")) )
		room = load_object(__DIR__"hole-1"); 
	{
	set("exits/east", __DIR__"hole-1");
	me->set_temp("marks/study",0);
	me->add_temp("marks/study",1);
	fire->move(environment(me));
	destruct(fire);
	fire = new(__DIR__"obj/firing");
	fire->move(me);
	remove_call_out("close_out");
    call_out("close_out",120);
	}
	return 1;
}

void close_out()
{
	object room;
	if ( !(room == find_object(__DIR__"hole-2")) )
		room = load_object(__DIR__"hole-2"); 
	room->delete("exits/east");
}

int do_study(string arg)
{
        object me, fire;
        me = this_player();
        if (!(fire=present("fire", me)))  return 0;
	if ( me->query_temp("marks/study") < 1) return 0;
        if ( !arg || ( arg != "pictures" ) )  return 0;
        if ( (int)me->query_skill("literate") < 30 )
		{
                write("��ĺ���ѧʶ̫�٣��޷�����ͼ���ϵĸ���Ľ�����\n");
		return 1;
		};
        if ( (int)me->query("jing") < 40)
		{
                write("���Ѿ����۵��ˣ�����Ϣһ�°ɡ�\n");
		return 1;
		}

	if ( (int)me->query_skill("sword",1) < 50 )
		{
                write("��Ľ������̫ǳ���޷�����ͼ���ϵĸ���Ľ�����\n");
		return 1;
		}
        me->add("jing", (-1)*random(40));
        message_vision("$N��ר���о�ʯ���ϵ�ͼ�Ρ�\n", me);
	if ( (int)me->query_skill("sword", 1) < 101)
	{
	        me->improve_skill("sword", random(me->query("int")) );
	        write("�����ʯ���ϵ�ͼ����ĥ��һ�ض����ƺ��Խ����е��ĵá�\n");
        }
	else
	        write("�����ʯ���ϵ�ͼ����ĥ��һ�ض�������ûʲô��˼�����ܶ�������˵̫ǳ�ˡ�\n");
	return 1;
}
