// emei-jiuyin.c 
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIG"�����澭�ٳ�ƪ"NOR, ({ "jiuyin sucheng", "book"}));
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�������𽭺�֮�����澭���ٳ�ƪ��������ж����µļ��ܣ�\n"
                            "������       (jiuyin-shenfa) \n"
                            "�����湦       (jiuyin-zhengong) \n"
                            "���¾�         (daode-jing) \n"
                            "������         (cuixin-zhang) \n"
                            "����������     (yinlong-bian) \n"
                            "�����׹�צ     (jiuyin-baiguzhua) \n"
                );
                set("treasure", 1);
                set("unique", 1);
                set("value", 0);
                set("material", "paper");
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

       if(where->query("sleep_room")|| where->query("no_fight"))
          return notify_fail("�����㲻�ܶ��顣\n");

       if( me->is_fighting() )
            return notify_fail("���޷���ս����ר�������ж���֪��\n");

       if( !me->query_skill("literate", 1) )
            return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");

       if(! me->query("quest/jiuyin2/pass"))
          return notify_fail("�������͵���ľ����澭���޷��ж���\n");

       if( this_object()->query("owner") != me->query("id"))
          return notify_fail("�������͵���ľ����澭���޷��ж���\n");

       if( (int)me->query("potential") < 1 )
            return notify_fail("���Ǳ���Ѿ������ˣ�����ô��Ҳû�á�\n");

       if( (int)me->query("combat_exp") < 1000000 )
            return notify_fail("���ʵս���鲻�㣬����ô��Ҳû�á�\n");

       if( me->query_int(1) < 35 )
            return notify_fail("����Ŀǰ��������������û�а취ѧ������ܡ�\n");

       cost = 40 * ( 1 + ( 35 - (int)me->query("int"))/20 );
       if (cost < 20) cost = 20;
       me->set_temp("last_damage_from", "�ж������书�������Ļ���");
      
       if( me->query("neili") < cost * 2 + 300)
           return notify_fail("��������������޷����������ܡ�\n");

       switch (arg) {
         case "jiuyin-baiguzhua":
            my_skill = me->query_skill("jiuyin-baiguzhua", 1);
            if( my_skill >= 180)
                return notify_fail("������⾭������д���Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n");
            if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
                return notify_fail("Ҳ����ȱ��ʵս���飬��Ծ���������˵�Ķ��������޷���ᡣ\n");
            else write("���ж����йؾ����׹�צ�ļ��ɣ��ƺ���Щ�ĵá�\n");
            me->improve_skill("jiuyin-baiguzhua", ((int)me->query_skill("literate", 1)/5+1) );
            me->receive_damage("jing", cost );
            me->add("neili", -cost * 2);
            me->add("potential", - random(2));
            break;             
         case "cuixin-zhang":
            my_skill = me->query_skill("cuixin-zhang", 1);
            if( my_skill >= 180)
                return notify_fail("������⾭������д���Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n");
            if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
                return notify_fail("Ҳ����ȱ��ʵս���飬��Ծ���������˵�Ķ��������޷���ᡣ\n");
            else write("���ж����йش����Ƶļ��ɣ��ƺ���Щ�ĵá�\n");
            me->improve_skill("cuixin-zhang", ((int)me->query_skill("literate", 1)/5+1) );
            me->add("neili", -cost * 2);
            me->receive_damage("jing", cost );
            me->add("potential", - random(2));
            break;
         case "jiuyin-shenfa":
            my_skill = me->query_skill("jiuyin-shenfa", 1);
            if( my_skill >= 180)
                return notify_fail("������⾭������д���Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n");
            if( my_skill >= me->query_skill("daode-jing",1))
                return notify_fail("��ĵ��¾�̫ǳ������ѧ��ʲô������\n");
            else
            if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
                return notify_fail("Ҳ����ȱ��ʵս���飬��Ծ���������˵�Ķ��������޷���ᡣ\n");
            else write("���ж����йؾ������ļ��ɣ��ƺ���Щ�ĵá�\n");
            me->improve_skill("jiuyin-shenfa", ((int)me->query_skill("literate", 1)/5+1) );
            me->add("neili", -cost * 2);
            me->receive_damage("jing", cost );
            me->add("potential", - random(2));
            break;
         case "jiuyin-zhengong":
            my_skill = me->query_skill("jiuyin-zhengong", 1);
            if( my_skill >= 180)
                return notify_fail("������⾭������д���Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n");
            if( my_skill >= me->query_skill("daode-jing",1))
                return notify_fail("��ĵ��¾�̫ǳ������ѧ��ʲô������\n");
            else
            if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
                return notify_fail("Ҳ����ȱ��ʵս���飬��Ծ���������˵�Ķ��������޷���ᡣ\n");
            else write("���ж����йؾ����湦�ļ��ɣ��ƺ���Щ�ĵá�\n");
            me->improve_skill("jiuyin-zhengong", ((int)me->query_skill("literate", 1)/5+1) );
            me->add("neili", -cost * 2);
            me->receive_damage("jing", cost );
            me->add("potential", - random(2));
            break;
         case "yinlong-bian":
            my_skill = me->query_skill("yinlong-bian", 1);
            if( my_skill >= 180)
                return notify_fail("������⾭������д���Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n");
            if( my_skill >= me->query_skill("daode-jing",1))
                return notify_fail("��ĵ��¾�̫ǳ������ѧ��ʲô������\n");
            else
            if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
                return notify_fail("Ҳ����ȱ��ʵս���飬��Ծ���������˵�Ķ��������޷���ᡣ\n");
            else write("���ж����йؾ��������޵ļ��ɣ��ƺ���Щ�ĵá�\n");
            me->improve_skill("yinlong-bian", ((int)me->query_skill("literate", 1)/5+1) );
            me->add("neili", -cost * 2);
            me->receive_damage("jing", cost );
            me->add("potential", - random(2));
            break;
         case "daode-jing":
            my_skill = me->query_skill("daode-jing", 1);
            if( my_skill >= 180)
                return notify_fail("������⾭������д���Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n");
            write("���ж��ŵ��¾����ƺ���Щ�ĵá�\n");
            me->improve_skill("daode-jing", ((int)me->query_skill("literate", 1)/5+5) );
            me->receive_damage("jing", cost );
            me->add("potential", - random(2));
            break;
       }
       return 1;
}

