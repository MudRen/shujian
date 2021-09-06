#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"�����澭"NOR, ({ "jiuyin zhenjing", "book"}));
        set_weight(1000);
        if( clonep())
               set_default_object(__FILE__);
        else {
               set("unit", "��");
               set("long", HIC"�������𽭺�֮�����澭��������ж����µļ��ܣ�\n"
                           HIM"�����湦     (jiuyin-zhengong) ������    (jiuyin-shenfa) \n"
                           HIB"������צ     (jiuyin-shenzhua) ��������    (jiuyin-shenzhang) \n"
                           HIY"��������     (xuanyin-jian)    ����������  (yinlong-bian) \n"
                           HIG"���ħȭ��   (dafumo-quanfa)   ���¾�      (daode-jing)\n"NOR
               );
               set("value", 0);
               set("unique", 1);
               set("treasure", 1);
               set("material", "paper");
               set("no_drop", 1);
               set("no_give", 1);
               set("no_get", 1);
               set("no_steal", 1);
        }
}

void init()
{
        add_action("do_study", "read" );
}

int do_study(string arg)
{
        int cost, my_skill;
        object me=this_player();
        object where = environment(me);

        if (!arg) return notify_fail("��Ҫ��ʲô��\n");

        if ( me->is_busy())
             return notify_fail("��������æ���ء�\n");

        if (where->query("sleep_room") || where->query("no_fight"))
             return notify_fail("�����㲻�ܶ��顣\n");

        if( me->is_fighting())
             return notify_fail("���޷���ս����ר�������ж���֪��\n");

        if(! me->query("quest/jiuyin1/owner"))
          return notify_fail("�������͵���ľ����澭���޷��ж���\n");

        if( this_object()->query("owner") != me->query("id"))
          return notify_fail("�������͵���ľ����澭���޷��ж���\n");

        if( !me->query_skill("literate", 1) )
             return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");

        if( (int)me->query("potential") < 1 )
             return notify_fail("���Ǳ���Ѿ������ˣ�����ô��Ҳû�á�\n");

        if( (int)me->query("combat_exp") < 1000000 )
             return notify_fail("���ʵս���鲻�㣬����ô��Ҳû�á�\n");

        if( me->query_int() < 40 )
             return notify_fail("����Ŀǰ��������������û�а취ѧ������ܡ�\n");

        cost = 40 * ( 1 + ( 35 - (int)me->query("int"))/20 );
        if (cost < 20) cost = 20;

        if( me->query("neili") < cost * 2 + 300)
          return notify_fail("��������������޷����������ܡ�\n");
        me->set_temp("last_damage_from", "�ж������书�������Ļ���");

        switch (arg){
         case "jiuyin-zhengong":
              my_skill = me->query_skill("jiuyin-zhengong", 1);
              if( my_skill >= 220)
                 return notify_fail("������⾭������д���Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n"); else
              if( my_skill >= me->query_skill("daode-jing",1))
                 return notify_fail("��ĵ��¾�̫ǳ������ѧ��ʲô������\n"); 
              if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
                 return notify_fail("Ҳ����ȱ��ʵս���飬��Ծ���������˵�Ķ��������޷���ᡣ\n");
              else
                 write("���ж��ž����湦���ƺ���Щ�ĵá�\n");
              me->improve_skill("jiuyin-zhengong", ((int)me->query_skill("literate", 1)/5+1) );
              me->receive_damage("jing", cost );
              me->add("neili", -cost * 2);
              me->add("potential", - random(2));
              break;             
         case "jiuyin-shenfa":
              my_skill = me->query_skill("jiuyin-shenfa", 1);
              if( my_skill >= 200)
                 return notify_fail("������⾭������д���Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n");
              if( my_skill >= me->query_skill("daode-jing",1))
                 return notify_fail("��ĵ��¾�̫ǳ������ѧ��ʲô������\n"); 
              if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
                 return notify_fail("Ҳ����ȱ��ʵս���飬��Ծ���������˵�Ķ��������޷���ᡣ\n");
              else
                 write("���ж����йؾ������ļ��ɣ��ƺ���Щ�ĵá�\n");
              me->improve_skill("jiuyin-shenfa", ((int)me->query_skill("literate", 1)/5+1) );
              me->receive_damage("jing", cost );
              me->add("neili", -cost * 2);
              me->add("potential", - random(2));
              break;
         case "jiuyin-shenzhua":
              my_skill = me->query_skill("jiuyin-shenzhua", 1);
              if( my_skill >= 200)
                 return notify_fail("������⾭������д���Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n");
              if( my_skill >= me->query_skill("daode-jing",1))
                 return notify_fail("��ĵ��¾�̫ǳ������ѧ��ʲô������\n");
              else if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
                 return notify_fail("Ҳ����ȱ��ʵս���飬��Ծ���������˵�Ķ��������޷���ᡣ\n");
              else write("���ж����йؾ�����צ�ļ��ɣ��ƺ���Щ�ĵá�\n");
              me->improve_skill("jiuyin-shenzhua", ((int)me->query_skill("literate", 1)/5+1) );
              me->receive_damage("jing", cost );
              me->add("neili", -cost * 2);
              me->add("potential", - random(2));
              break;             
         case "jiuyin-shenzhang":
              my_skill = me->query_skill("jiuyin-shenzhang", 1);
              if( my_skill >= 200)
                 return notify_fail("������⾭������д���Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n"); else
              if( my_skill >= me->query_skill("daode-jing",1))
                 return notify_fail("��ĵ��¾�̫ǳ������ѧ��ʲô������\n"); 
              if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
                 return notify_fail("Ҳ����ȱ��ʵս���飬��Ծ���������˵�Ķ��������޷���ᡣ\n");
              else write("���ж����йؾ������Ƶļ��ɣ��ƺ���Щ�ĵá�\n");
              me->improve_skill("jiuyin-shenzhang", ((int)me->query_skill("literate", 1)/5+1) );
              me->receive_damage("jing", cost );
              me->add("neili", -cost * 2);
              me->add("potential", - random(2));
              break;             
         case "dafumo-quan":
              my_skill = me->query_skill("dafumo-quan", 1);
              if( my_skill >= 200)
                 return notify_fail("������⾭������д���Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n"); else
              if( my_skill >= me->query_skill("daode-jing",1))
                 return notify_fail("��ĵ��¾�̫ǳ������ѧ��ʲô������\n");
              if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
                 return notify_fail("Ҳ����ȱ��ʵս���飬��Ծ���������˵�Ķ��������޷���ᡣ\n");
              else write("���ж����йش��ħȭ���ļ��ɣ��ƺ���Щ�ĵá�\n");
              me->improve_skill("dafumo-quan", ((int)me->query_skill("literate", 1)/5+1) );
              me->receive_damage("jing", cost );
              me->add("neili", -cost * 2);
              me->add("potential", - random(2));
              break;             

         case "xuanyin-jian":
              my_skill = me->query_skill("xuanyin-jian", 1);
              if( my_skill >= 200)
                 return notify_fail("������⾭������д���Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n"); else
              if( my_skill >= me->query_skill("daode-jing",1))
                 return notify_fail("��ĵ��¾�̫ǳ������ѧ��ʲô������\n");
              if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
                 return notify_fail("Ҳ����ȱ��ʵս���飬��Ծ���������˵�Ķ��������޷���ᡣ\n");
              else write("���ж����й����������ļ��ɣ��ƺ���Щ�ĵá�\n");
              me->improve_skill("xuanyin-jian", ((int)me->query_skill("literate", 1)/5+1) );
              me->receive_damage("jing", cost );
              me->add("neili", -cost * 2);
              me->add("potential", - random(2));
              break;             
         case "yinlong-bian":
              my_skill = me->query_skill("yinlong-bian", 1);
              if( my_skill >= 200)
                 return notify_fail("������⾭������д���Ѿ�̫ǳ�ˣ�����ѧ��ʲô������\n"); else
              if( my_skill >= me->query_skill("daode-jing",1))
                 return notify_fail("��ĵ��¾�̫ǳ������ѧ��ʲô������\n");
              if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
                 return notify_fail("Ҳ����ȱ��ʵս���飬��Ծ���������˵�Ķ��������޷���ᡣ\n");
              else write("���ж����йؾ��������޵ļ��ɣ��ƺ���Щ�ĵá�\n");
              me->improve_skill("yinlong-bian", ((int)me->query_skill("literate", 1)/5+1) );
              me->receive_damage("jing", cost );
              me->add("neili", -cost * 2);
              me->add("potential", - random(2));
              break;             
         case "daode-jing":
              my_skill = me->query_skill("daode-jing", 1);
          write("���ж��ŵ��¾����ƺ���Щ�ĵá�\n");
          me->improve_skill("daode-jing", ((int)me->query_skill("literate", 1)/5+5) );
          me->receive_damage("jing", cost );
          if(me->query_skill("daode-jing",1)>150)
               me->add("potential", - random(2));
          if(me->query_skill("daode-jing",1)>200)
               me->add("potential", - random(2));
          if(me->query_skill("daode-jing",1)>250)
               me->add("potential", - random(3));
          if(me->query_skill("daode-jing",1)>300)
               me->add("potential", - random(3));
         break;             
        }
        return 1;
} 
