// tianwang.c �������ĵ�
// Modify By Looklove@SJ 2000/1/15
#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
        set_name("�������ĵ�", ({"tianwang huxindan", "tianwang","huxindan","dan"}));
        if (clonep())
        set_default_object(__FILE__);
        else {
                set("value", 20000);
                set("unit", "Щ");
                set("long","����һ���������ĵ������ڽ⺮����\n");
                set("base_value", 20000);
                set("base_unit", "��");
                set("base_weight", 30);
        }
        set_amount(1);
}       

int init()
{
        add_action("do_eat", "fu");
} 

int do_eat(string arg)
{
        object me = this_player();
        object ob = this_object();

        if(!arg || arg!="dan")
                return notify_fail("��Ҫ��ʲô��\n");

        if (!me->query_condition("cold_poison"))
                return notify_fail("�����ڲ���Ҫ���������ĵ���\n");
        
        if(me->query_condition("cold_poison") > 1000)
                return notify_fail("�������ж�̫��������ĵ�û��ʲôЧ�á�\n");
                        
        if(me->query_condition("cold_poison") > 50){
                me->apply_condition("cold_poison", me->query_condition("cold_poison")-50);
                message_vision("$N����һ���������ĵ�����ɫ�������ö��ˡ�\n", me, ob);
                destruct(ob);
                return 1;
        }
        add_amount(-1);
        message_vision("$N������һ���������ĵ���\n", me, ob);
        me->clear_condition("cold_poison");
        write("����ɫ������ʼ��ת�����ϵĺ���Ҳ��ʼ�����ˡ�\n", me);
        destruct(ob);
        return 1;
}

