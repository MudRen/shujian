// houshanty.c
// ��ɽ����ɽ��С·
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIG "ɽ��" NOR);
        set("long", @long
������һ����ʪ�����ɽ����������һ���ʯͷ��������ɽ���ĺ�ڣ���
������Լ�и����������Ρ�
long);
        set("outdoors", "��üɽ");
        set("exits",([
             "out":__DIR__"houshansl",
]));
        setup();
}

void init()
{
//     add_action("do_panzuo", "panzuo");
//     add_action("do_xiulian", "xiulian");
}

int do_panzuo(string arg)
{
    object me=this_player();
    if (me->is_busy())
        return notify_fail("��������æ���أ�\n");
    if (!arg && arg!="stone" && arg!="shitou" && arg!="shi" )
        return 0;
    message_vision("$N�������ڴ�ʯͷ���棬����ʯ�ڡ�\n", me);
    me->set_temp("marks", "����");
    return 1;
}

int do_xiulian()
{
    object me=this_player();
    if( me->query_temp("marks") != "����" )
        return 0;
    message_vision("$N�������ڴ�ʯͷ���棬����ʯ�ڣ����������˼��֮�С�\n", me);
    me->delete_temp("marks");
    me->start_busy(30);
    call_out("end_xiulian", 60, me);
    return 1;
}

void end_xiulian(object me)
{
	if (!me) return;
    message_vision("�������ã�$N������������\n", me);
    if( (int)me->query("emsujia") < 2 ) me->add("emsujia", 1);
    me->add("potential", me->query_skill("linji-zhuang",1)/10);
        if((int)me->query("potential", 1)> (int)me->query("max_pot", 1))
           me->set("potential", (int)me->query("max_pot", 1));
    me->add("combat_exp", me->query_skill("linji-zhuang",1)/30);
    return;    
}
