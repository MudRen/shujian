#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��ɽ");
        set("long", @LONG
����ֱ������ʮ���⣬����ֹ����ֻ������
����һ����ɽ֮�С�ĺ���ĺϣ���ѻ����
��Ҫ�뿪�͸Ͻ��뿪(leave)�ɡ�
LONG
        );

 set("outdoors", "shaolin");    
set("no_fight", 1);
   set("exits", ([
                 "leave" : "/d/wudang/houyuan",
]));
   setup();
}
void init()
{
        object me = this_player(), ob;

       

        add_action("do_look", "xun");
       add_action("do_fire", "shi");

        if (me->query_temp("wdjiuyang2"))
        {
		
                tell_object(me, HIG "����ɮ������ǿ����һ���������ۣ�ȴҲ�ѽ�ƣ���ߣ�\n"
                                    "һʱ֮�䣬��Ҳ��������Ͱж�¼�����\n"NOR);

        }
        return 0;
}
int do_look(string arg)
{
object me = this_player();
if (!me->query_temp("wdjiuyang2"))
 return notify_fail("������ô���ģ�\n");
if (arg != "caomei" )
return notify_fail("��Ҫ��ʲô��\n");
 if (me->is_busy() || me->is_fighting())
return notify_fail("����æ���ء�\n");
 if ( (int)me->query("jingli")<400)
             {
                     write("������̫���ˣ���Ϣһ�°ɣ�\n");
             return 1;
             } 

        if(random(10) > 3)
             {
             me->add("jingli",-random(300));
             return notify_fail("���ۼ������ﳤ����ϥ�������Ұɽ�أ����������Եġ�\n"); 
}
 message_vision(HIG"$Nȥ�˰��գ�ֻ�ɵ�һ��Ѳ�ݮ�������˺��ҳ��ˣ���ʯ��Ϣ��\n"NOR, me);
 me->start_busy(random(5));
me->delete_temp("wdjiuyang2");
me->set_temp("wdjiuyang3",1);
return 1;
	
}
int do_fire(string arg)
{
object me = this_player();
if (!me->query_temp("wdjiuyang3"))
return notify_fail("������ô���ģ�\n");
if (arg != "kuchai" )
return notify_fail("��Ҫ��ʲô��\n");
 if (me->is_busy() || me->is_fighting())
return notify_fail("����æ���ء�\n");
message_vision(RED"$NʰЩ�ݲ����˸��𣬿�����Ů���Լ����ϵ��·������˱��ڴ���֮��˯�ˡ�
\n"NOR, me);
me->delete_temp("wdjiuyang3");
remove_call_out("meet");
        call_out("meet", 2, me);
        return 1;
}
int meet(object me)
{
me = this_player();
tell_object(me,HIG"\n˯����ҹ����������ɮ������������������������������ֻ���������������\n"NOR);  
tell_object(me,HIG"��������֮��������֮Ƥë����֮������˹������֧�ţ�һ����ͨ��\n"
                     "���������飬������ȥ�����������顣������ȥ������\n"NOR);  
tell_object(me,HIG"\nֻ������һ�٣��������\n"
                     "�в����洦�����ɢ�ң��䲡��������֮������\n"NOR);
                  
tell_object(me,HIR"\n������һ�ݣ������е�Ī�Ǿ��������˿��г��ᵽ��......\n"NOR);  
tell_object(me,HIW"\n���ں�˼���룬��Ȼһ����Ͱ�����ѣ��������۾���ԭ����������������ߡ�\n"NOR); 
me->set_temp("wdjiuyang4",1);
me->move("/d/wudang/houyuan");

        return 1;
}
