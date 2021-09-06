#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HBBLU"����"NOR);
        setup();
}

void init()
{
     object me = this_player();
     object env = me->query("lastroom");
if(!userp(me)) return ;
     me->move(env);
     me->start_busy(1);
     switch(random(8)) {
       case 0: //��
         me->start_busy(10);
         message_vision(HIR"$N̤�롰�ݡ��ţ�ֻ���ýŲ�������������ʩ��\n"NOR, me);
        break;
       case 1: //��
         if (env->query("th_buzhen")) {
         env->set("long", env->query("org_desc"));
         env->set("exits", env->query("org_exits"));
         env->delete("org_desc");
         env->delete("org_exits");
         env->delete("th_buzhen");
         env->delete("th_pozhen");
         env->delete("th_zhen_owner");
         }
         message_vision(HIG"$N̤�롰�����ţ��ƽ�������󷨣�\n"NOR, me);
        break;
       case 2: //��
         me->set_temp("last_damage_from", "�ܵ��������л��ع�����");
         me->receive_wound("qi",100+random(100));
         message_vision(HIY"$N̤�롰�ˡ��ţ����л���ͻȻ������$N��ʱ���˵��ˣ�\n"NOR, me);
        break;
       case 3: //��
         me->set("neili",0);
         message_vision(HIB"$N̤�롰�š��ţ�ֻ�����������أ��ľ������������˻�ԭλ��\n"NOR, me);
        break;
       case 4: //��
         me->set_temp("last_damage_from", "�ܵ��������л�Ӱ������־");
         me->receive_wound("jing",100+random(100));
         message_vision(HIM"$N̤�롰�����ţ���Ȼ��ǰ���ֻ�Ӱ��ͷ����ѣ����֪�����Ļص���ԭ�ء�\n"NOR, me);
        break;
       case 5: //��
         message_vision(HBRED"$N̤�롰�����ţ�ͻȻ��ʧ��ì����ҩ����ȫ������������\n"NOR, me);
         if (random(me->query_dex()) > 3) {
            message_vision(HBRED"$N���ܲ���������������\n"NOR, me);
            me->set_temp("last_damage_from", "̤��������С������Ŷ�");
            me->die();
         } else {
            message_vision(HBRED"$Nƴ���ֿ�����Ȼ�ӳ����죬Ԫ���Ѿ��Ǵ���\n"NOR, me);
            me->add("max_neili", -2-random(4));
         }
        break;
       case 6: //��
         me->set_temp("last_damage_from", "�ܵ��������пɲ������");
         me->add("jingli",-100-random(100));
         message_vision(HIW"$N̤�롰�����ţ�������һ��������ȫ������������ֽ����æ�˻أ�\n"NOR, me);
        break;
       case 7: //��
         message_vision(HIC"$N̤�롰�����ţ���֪��Ϊ������һȦ���߻���ԭ�ء�\n"NOR, me);
        break;
     }
}

