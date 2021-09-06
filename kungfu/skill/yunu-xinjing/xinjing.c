// xinjing.c 
// By River
// Modified by darken@SJ

#include <ansi.h>
inherit F_CLEAN_UP;
string *pictures=({
  HIY"��˼��"YEL"���"HIC"������"HIR"���¡�"HIB"���"MAG"��Ц"HIW,
  YEL"�ٳ"CYN"���֡�"HIG"��ϲ��"HIR"��ŭ��"HIY"�ٺá�"RED"�ٶ�"HIW,
  HIC"��˼"HIG"��"HIW"�񵡣�"HIB"����"MAG"��"HIY"��ɢ"HIW,
  HIR"����"YEL"��"BLU"����"MAG"����"RED"��"HIG"��ƣ"HIW,
  HIB"����"CYN"��"RED"���٣�"HIR"��Ц"HIC"��"BLU"����"HIW,
  MAG"���"YEL"��"HIR"���壬"RED"����"BLU"��"HIY"����"HIW,
  HIW"��ϲ"HIG"��"HIY"����"MAG"���ң�"HIC"��ŭ"HIR"��"HIB"����"HIG"����"HIW,
  HIG"���"RED"��"BLU"ר��"HIG"���Σ�"HIW"���"HIB"��"MAG"����"CYN"����"HIW
});
string exert_name(){ return HIW"��Ů�ľ�"NOR; }
int exert(object me)
{
        int skill;
        string picture;

        if((int)me->query("neili") < 500 ) 
                return notify_fail("�������������\n");

        if((int)me->query_temp("gm/xinjing")) 
                return notify_fail("���Ѿ����˹����ˡ�\n");

        if((int)me->query_skill("yunu-xinjing",1 ) < 100)
                return notify_fail("�����Ů�ľ��ȼ����������������ʮ���ٺ�ʮ����֮���\n");

        if( me->query_skill_mapped("force") != "yunu-xinjing")
                return notify_fail("�����ڲ���ʹ�á��ľ����־���\n");

        if( me->query("gender") == "����" )
                return notify_fail("���޸����ԣ������������Ů�ľ��ġ��ľ����־���\n");
                
        skill = (int)me->query_skill("yunu-xinjing", 1);
        if (skill > 250) skill = 250+ (skill-250)/5;
        me->add("neili", -(200+ random(200)));
        picture = pictures[random(sizeof(pictures))];
        message_vision(HIY"$N�������񣬿���Ĭ��"HIW"��"+picture+"��"HIY"����Ů�ľ�����Ҫ����\n" NOR, me);
 
        if( me->query_temp("tryhb")
        	&& me->query("kar") >25 
        	&& me->query("kar") <31
        	&& random(me->query("kar")) >20
         	&& random(me->query("pur")) >25
         	&& random(me->query("int")) >20 ) { 
                 		me->set("gmhb","pass");
       	            me->delete_temp("tryhb");
       	 message_vision("��ϲ��$N�ɹ����ù�Ĺ�ķ���ͨȫ�潣������Ů�����ĵ���˫����赣�\n", me);

           log_file("quest/gmhb",sprintf("%-18s�ɹ����ܹ�Ĺ����˫����赣�����%d����%d������%d��\n",
                    me->name(1)+"("+capitalize(getuid(me))+")",
                    me->query("kar"), 
                    me->query("int"),
                    me->query("pur")  ), me  );		
        			 
          }
          
        me->add_temp("apply/intelligence", skill/10);
        me->add_temp("apply/dexerity", skill/10);

        if (skill > 200) {
          me->add_temp("apply/attack", skill/5);
          me->add_temp("apply/damage", skill/8);
        }
        if( me->query("gender") == "Ů��" && skill >200)
        {
             me->add_temp("apply/dodge", skill/10);
             me->add_temp("apply/parry", skill/10);
             me->add_temp("apply/armor", skill/10);
        }
        else if( me->query("gender") == "����" && skill >200)
        {
             me->add_temp("apply/strike", skill/10);
             me->add_temp("apply/parry", skill/10);
             me->add_temp("apply/armor", skill/10);
        }

        me->set_temp("gm/xinjing", skill);
        me->start_call_out((:call_other,__FILE__,"remove_effect",me, me->query_skill("yunu-xinjing", 1)/3:),1);

       if( me->is_fighting() && userp(me)) me->start_busy(1+random(2));
        me->start_exert(2,"���ľ����־�");
        return 1;
}

void remove_effect(object me, int count)
{       
        int skill;
        if(!objectp(me)) return;
        if(objectp(me)
        && me->query_temp("gm/xinjing")
        && me->query_skill_mapped("force") == "yunu-xinjing"
        && count){   
                call_out("remove_effect", 1, me, --count);
                return;
        }
        skill = me->query_temp("gm/xinjing");
        me->add_temp("apply/intelligence", -skill/10);
        me->add_temp("apply/dexerity", -skill/10);
        if (skill > 200)
        {
            me->add_temp("apply/attack", -skill/5);
          me->add_temp("apply/damage", -skill/8);
        }
        if( me->query("gender") == "Ů��" && skill > 200)
        {
           me->add_temp("apply/dodge", -skill/10);
           me->add_temp("apply/parry", -skill/10);
           me->add_temp("apply/armor", -skill/10);
        }
        else if( me->query("gender") == "����" && skill >200)
        {
             me->add_temp("apply/strike", -skill/10);
             me->add_temp("apply/parry", -skill/10);
             me->add_temp("apply/armor", -skill/10);
        }
        me->delete_temp("gm/xinjing");
        tell_object(me, HIW"�����Ů�ľ����ľ����־��˹���ϣ��������ջص��\n"NOR);
}
