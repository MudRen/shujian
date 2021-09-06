//gold-falun.c ����
//by iceland
#include <weapon.h>
#include <ansi.h>
inherit HAMMER;
inherit F_UNIQUE;
void create()
{
        set_name(HIY"����"NOR,({ "jin falun","gold falun" ,"lun" ,"falun","jinfalun" }));
        set_weight(25000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long","����һ���ƽ�����ķ��֣�Լ�г߰��С�������������ڷ�ħ���ԣ��ڲؾŸ�С���Ǹ�ɮ�������õ�һ�ַ�����\n");
                set("value", 3000);
                set("unique", 1);
                set("rigidity", 8);
                set("sharpness", 5);
                set("treasure",1);  
                set("weapon_prop/dodge", -8);
                set("weapon_prop/parry", 10);     
                set("material", "gold");
                set("wield_neili", 500);
                set("wield_maxneili", 1500);
                set("wield_str", 35);
                set("wield_msg", "$N�ӻ����ͳ�һ��$n���˵�������������У������������á�\n");
                set("unwield_msg","$N�����е�$n���ػ��С�\n");
        }
        init_hammer(75);
        setup();
}

void init()
{
    add_action("do_add",({"zuhe", "���"}));
}

int do_add()
{
     object me,ob,ob2,ob3,ob4,ob5,falun;
     me = this_player();
     if ((int)me->query_skill("longxiang-boruo",1) <150 )
           return notify_fail("�������������ھŲ���Ϊ��δ�ڻ��ͨ���޷���Ϸ��֡�\n");
     ob = this_object();
     ob2 = present("silver falun", me);
     ob3 = present("bronze falun", me);
     ob4 = present("iron falun", me);
     ob5 = present("leaden falun", me);
     if( !objectp(ob2) || !objectp(ob3)
      || !objectp(ob4) || !objectp(ob5))
           return notify_fail("�����еķ��ֲ�������ϳɷ���֡�\n");
     falun = unew(BINGQI_D("bestfalun"));
     if(!clonep(falun)) return notify_fail("��ͻȻ�������еķ��ֿ�ס�ˣ�������������ˡ�\n");
     message_vision(HIY"������ͭ������Ǧ��ֻ����˸Ȼ���⣬�������������Ǽ�������һ�����һֻ���Ӵ�ķ��֡�\n"NOR, me);
     destruct(ob2);
     destruct(ob3);
     destruct(ob4);
     destruct(ob5);   
     falun->move(me);
     destruct(ob);
     return 1;
}
