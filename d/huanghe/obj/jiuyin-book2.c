#include <ansi.h>
inherit ITEM;
inherit F_AUTOLOAD;

int query_autoload(){return 1;}

void create()
{
        set_name(HIB"�����澭�¾�"NOR, ({ "jiuyin zhenjing", "xiajuan", "book"}));
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"�������𽭺�֮�����澭���¾�������ж����µļ��ܣ�\n"
"������         (cuixin-zhang) \n""�����׹�צ (jiuyin-baiguzhua) \n"
);
                set("treasure", 1);
                set("unique", 1);
                set("value", 0);
                set("material", "skin");
                set("no_drop", 1);
                set("no_give", 1);
                set("no_get", 1);
                set("no_steal", 1);
        }
}

void init()
{
    add_action("do_study",({"study", "du", "read"}));
}

int do_study(string arg)
{
    int cost, my_skill;
    object me=this_player();
    object where = environment(me);
    if (!arg) return notify_fail("��Ҫ��ʲô��\n");
    if (me->is_busy())
        return notify_fail("��������æ���ء�\n");
    if (where->query("sleep_room"))
        return notify_fail("���Ҳ��ܶ��飬��Ӱ�������Ϣ��\n");
    if( me->is_fighting() )
        return notify_fail("���޷���ս����ר�������ж���֪��\n");
    if( !me->query_skill("literate", 1) )
        return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
    if( (int)me->query("potential") < 1 )
        return notify_fail("���Ǳ���Ѿ������ˣ�����ô��Ҳû�á�\n");
    if( (int)me->query("combat_exp") < 1000000 )
        return notify_fail("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
    if( me->query_int() < 35 )
        return notify_fail("����Ŀǰ��������������û�а취ѧ������ܡ�\n");

    cost = 40 * ( 1 + ( 35 - (int)me->query("int"))/20 );
    if (cost < 20) cost = 20;
    me->set_temp("last_damage_from", "�ж������书�������Ļ���");

    switch (arg) {
         case "jiuyin-baiguzhua":
              my_skill = me->query_skill("jiuyin-baiguzhua", 1);
              if( my_skill >=150)
                 write("������⾭������д���Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n");
              if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
                 write("Ҳ����ȱ��ʵս���飬��Ծ���������˵�Ķ��������޷���ᡣ\n");
              else write("���ж����йؾ����׹�צ�ļ��ɣ��ƺ���Щ�ĵá�\n");
          me->improve_skill("jiuyin-baiguzhua", ((int)me->query_skill("literate", 1)/5+1) );
          me->receive_damage("jing", cost );
          if(me->query_skill("jiuyin-baiguzhua",1)<150)
               me->add("potential", - random(2));
         break;             
         case "cuixin-zhang":
              my_skill = me->query_skill("cuixin-zhang", 1);
              if( my_skill >=150)
                 write("������⾭������д���Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n");
              if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
                 write("Ҳ����ȱ��ʵս���飬��Ծ���������˵�Ķ��������޷���ᡣ\n");
              else write("���ж����йش����Ƶļ��ɣ��ƺ���Щ�ĵá�\n");
          me->improve_skill("cuixin-zhang", ((int)me->query_skill("literate", 1)/5+1) );
          me->receive_damage("jing", cost );
          if(me->query_skill("cuixin-zhang",1)<150)
               me->add("potential", - random(2));
         break;
    }
    return 1;
}

