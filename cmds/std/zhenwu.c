        // zhenwu.c
// By Scatter 1/4/2002

inherit F_CLEAN_UP;

#include <ansi.h>
#include <skill.h>



inherit F_SSERVER;
string *position = ({
                                         "������","������","������","������","������","������","������"
});

string *sword = ({
        "�鲽������һ�С����ѵ�ˮ�������еĽ����������һ����������ֵ����֡�",
        "�ҽŶ�����һ�С�����ǡ�������ǰ��󷴴̶��ֵ���š�",
        "һ�С�̽��ʽ�����ҽŶ�������ϥ���𣬽���ǰ�������ֵ�������",
        "һ�С�����ɨ����һ�С�����ɨ��������ƽָ��һ���ǳɺ�ɨ���ֵ��ֱۡ�",
        "ʹ�����������¡�������������ԲȦ������ֱ�������಻�ϻ�����֡�",
        "һת�������б����һ�С�����Ҷ����������֡�",
        "��ǰ����������һ�С�Ұ��������������ǰƽ�̶��ֵ��ز���",
        "�����ǰ��һ�������ɺ�һ��Բ��ǰ����һ�С�ӭ�絧������������ֵ��ҽš�",
        "���������ǰ��һ�������ֵĽ�һ�С�˳ˮ���ۡ������Һ󷽴�����ֵ��ұۡ�",
        "�ҽ���ǰ�沽��һ�С��������¡������������һ���󻡣���ǰ������֡�",
        "����δ��ʹ�ϣ���ȻȦת��ͻȻ֮�䣬������ǰ�����˼�����ɫ��Ȧ����ȦСȦ����ȦбȦ����˸���ѡ�"
});

string *zhen =  ({
        "�����ʱ���������˺ͣ���ʽ������תΪǿ�ƣ�����תΪ����",
        "�����߽������������̾Ϊ��ֹ��������ʿ����������ߡ�",
        "ֻ���������߽���ʹ��������������߾��磬���ֵ��书��ʱ�����κ����á�",
        "ֻ�������߽��������������ϵ������޷죬�ۿ����ֵ������Ծ���"
});


int check_ob(object ob,object me);
void start_zhenwu(object ob, int mypos,int zhenwu_time );
int zhenwu(object me);
int halt_zhenwu(object me);
int do_zhenwu(string arg);
int zhenwu(object me);
int halt_zhenwu(object me);
int stop_zhenwu();

void create() { seteuid(getuid()); }


int main(object me, string arg)
{
                  object enemy;
                  int i,power,zw_power;
                  object here;
                  string name1,name2,enemy_id;
                  object ob1,ob2;

                                  if( !this_player()->query("canzhenwu") )
                                          return notify_fail("�㻹����ʹ�������߽���\n");
                  if( this_player()->is_busy() )
                  {
                                return notify_fail("����æ���أ�\n");
                  }

                  here = environment( this_player() );

                  if( !arg || sscanf(arg, "%s %s %s", enemy_id,name1,name2)!=3 )
                                         return notify_fail("zhenwu enemy ally1 ally2\n");

                  if( !(enemy = present(enemy_id, here) ) )
                  {
                                return notify_fail(enemy_id+"�������\n");
                  }

                  if( enemy->query("race") != "����" )
                  {
                                return notify_fail("ɱ������ţ����\n");
                  }

                  if( enemy->query("family/family_name") == "�䵱��" )
                  {
                                return notify_fail("��Ҫ�����Ż���\n");
                  }


                  if( !(ob1 = present(name1, here ) ) )
                  {
                                return notify_fail(name1+"�������\n");
                  }

                  if( ob1->is_busy() )
                  {
                                return notify_fail(name1+"��æ���أ�\n");
                  }
                  
                  i = check_ob(ob1,me);
                  if(  i !=1) return i;

                  if( !(ob2 = present(name2, here) ) )
                  {
                                return notify_fail(name2+"�������\n");
                  }

                  if( ob2->is_busy() )
                  {
                                return notify_fail(name2+"��æ���أ�\n");
                  }

                  i = check_ob(ob2,me);
                  if(  i !=1) return i;

                  if( name1 == me->query("id") ||   name2 == me->query("id")  )
                  {
                                return notify_fail("��һ�����ã��㲻��������ɣ�\n");
                  }

                  if( name1 == name2 )
                  {
                                return notify_fail(name1 + "����������ɣ�\n");
                  }


                  power = me->query("force") + ob1->query("force")+ob2->query("force");
                  power += me->query("sword") + ob1->query("sword")+ob2->query("sword");
                  power += me->query("str") + ob1->query("str")+ob2->query("str");
                  power += me->query("dex") + ob1->query("dex")+ob2->query("dex");
                  zw_power = me->query("taiji-shengong") + ob1->query("taiji-shengong")+ob2->query("taiji-shengong");
                  power = power / 140/2;
                  zw_power /= 70/5;
                  power *= zw_power;

                  if(power>50)power=50;
                  if(power<15)power=15;


                  start_zhenwu(me,0,power);
                  start_zhenwu(ob1,1,power);
                  start_zhenwu(ob2,2,power);

                  here->set_temp("ob1",me->query("id"));
                  here->set_temp("ob2",ob1->query("id"));
                  here->set_temp("ob3",ob2->query("id"));

                  message_vision(HIR"\n$N��$n�ȵ���" + RANK_D->query_rude(enemy) + "��һ��Ϊ�������������䵱��Ҫ�����е�����������\n"NOR, me, enemy);
                  me->kill_ob(enemy);
                  ob1->kill_ob(enemy);
                  ob2->kill_ob(enemy);
                  enemy->kill_ob(me);
                  enemy->kill_ob(ob1);
                  enemy->kill_ob(ob2);
                  message_vision(HIY"$NͻȻ�����ƶ��������䵱���Ӿ�վս��λ�ã��ڳ���"+ HIW +"�������߽���"+ HIY + "�󷨡�\n\n"NOR, me);
                                  message_vision(HIG"

        MM.                M;                              ,. -M.                 MM
        MM;MXH             MM                              MM  M;.M               MM
     ==MMMMMMM,            $M ,            =               -M  M; MX        -M+.  MM$@
   =MMMMM;-,             = MM MMM.        .MM            ;;MMMMM; %M      $MMMM;M@MM$@
       ,M ;;           =HM=-M  %$          M;            ,;;M  @; :,      ;M @    M$=M+
     M@MMMMM:         MM@; .M.;;           M=             -HMHMHMMMM$     ;M,M MM;MM/MM
     MMMMMMM          .-MMMMMMMM           M, .HMMMM   =MMMM;- ;M         ;M M;HM;MMMMM
     MH$; -M        ;$MMM@. M              M;MMMMH$M      MMMX  M- M+     ;M $M=M;MX M%
     MMMMMMM        :MM-M;  MH       -$MMMMM@$;-         MM;MMM;HM MM     ;M;MM-M;MMMM;
     M+M;,-M            M;..$X        :MH  M             MX$M%, :M:M:     ;M    %%MH-@ "NOR, me);
                                message_vision(HIG"
     MHMMMMM         MM MMMM;M;            M            MMMMMMM:.MMM      MM    , MM=;MMM
     M;;:.;M+MM;     -M M;   MM            M,          ;H;M;MMM; MM       $M MMMMMMMMMMMM.
  --:MXMMMMMMMMM:     M M;:%. M            M+    :;      +X$M+   XM       M$  .   M;      
 ;MMMM;;--M$         .M@MM+,  MM  M        /MMMMMMM%     $M;MMMM=MM/ ;    M$      M;      
     $MM  ,M$,     -$MM$=     =M,-M          ---;        HX$;, ,@+XM:M    +;      M;      
    @M@;   MMM      XM$        MMMM                      M;   ,M;  MMM            M=      
  ;;@-      :M                  ;MM                      /-   .     $M-           M.\n"NOR, me);
                                                                          
                  return 1;
}


int check_ob(object ob,object me)
{
        string ob_name;
        float exp_diff;

                          if( !objectp(ob) )
                          {
                                         return notify_fail("��ϧû������ˡ�\n");
                          }
                                  ob_name = ob->query("name");

                                  if ( !present( ob->query("id"), environment(me) ) )
                                  {
                                         return notify_fail("��ϧ"+ob_name+"�������\n");
                                  }

                                  if ( ob->query("family/family_name") != "�䵱��" )
                                  {
                                         return notify_fail("��ϧ"+ob_name+"�����䵱���ӣ����ᡸ̫���񹦡���\n");
                                  }


                                  if ( ob->query_skill("taiji-jian",1) <100 || ob->query("combat_exp",1)<50000 ||
                                                ob->query_skill("dodge") < 100
                                          )
                                  {
                                         return notify_fail("��ϧ"+ob_name+"�书̫����ᡸ̫���񹦡���\n");
                                  }

                                  exp_diff = (float)( ob->query("combat_exp" ) - me->query("combat_exp") ) / (float)me->query("combat_exp");

                                  if( exp_diff > 0.3 || exp_diff < -0.3 )
                                         return notify_fail("��ϧ"+ob_name+"�书������̫�󣬲��ܹ��ڡ������߽��󡹡�\n");

                 return 1;
}

void start_zhenwu(object ob, int mypos,int zhenwu_time )
{
                        ob->set_temp("pending/zhenwu", 1);
                        ob->set_temp("zhenwu_time", zhenwu_time*2);
                        ob->set_temp("zw_pos", mypos);
                        ob->set_temp("zw_power",zhenwu_time);
                        ob->start_busy((: zhenwu :), (:halt_zhenwu:));
}




void destruct_me(object me)
{
        if(me)
                destruct(me);
}

void check_leaving(object me)
{
        //string name = me->query("id");

         if( !userp(me) )
                {
                 object enemy = offensive_target(me);
                 if( !objectp(enemy) && !me->is_busy() && !me->is_fighting() )
                 {
                         message_vision(HIY"\n$N���˸�鮵���ʣ�����ľͽ������ǣ������ȸ����ˣ�\n"NOR, me);
                         call_out("destruct_me",10,me);
                         return;
                  }

                  call_out("check_leaving",5,me);
          }
}

int zhenwu(object me)
{
                  object  where = environment(this_player());
                  int zhenwu_time = (int)me->query_temp("zhenwu_time");
                  object room, enemy,weapon;
                  int bonus,mypos=me->query_temp("bd_pos");
                  int power;
                  object ob1,ob2,ob3;


                  if( !(room = environment(this_player())) )

                  {

                                  if(!objectp(weapon = me->query_temp("weapon"))

                                                || (string)weapon->query("skill_type") != "sword" )
                                                {
                                                        message_vision(HIW"\n$N�������һ�ݣ�ʹһ�С�������ǧ�����Χ�Ķ����������˳��ˡ������߽��󡹡�\n"NOR, me);
                                                }
                                else
                                        message_vision(HIW"\n$N�������һ�ݣ�ʹһ�С�������ˮ�����ڿ��е���һ�£��˳��ˡ������߽��󡹡�\n"NOR, me);

                                me->remove_all_enemy();

                                me->delete_temp("pending/zhenwu");
                                me->delete_temp("zhenwu_time");
                                me->delete_temp("zw_pos");
                                me->delete_temp("zw_power");
                                call_out("check_leaving",2,me);

                          return 0;

                        }

                  enemy = offensive_target(me);


                  if( enemy && enemy->query_temp("yield") )

                  {

                                  if(!objectp(weapon = me->query_temp("weapon"))

                                                || (string)weapon->query("skill_type") != "sword" )
                                                {
                                                        message_vision(HIG"\n$N�������һ�ݣ�ʹһ�С�������ǧ�����Χ�Ķ����������˳��ˡ������߽��󡹡�\n"NOR, me);
                                                }
                                        else
                                          message_vision(HIG"\n$N�������һ�ݣ�ʹһ�С�������ˮ�����ڿ��е���һ�£��˳��ˡ������߽��󡹡�\n"NOR, me);


                                        message_vision(HIY"\n$N���������䵱��ɱ������֮�ˣ���λ"+RANK_D->query_respect(enemy)+HIY"���߰ɣ�\n"NOR, me);

                                        me->remove_all_enemy();

                                        me->delete_temp("pending/zhenwu");
                                        me->delete_temp("zhenwu_time");
                                        me->delete_temp("zw_pos");
                                        me->delete_temp("zw_power");
                                        room->delete_temp("ob1");
                                        room->delete_temp("ob2");
                                        room->delete_temp("ob3");

                                        call_out("check_leaving",2,me);
                                        return 0;
                  }


                  if ( me->query("neili") < 60 || me->query("jingli")<50 )
                  {
                                  if(!objectp(weapon = me->query_temp("weapon"))
                                                || (string)weapon->query("skill_type") != "sword" )
                                                {
                                                        message_vision(HIR"\n$N������֧��ֻ���������һ�ݣ��˳��������߽��󡹡�\n"NOR, me);
                                                }
                                  else
                                                message_vision(HIR"\n$N������֧��ֻ���������һ�ݣ��˳��������߽��󡹡�\n"NOR, me);

                                        me->remove_all_enemy();
                                        me->delete_temp("pending/zhenwu");
                                        me->delete_temp("zhenwu_time");
                                        me->delete_temp("zw_pos");
                                        me->delete_temp("zw_power");
                                        call_out("check_leaving",2,me);
                                         return 0;
                  }

                  if( !( room->query_temp("ob1",1) &&
                                (objectp(ob1=present( room->query_temp("ob1",1),where) ) ) && ob1->query_temp("zhenwu_time") &&
                                (objectp(ob2=present( room->query_temp("ob2",1),where) ) ) && ob2->query_temp("zhenwu_time") &&
                                (objectp(ob3=present( room->query_temp("ob3",1),where) ) ) && ob3->query_temp("zhenwu_time") )
                         )
                         {
                                  if(!objectp(weapon = me->query_temp("weapon"))
                                                || (string)weapon->query("skill_type") != "sword" )
                                                {
                                                        message_vision(HIW"\n$N�������һ�ݣ�ʹһ�С�������ǧ�����Χ�Ķ����������˳��ˡ������߽��󡹡�\n"NOR, me);
                                                }
                                        else
                                          message_vision(HIW"\n$N�������һ�ݣ�ʹһ�С�������ˮ�����ڿ��е���һ�£��˳��ˡ������߽��󡹡�\n"NOR, me);

                                        me->remove_all_enemy();
                                        me->delete_temp("pending/zhenwu");
                                        me->delete_temp("zhenwu_time");
                                        me->delete_temp("zw_pos");
                                        me->delete_temp("zw_power");
                                        room->delete_temp("ob1");
                                        room->delete_temp("ob2");
                                        room->delete_temp("ob3");

                                        call_out("check_leaving",2,me);
                                        return 0;
                         }


                  zhenwu_time = zhenwu_time-1;
                  me->set_temp("zhenwu_time", zhenwu_time);

                  bonus = random( ( me->query("int")+me->query("con")+25 ) / 30 ) + (me->query("int")+me->query("con")+25 ) / 30;
                  if( bonus > 3 ) bonus = 3;


                  if(enemy) bonus = bonus * 2 * ( enemy->query("combat_exp") - me->query("combat_exp") ) / me->query("combat_exp");
                  else bonus = 0;

                  if( bonus <0 ) bonus = 0;
                  if( bonus > 8 ) bonus = 8;

                  if( (int)me->query("potential") < (int)me->query("max_potential") )
                                         me->add( "potential", bonus/2 );

                  me->add( "combat_exp", bonus*2/3 );
                  me->improve_skill( "taiji-shengong", random(bonus*2/3) );

                  enemy = offensive_target(me);

                  power = me->query_temp("zw_power",1)*4;


                  if( random(6)==1 )
                  {
                          tell_room(environment(me), HIR"\n" + zhen[(int)random(4)] +"\n"NOR, this_object());

                          if( objectp(enemy) && objectp( present( enemy->query("id"),environment(me) )) )
                                  enemy->start_busy( random(2) );
                  }

                  if( objectp(enemy) && objectp( present( enemy->query("id"),environment(me) )) )
                  {
                          me->set_temp("apply/parry",me->query_temp("apply/parry",1)+power);
                          me->set_temp("apply/armor",me->query_temp("apply/armor",1)+power);
                          if( random(2)==1 )
                          {
                                  if(random(2)==0)
                                          message_vision("\n" + position[mypos] + "λ�ϵ�$N̤��Ǭ�ԣ�ʹ��������ǿ�����������صĹ������������۵Ĺ꽫�����ҡ�", me);
                                  else message_vision("\n" + position[mypos] + "λ�ϵ�$N����ת������Ǭת�����������ḡ�����߽����������ң��������߳���һ�㣬����������мܡ�", me);

                                  me->set_temp("apply/damage",me->query_temp("apply/damage",1)+power/2);
                                  me->set_temp("apply/attack",me->query_temp("apply/attack",1)+power/2);
                                  COMBAT_D->do_attack(me, enemy, me->query_temp("weapon"));
                                  me->set_temp("apply/damage",me->query_temp("apply/damage",1)-power/2);
                                  me->set_temp("apply/attack",me->query_temp("apply/attack",1)-power/2);
                                  me->receive_damage("jingli", 15+random(15), "��ת�����߽���������");
                                  me->add("neili", -20-random(20));
                          }
                          me->set_temp("apply/parry",me->query_temp("apply/parry",1)-power);
                          me->set_temp("apply/armor",me->query_temp("apply/armor",1)-power);
                          return 1;
                  }
                  else
                  {
                                if ( random(3)==1 )
                                {
                                        if( ( weapon = me->query_temp("weapon") )
                                                 && (string)weapon->query("skill_type") == "sword" )
                                        {
                                                message_vision("\n" + position[mypos] + "λ�ϵ�$N"+ sword[random(10)]+"\n", me);
                                        }

                                        me->receive_damage("jingli", 15+random(10), "��ϰ�����߽���������");
                                        me->add("neili", -20-random(15) );
                                }
                  }


         me->delete_temp("pending/zhenwu");
         me->delete_temp("zhenwu_time");
         me->delete_temp("zw_pos", mypos);
          if(!objectp(weapon = me->query_temp("weapon"))
                        || (string)weapon->query("skill_type") != "sword" )
                        {
                                message_vision(HIW"\n$N�������һ�ݣ�ʹһ�С�������ǧ�����Χ�Ķ����������˳��ˡ������߽��󡹡�\n"NOR, me);
                        }
                else
                        message_vision(HIW"\n$N�������һ�ݣ�ʹһ�С�������ˮ�����ڿ��е���һ�£��˳��ˡ������߽��󡹡�\n"NOR, me);


         call_out("check_leaving",5,me);
         return 0;
}

void restart (object me)
{
        start_zhenwu(me, me->query_temp("zw_pos"), me->query_temp("zhenwu_time",1) );
}

int halt_zhenwu(object me)
{
          object weapon;
          int zhenwu_time = (int)me->query_temp("zhenwu_time",1);
          if (zhenwu_time > 0)
          {
                        if( !living(me) ) return 1;

                        if(random(2)==1)
                        {
                                message_vision(HIY"\n$N�ܵ����ֳ��治���һ����$N�Ͻ�ʹ��������ǧ����ֱ����ˣ�$N���վ���ȡ�\n"NOR, me);
                        }
                        else message_vision(MAG"\n$N����Ļ��˼��Σ�$N�Ͻ�ʹ��������ǧ����ֱ����ˣ���վ���˲��ӡ�\n"NOR, me);
                        call_out("restart",4,me);
                        return 1;
          }

          if(!objectp(weapon = me->query_temp("weapon"))
                        || (string)weapon->query("skill_type") != "sword" )
                {
                        message_vision(HIW"\n$N�������һ�ݣ�ʹһ�С�������ǧ�����Χ�Ķ����������˳��ˡ������߽��󡹡�\n"NOR, me);
                }
                else
                        message_vision(HIW"\n$N�������һ�ݣ�ʹһ�С�������ˮ�����ڿ��е���һ�£��˳��ˡ������߽��󡹡�\n"NOR, me);

          me->delete_temp("pending/zhenwu");
          me->delete_temp("zhenwu_time");
          me->delete_temp("zw_pos");
          me->delete_temp("zw_power");
          return 1;
}

int stop_zhenwu()
{
          object weapon,me=this_player();
          if(!me->query_temp("pending/zhenwu"))
                                         return notify_fail("ͣʲô���㲻�����С�������󡹡�\n");
          if(!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword" )
          {
                message_vision(HIG"\n$N�������һ�ݣ�ʹһ�С�������ǧ�����Χ�Ķ����𿪣��˳��ˡ������߽���\n"NOR, me);
                }
         else
                message_vision(HIG"\n$N�������һ�ݣ�ʹһ�С�������ˮ�����ڿ��е���һ�£��˳��ˡ������߽��󡹡�\n"NOR, me);

          me->remove_all_enemy();
          me->delete_temp("pending/zhenwu");
          me->delete_temp("zhenwu_time");
          me->delete_temp("zw_pos");
          me->delete_temp("zw_power");
          return 1;
}



int help(object me)
{
                  write(@HELP
ָ���ʽ : zhenwu <enemy> <����1> <����2> <����3>

�������߽���Ϊ�������������䵱ɽһ�򹩷�����ۡ���������һ����Ѫ������\n
��������������ǰ�Ĺ��߶��������𳤽��ͺ�ˮ֮�����ɽ����ɽ�����볤���鶯���ڹ����أ�\n
����������һ��һ�ߣ����Ǽ����������ص��������ԣ��������һ�׾����޷����书������\n
�����书���Ǵӹ��߶�ɽ�������磬��ɽ���ݻ��������书��ɭȻ���У����޼��㡣\n
�����书�����ɫΪ������Ϊ���˺�ʹ������ͬ��ʮ���˸��ֺ�ʹһ�㣬������֮�ͣ�\n
ʵ���޿ɱ��⡣

HELP
                  );
                  return 1;
}
