
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(RED "��ȸ�ų���" NOR, ({ "zhuque chengmen", "chengmen" }) );         
        set_weight(30000000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("unit", "��");
set("long", @LONG
����һ�Ժ��صĳ��ţ������عر��ţ�����¥����һ�Ӷ���װ��ʿ��
������ȥ���������������ս������������ʧ��������˴�Ƭ�Ļ�
�أ�����ϡ�١�
LONG);
set("value",50000000); 
set("no_get",1);
set("defend",10);
        setup();
}
}
void init()
{
	
   add_action("do_recover", ({"buji", "bu"}));
}

int do_recover(string arg)
{
object me = this_player();
object ob = this_object();
if (!arg)
		return notify_fail("��Ҫ��ʲô����?\n");
	    
	if (arg!="����" && arg!="chengmen")
		return notify_fail("��Ҫ��ʲô����?\n");
if ( !me->query_temp("��������/������ս/��Ӫ") || me->query_temp("��������/������ս/��Ӫ") != 1)
return notify_fail("�㲻�ܸ����Ų���?\n");
if( me->is_busy() || me->is_fighting())
return notify_fail("������æ�úܣ����ܲ������š�\n");
if(ob->query("defend")>=50000 )
return notify_fail(""+ob->query("name")+"���ڲ���Ҫ������\n");
message_vision(WHT"$Nָ����һ���ξ�����һ���ľ�ϣ������ض�ס��"+ob->query("name")+WHT",��ʱȷ���˰�ȫ��\n"NOR, me);
ob->add("defend",random(30));
message_vision(HIG""+ob->query("name")+HIG"�ļ�����ӵ���"+ob->query("defend")+"��\n"NOR, me);
me->start_busy(random(4));
if(random(10)>6)
{
message_vision(RED"ͻȻ�ӳ��������֧�����$N��ߵļ����α��м����£�$N����������ҡ�\n"NOR, me);
me->add_busy(random(6));
}

return 1;
}

