// beauty ��������
// 19991002001
// Update By lsxk@hsbbs 2007/6/5

#include <ansi.h>

inherit F_SSERVER;

string perform_name() {return MAG"��������"NOR;}

int calc_damage(int,int,object,object);

int perform(object me, object target)
{
        object weapon;
        string msg,result;
        int i,total,def,abs,gifts1,gifts2; 
        
        if( !target ) target = offensive_target(me);

        if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
                return notify_fail("���������С�ֻ����ս��ʱʹ�ã�\n");

        if(me->query("family/master_id")!="hong antong")
                return notify_fail("���������С�ֻ�а��˽���������ã�\n");

        if( objectp(weapon=me->query_temp("weapon")) ) {
                string *ids = weapon->parse_command_id_list();
                if (member_array("bishou", ids) == -1)                          
                        return notify_fail("���������ذ�ײ����á��������С���\n");
        }
        else {
                return notify_fail("���������ذ�ײ����á��������С���\n");
        }
        
        if( (int)me->query_skill("huagu-mianzhang", 1) < 150 )
                return notify_fail("��Ļ������ƻ���������������ʹ�á��������С���\n");

        if (me->query_skill_mapped("strike") != "huagu-mianzhang")
                return notify_fail("ֻ��ʹ�û�������ʱ����ʹ�á��������С���\n");

        if( (int)me->query_skill("shenlong-tuifa", 1) < 150 )
                return notify_fail("��������ȷ�����������������ʹ�á��������С���\n");

        if (me->query_skill_mapped("leg") != "shenlong-tuifa")
                return notify_fail("ֻ��ʹ�������ȷ�ʱ����ʹ�á��������С���\n");

        if( (int)me->query_skill("canglang-goufa", 1) < 150 )
                return notify_fail("��Ĳ��˹�������������������ʹ�á��������С���\n");

        if (me->query_skill_mapped("hook") != "canglang-goufa")
                return notify_fail("ֻ��ʹ�ò��˹���ʱ����ʹ�á��������С���\n");

        if( (int)me->query_skill("dulong-dafa", 1) < 150 )
                return notify_fail("��Ķ����󷨹������㣬�����á��������С���\n");

        if((int)me->query("jingli", 1) < 800)
                return notify_fail("�����ھ������㣬����ʹ�á��������С���\n");       

        if((int)me->query("neili", 1) < 1500) 
                return notify_fail("�������������㣬����ʹ�á��������С���\n");      
/*


        if(me->query("gender") == "����" ) 
                return notify_fail("����Ů����ô��ʹ�á��������С��أ�\n");
*/
        if( me->query_skill_mapped("force") != "dulong-dafa")
                return notify_fail("��������ʹ�õ��ڹ�ͬ��������ִ�������ʹ�á��������С���\n");


        me->add("jingli",-100);
        me->add("neili",-400);

         def = target->query_temp("apply/armor",1);
gifts1 = me->query("str") +  me->query("dex") +  me->query("con") +  me->query("int") ;
gifts2 = target->query("str") +  target->query("dex") +  target->query("con") +  target->query("int") ;

        msg = MAG"$N��$n��������֮����ƴ��ȫ��ʹ���շ��˲���֮�����������������С�"NOR;

        if((random((int)me->query_skill("canglang-goufa",1)) > (int)target->query_skill("parry",1)/3
         || random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/3
         || random(me->query_dex() )> target->query_con() /3)
         && (gifts1 + 3)>= gifts2
          ||!userp(target)){
                me->start_busy(1);
                total = 0;
                msg +=MAG "\n\n$Nʹ��һ�С�"HIM"��������"MAG"��������΢����������Ť�����㷴�ߣ���$nС����ȥ��\n"+
                          "����˳�Ʒ�������§ס$nͷ�������ֱ��ж�׼$n���Ļ�ȥ��\n"NOR;
                i = calc_damage((int)me->query_skill("huagu-mianzhang",1),(int)me->query_skill("canglang-goufa",1),me,target);
                                abs =  i * def /(1000+ def );
                total += i;
                if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",i));
                
                

                target->receive_damage("qi", i, me );
                target->receive_wound("qi", i/3 , me);
                result = COMBAT_D->damage_msg(i,"����");
                result = replace_string( result, "$l", "ͷ��" );
                msg += result;
                message_vision(msg,me,target);
                COMBAT_D->report_status(target, 0); 
      if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"RED+ i+ WHT"�㹥���˺�("RED+ abs + WHT"������)��\n"NOR);    
      if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+ i+ WHT"���˺�("RED+ abs + WHT"������)��\n"NOR); 

                msg =MAG "\n$Nʹ��һ�С�"HIG"С�����"MAG"�����Դ�������Լ��ؿ����䣬˳���ڵ���һ��������\n"+
                         "��$n������������ű��������ֳ�ȭ����$n���ġ�\n"NOR;

                i = calc_damage((int)me->query_skill("tenglong-bifa",1),(int)me->query_skill("canglang-goufa",1),me,target);
                abs =  i * def /(1000+ def );
                total += i;
    
		    
                
                if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",i));
                target->receive_damage("qi", i, me );
                target->receive_wound("qi", i/3 , me);
                result = COMBAT_D->damage_msg(i,"����");
                result = replace_string( result, "$l", "����" );
                result = replace_string( result, "$w", weapon->query("name") );
                msg += result;
                message_vision(msg,me,target);
                COMBAT_D->report_status(target, 0);     
      if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"RED+ i+ WHT"�㹥���˺�("RED+ abs + WHT"������)��\n"NOR);    
      if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+ i+ WHT"���˺�("RED+ abs + WHT"������)��\n"NOR);    //-------------------------------------------------------------

                msg =MAG "\n$Nʹ��һ�С�"HIB"�������"MAG"��������˳��һ�����ڱ�����һ�㣬����������$N�ʺ�\n"+
                         "���ȥ��$N��������һ�����Ǳ�������$n�ؿڡ�\n"NOR;

                i = calc_damage((int)me->query_skill("shenlong-tuifa",1),(int)me->query_skill("canglang-goufa",1),me,target);
                abs =  i * def /(1000+ def );
                total += i;
                if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",i));
                

                target->receive_damage("qi", i, me );
                target->receive_wound("qi", i/3 , me);
                result = COMBAT_D->damage_msg(i,"����");
                result = replace_string( result, "$l", "�ؿ�" );
                msg += result;
                message_vision(msg,me,target);
                COMBAT_D->report_status(target, 0);     
      
      if(userp(me) && me->query("env/damage"))         {
         tell_object(me,WHT"���"+ target->query("name") +"�����"RED+ i+ WHT"�㹥���˺�("RED+ abs + WHT"������)��\n"NOR);  
   abs = total * def /(1000+ def );
         tell_object(me,WHT"��ġ���Ů���С���"+ target->query("name") +"�ܹ������"RED+ total+ WHT"�㹥���˺�("RED+ abs + WHT"������)��\n"NOR);    
       }
         
 
      if(userp(target)&& target->query("env/damage"))     { 
        tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+ i+ WHT"���˺�("RED+ abs + WHT"������)��\n"NOR); 
                              abs = total * def /(1000+ def );
        tell_object(target,WHT""+ me->query("name") +"�ġ���Ů���С������ܹ������"RED+ total+ WHT"���˺�("RED+ abs + WHT"������)��\n"NOR);          
        }
                
                if(wizardp(me)) tell_object(me,sprintf("Total damage: %d \n",total));
                me->start_perform(5,"���������С�");
        }
        else {
                msg += MAG "\n\n$Nʹ��һ�С�"HIM"��������"MAG"��������΢����������Ť�����㷴�ߣ���$nС����ȥ��\n"+
                           "����˳�Ʒ�������§ס$nͷ�������ֱ��ж�׼$n���Ļ�ȥ��\n"NOR;
                msg += "����$n������$N����ͼ��û���ϵ�������ææ���Ա�һ�������˹�ȥ��\n";
                msg +=MAG "\n$Nʹ��һ�С�"HIG"С�����"MAG"�����Դ�������Լ��ؿ����䣬˳���ڵ���һ��������\n"+
                          "��$n������������ű��������ֳ�ȭ����$n���ġ�\n"NOR;
                msg += "$n����һ�������漴�侲�������ڿ�����һ��������$N���ţ�$Nֻ���ɿ����֡�\n";
                msg +=MAG "\n$Nʹ��һ�С�"HIB"�������"MAG"��������˳��һ�����ڱ�����һ�㣬����������$N�ʺ�\n"+
                          "���ȥ��$N��������һ�����Ǳ�������$n�ؿڡ�\n"NOR;
                msg += "$n��$N��ס������Σ���ң���������סҪ����ͬʱ�߸�Ծ�𣬷�����ͷײ�أ���$Nײ�˳�ȥ��\n";
                message_vision(msg,me,target);
                me->start_busy(1+random(3));
                me->start_perform(3,"���������С�");
        }
        return 1;
}

int calc_damage(int skill,int skill2,object me,object target)
{
        int i,lvl;

            i = ( (skill+skill2)*2 - (int)target->query_skill("parry",1) )*10;
            lvl = skill + skill2 - target->query_skill("parry",1)* 2;

            if (i<0) i = -i;
            i += random(i*2/5);
         if( i < (skill2*5)) i = (int)target->query("qi",1)/4;   

if(userp(target)){
if (lvl>50) i = i * 3 /2;
if(lvl + 50 < 0)  i = i /2;
}
if(me->query("gender")=="����")  i = i * me->query("str") /50;
else i = i * me->query("dex") /50;

if(!userp(target)) i = i*2;
        return i;
}

int help(object me)
{
   write(WHT"\n��"MAG"��Ů����"WHT"����"NOR"\n");
   write(@HELP

    Ҫ�󣺵�ǰ���� 1500 ���ϣ�
          ��ǰ���� 800 ���ϣ�
          �������Ƶȼ� 150 ���ϣ�
          �����ȷ��ȼ� 150 ���ϣ�
          ���˹����ȼ� 150 ���ϣ�
          �����󷨵ȼ� 150 ���ϣ�
          �Ա����� Ů�ԡ�
HELP
   );
   return 1;
}
