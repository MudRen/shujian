//houyuan.c

inherit ROOM;
#include <ansi.h>
#define QUESTDIR "quest/���Ǿ�/"
#define QUESTDIR1 "quest/���Ǿ�/ѩ�ȼ���ƪ/"
#define QUESTDIR2 "quest/���Ǿ�/���̽��ƪ/"

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
��������ƺ���һ����Ժ�ˣ����ܶ���������ƺ��ܾ�û��������ԶԶ
��ȥ�ǹ�����ů��Ĵ��ڡ�ֻ������ǽ���ƺ���Щ��֡�����ǽ�ܸо�������
��һ��������ǽȷ������һС�����䣬�ƺ����ԴӶ������ȥ��
LONG
    );
        setup();
}
void init()
{
	add_action("do_jump", ({"jump", "tiao"}));
	add_action("do_enter", ({"zuan"}));
	add_action("do_wa", ({"wa"}));
}
int do_jump(string arg)
{
	object room,me = this_player();
    if( arg == "chuang" || arg == "window" || arg == "chuanghu" || arg == "chuangkou")
    {
		if(me->query_skill("dodge")<100) 
		{
			message_vision(HIY"\n$N����һ��������Ӵ�������ȥ��\n"NOR,me);
			return notify_fail("����ɽ��ǰ����һ�죺��λ"+RANK_D->query_respect(me) +"����Ҫ��ʲô����");
		}
		if (!(room = find_object(__DIR__"woshi")))
			room = load_object(__DIR__"woshi");
		if(!room)
		{ 
			tell_object(me,HIR"\n��������ô�������ֶ�����ԭ��!\n");
			log_file("quest/LCHJ", sprintf("%s(%s)ȱ��woshi.c�ļ���\n", me->name(1),me->query("id")) );	
		}
		else
		{
			message_vision(HIY"\n$N����һ������������ɽ��ע�⣬ͻȻֱ�ӴӴ������˽�ȥ��\n"NOR, me);
			me->move(room);
			me->start_busy(1);
			tell_room(environment(me),"\nֻ��һ����Ӱ���������ԭ����"+me->name()+"�Ӵ��������˽�����\n"NOR, ({me}));                       	
		}
		return 1;
	}
	return 0;
}
int do_enter(string arg)
{
	object room,me = this_player();
    if( arg == "dong" )
    {
		if (!(room = find_object(__DIR__"citang")))
			room = load_object(__DIR__"citang");
		if(!room)
		{ 
			tell_object(me,HIR"\n��������ô�꣬���ֶ�����ԭ��!\n");
			log_file("quest/LCHJ", sprintf("%s(%s)ȱ��citang.c�ļ���\n", me->name(1),me->query("id")) );	
		}
		else
		{
			message_vision(HIY"\n$N����̽���������Ӷ������˽�ȥ��\n"NOR, me);
			me->move(room);
			me->start_busy(1);
			tell_room(environment(me),"\nֻ��һ���˴�һ���������˳�����ԭ����"+me->name()+"��\n"NOR, ({me}));                       	
		}
		return 1;
	}
	return 0;
}
int do_wa(string arg)
{
	object me = this_player();
	if(!arg || arg!="qiang") 
		return notify_fail("��Ҫ��ʲô��\n");
	if(!present("gao tou",me))
		return notify_fail("û�и�ͷ����ô��ǽ��\n");
	if(!me->query_temp(QUESTDIR2+"askqiqiang" ))
		return notify_fail("��Ե�޹ʣ�����ǽ��ʲô��\n");
	if(!me->query_temp(QUESTDIR2+"askwan_diyun" ))
		return notify_fail("��Ե�޹ʣ�����ǽ��ʲô��\n");
	if(!me->query_temp(QUESTDIR2+"askwan_qi" ))
		return notify_fail("��Ե�޹ʣ�����ǽ��ʲô��\n");
	if(me->query_temp(QUESTDIR2+"waqiang" ))
		return notify_fail("���Ѿ���������������ˡ�\n");
	if(me->is_busy())
		return notify_fail("���������ء�\n");
	if(me->query_temp(QUESTDIR2+"wa_qiang_ing" )<=5)
	{
        message_vision(HIC"\n$N��ǽ���������˼��£��������ͷ��ǽ����һ�ǡ�\n"NOR, me);
		tell_object(me,RED"һ���������۵���ͷ�󺹣�\n"NOR);
		me->start_busy(3);
		me->add_temp(QUESTDIR2+"wa_qiang_ing",1);
		return 1;
	}
	message_vision(HIY"\n$N��ǽ���������˼��£�Ȼ�������ͷ��ǽ���˿�����\n"NOR, me);
	message_vision(HBYEL"\n$N��Ȼ����ǽ�ھ�Ȼ�����пա�\n"NOR, me);
	tell_object(me,CYN"\n�����������õ���������˵û������ɽ�����ݳ������޻����ơ�\n"NOR);
	tell_object(me,CYN"ֻ�ǣ����Ǿ������ܾ�����ʲô�ط��أ�\n"NOR);
	me->start_busy(1);
	me->set_temp(QUESTDIR2+"waqiang",1);
	return 1;	
}

