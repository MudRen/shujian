#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_drink", "drink");
}

void create()
{
        set_name(HIY"��佬"NOR, ({"yufeng jiang", "jiang"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ƿ");
                set("long", "����һ��Сƿ��,ɢ����һ��Ũ��������֮�����㲻�ɵ�����һ�ڿ�ˮ��\n");
                set("value", 1000000);
                set("no_drop", 1);
                set("no_get", 1);
                 }
        setup();
}

int do_drink(string arg)
{
        object me = this_player();

        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");

        if ( me->query_skill_mapped("force") != "yunu-xinjing" )
      {
       
                write("�����ڹ�����������佬���¶���û��ʲô���ã�\n");

                return 1;
            }  

         if ( me->query("max_neili") < 400 )
        {
    message_vision(HIR "$N������佬��ֻ�����ڸ��𣬿�ϧ������Ϊ��ȱ��û��ʲô���棡\n" NOR, me);
        }
        else if ( (int)me->query_condition("medicine" ) > 0 )
     
        {
         me->add("max_neili",-5);                         
           message_vision(HIR "$N������佬����ϧ��ʳ̫��̫�࣬ҩЧ�޷����գ���������������\n" NOR, me);
        }
         else if ((me->query_skill("force")*8 +  me->query("combat_exp",1)/1000 ) <= me->query("max_neili") )
        { 
                message_vision(HIR "$N������佬��ֻ����ҩ��ƽƽ����������������Ϊ�ˣ�\n" NOR, me);
        }
        else
        {
                me->add("max_neili", 1);
       message_vision(HIG "$N������彬��ֻ���û���������̹���ƺ�����������ߣ�\n" NOR, me);
              me->apply_condition("medicine", 60);
        }
        destruct(this_object());
        return 1;
}

