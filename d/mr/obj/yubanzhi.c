// yubanzhi.c ��ָ

#include <ansi.h>
#include <armor.h>
inherit FINGER;
void create()
{
        set_name(HIG "���ָ" NOR, ({ "yu banzhi", "banzhi",}));
        set("weight", 100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", HIG"�����ָ�̵ó��棬ͨ����̣���Ө�ɰ������̲�ס����(mo)����\n" NOR);
                set("value", 50000);
                set("no_get", 1);
                set("no_drop", 1);
                set("material", "jade");
                set("armor_type", "cloth");       
                set("armor_prop/armor", 5);
        }
        setup();
}

void init()
{                     
        object ob, me;
        ob = this_object();
        me = this_player();
        add_action("task", "mo");
        call_out("do_check", 2, ob);
}

int task(string arg)
{
        object me = this_player();
        int i;
        i = (int)me->query_temp("skill_lvl", 1);
        if( !me->query_temp("mr_job", 1) && !me->query_temp("mr_job_done"))
                return notify_fail("������û���κ�����\n"); 
        write("����������������ָ��ͻȻ������һ��С�����ֳ�����\n\n");
        write("\t\t͵ѧ"HIR"[touxue]"NOR"�书��"+HIY+me->query_temp("skill_target")+NOR"��"+to_chinese(i)+"����Ȼ��չʾ"HIC"[show]"NOR"��Ľ�ݸ���\n\n");
        return 1;
}

void do_check()
{
        object ob = this_object();
        object me = this_player();
        string skill;
        
        if( !interactive(me)) 
        {
                if(stringp( skill = me->query("doing_job") ))
                {
                        me->delete_skill(skill);
                 }                                          
         call_out("do_check", 2, ob);
         }
         else    call_out("do_check", 2, ob);
         return;
}       
         
