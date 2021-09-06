// By Spiderii@ty �����츳
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("��Ƥ", ({ "ren pi", "pi"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����Ƥ����������ʲô�ر�֮����\n");
                set("treasure", 1);
                set("unique", 1);
                set("value", 0);
                set("no_give", 1);
                set("no_get", 1);
                set("no_steal", 1);
                set("no_drop", 1);
                set("material", "skin");
        }
}

void init()
{
       if(this_player()->query("quest/jiuyin2/pass")){
         set_name(HIB"�����澭�¾�"NOR, ({ "jiuyin zhenjing", "xia juan", "book"}));
         set("unit", "��");
         set("long", "�������𽭺�֮�����澭���¾�������ж����µļ��ܣ�\n"
                     "������         (cuixin-zhang) \n"
                     "�����׹�צ     (jiuyin-baiguzhua) \n"
                     "����������     (yinlong-bian) \n"
         );
         add_action("do_study", "read");
       }
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

       if(! me->query("quest/jiuyin2/pass"))
          return notify_fail("�������͵���ľ����澭���޷��ж���\n");

       if( this_object()->query("owner") != me->query("id"))
          return notify_fail("�������͵���ľ����澭���޷��ж���\n");

       if( !me->query_skill("literate", 1) )
            return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");

       if((int)me->query("potential") < 1 )
            return notify_fail("���Ǳ���Ѿ������ˣ�����ô��Ҳû�á�\n");

       if((int)me->query("combat_exp") < 1000000 )
            return notify_fail("���ʵս���鲻�㣬����ô��Ҳû�á�\n");

       if( me->query_int() < 35 )
            return notify_fail("����Ŀǰ��������������û�а취ѧ������ܡ�\n");

       cost = 40 * ( 1 + ( 35 - (int)me->query("int"))/20 );
       if (cost < 20) cost = 20;
      
       if( me->query("neili") < cost * 2 + 300)
          return notify_fail("��������������޷����������ܡ�\n");

       me->set_temp("last_damage_from", "�ж������书�������Ļ���");
       switch (arg) {
         case "jiuyin-baiguzhua":
            my_skill = me->query_skill("jiuyin-baiguzhua", 1);
            if( my_skill >= 150)
                return notify_fail("������⾭������д���Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n");
        //�츳�������ʦ��Ӱ��Ч����  by spiderii@ty ..lsxk�뷨̫����̬��
        if(me->query("relife/quest/lwds")){
         if(random(100) > me->query("relife/quest/lwds")*10)
            write(HIC"�㾭��ת�����޺��������似��䲻�����ڵĵ���˲�������˾����׹�צ�ľ������ڡ�\n"NOR);
            me->set_skill("jiuyin-baiguzhua",150);
            }
            if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
                return notify_fail("Ҳ����ȱ��ʵս���飬��Ծ���������˵�Ķ��������޷���ᡣ\n");
            else
                write("���ж����йؾ����׹�צ�ļ��ɣ��ƺ���Щ�ĵá�\n");
            me->improve_skill("jiuyin-baiguzhua", ((int)me->query_skill("literate", 1)/5+1) );
            me->receive_damage("jing", cost );
            me->add("neili", -cost * 2);
            if(me->query_skill("jiuyin-baiguzhua",1) < 150)
              me->add("potential", - random(2));
            break;             
         case "cuixin-zhang":
            my_skill = me->query_skill("cuixin-zhang", 1);
            if( my_skill >= 150)
                return notify_fail("������⾭������д���Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n");
        //�츳�������ʦ��Ӱ��Ч����  by spiderii@ty ..lsxk�뷨̫����̬��
        if(me->query("relife/quest/lwds")){
         if(random(100) > me->query("relife/quest/lwds")*10)
            write(HIC"�㾭��ת�����޺��������似��䲻�����ڵĵ���˲�������˴����Ƶľ������ڡ�\n"NOR);
            me->set_skill("cuixin-zhang",150);
            }
            if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
                return notify_fail("Ҳ����ȱ��ʵս���飬��Ծ���������˵�Ķ��������޷���ᡣ\n");
            else
                write("���ж����йش����Ƶļ��ɣ��ƺ���Щ�ĵá�\n");
            me->improve_skill("cuixin-zhang", ((int)me->query_skill("literate", 1)/5+1) );
            me->receive_damage("jing", cost );
            me->add("neili", -cost * 2);
            if(me->query_skill("cuixin-zhang",1) < 150)
               me->add("potential", - random(2));
            break;
         case "yinlong-bian":
            my_skill = me->query_skill("yinlong-bian", 1);
            if( my_skill >= 150)
                return notify_fail("������⾭������д���Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n");
        //�츳�������ʦ��Ӱ��Ч����  by spiderii@ty ..lsxk�뷨̫����̬��
        if(me->query("relife/quest/lwds")){
         if(random(100) > me->query("relife/quest/lwds")*10)
            write(HIC"�㾭��ת�����޺��������似��䲻�����ڵĵ���˲�������˾��������޵ľ������ڡ�\n"NOR);
            me->set_skill("yinlong-bian",150);
            }
            if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
                return notify_fail("Ҳ����ȱ��ʵս���飬��Ծ���������˵�Ķ��������޷���ᡣ\n");
            else
                write("���ж����йؾ��������޵ļ��ɣ��ƺ���Щ�ĵá�\n");
            me->improve_skill("yinlong-bian", ((int)me->query_skill("literate", 1)/5+1) );
            me->receive_damage("jing", cost );
            me->add("neili", -cost * 2);
            if(me->query_skill("yinlong-bian",1) < 150)
               me->add("potential", - random(2));
            break;
    }
    return 1;
}

