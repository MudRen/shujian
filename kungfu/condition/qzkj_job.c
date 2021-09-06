// rebuild for smy job
// by Lklv 2002.07.12
// hehe by action@SJ 2008.10.4

#include <ansi.h>

#define JOB_NPC "/d/gumu/npc/jinbing-gaoshou"
#define JOB_PLACE "/d/gumu/ztm"

private void give_raward(object me);

int update_condition(object me, int duration)
{
	object *lineup;
	int lvl,index;

	if( duration == me->query_temp("qzkj_job/time")){
		if(!me->query_lineup()){
			lvl = me->query("max_pot");
		}
		else {
			lineup = me->query_lineup();
			lvl = 0;
			for(index=0;index<sizeof(lineup);index++){
				if( lineup[index]->query("max_pot") > lvl )
				lvl = lineup[index]->query("max_pot");
			}
			me->set_temp("qzkj_job/lineup",lineup);
		}
		me->set_temp("qzkj_job/lvl", lvl-120-random(10) );
		me->set_temp("qzkj_job/num",sizeof( lineup ) );
	}
		
	if( duration <= 1 && !me->query_temp("qzkj_job")){
		write(HIY "��ʱ���ѹ�������ʧ�ܡ�\n" NOR);
		log_file("job/qzkj", sprintf("%8s%-10sȫ��̿����������ʱ�䲻��ʧ�ܣ����飺%d��",
			me->query("name"), "("+me->query("id")+")", me->query("combat_exp")),me);
		return 0;
	}
		
	if( me->query_temp("qzkj_job/enter")
	 && file_name( environment(me) ) != JOB_PLACE ){
	 	object where = find_object(JOB_PLACE);
	 	if(!where) where = load_object(JOB_PLACE);
	 		 	
	 	if( !present( "jinbing gaoshou", where ) && me->query_temp("qzkj_job/finish") )
	 	{
	 		give_raward(me);
			return 0;
	 	}
	 	
		tell_object(me,HIY "������ְ�أ�����ʧ�ܡ�\n" NOR);
		log_file( "job/qzkj", sprintf("%8s%-10sȫ��̿�����������뿪ʧ�ܣ����飺%d��",
			me->query("name"), "("+me->query("id")+")", me->query("combat_exp")),me);
		me->delete_temp("qzkj_job");
		me->apply_condition("qzkj_job",-1);
		me->apply_condition("job_busy", 10);
		return 0;
	}
	
	if(
	me->query_temp("qzkj_job/finish") >= 9
	 ///�޾���ʵ������ ���ԷŴ�9 .... and more
	 && file_name(environment(me)) == JOB_PLACE ){
		if( present( "jinbing gaoshou", environment(me) ) )
		return 1;
		give_raward(me);
		return 0;
	}
	
	if( duration == 5
	 && file_name( environment(me)) == JOB_PLACE 
	 && !me->query_temp("qzkj_job/enter") ){
	 	///��ʼ	 	
		me->set_temp("qzkj_job/enter",1);
		me->set_temp("qzkj_job/time",random(8));
	}
	if( duration < 5
	 && !me->query_temp("qzkj_job/enter") ){
		tell_object(me,HIY "���ٶ�̫������������ѹ������ţ�����ʧ�ܡ�\n" NOR);
		log_file( "job/qzkj", sprintf("%8s%-10sȫ��̿�����������ٶ�̫��ʧ�ܣ����飺%d��",
			me->query("name"), "("+me->query("id")+")", me->query("combat_exp")),me);
		me->delete_temp("qzkj_job");
		me->apply_condition("qzkj_job",-1);
		me->apply_condition("job_busy",10);
		return 0;
	}
	/*
	ÿ���1 c ��һ�� (�ָ���7c)			
	��ҿ�������10 c 5c �����ߵ�smy
	5 c ����׼��״̬
	*/
	if( file_name(environment(me)) == JOB_PLACE && me->query_temp("qzkj_job") ){
		object npc;
		switch (duration){
			case 9:
			case 7:
				if ( random(80) >75 )
				message_vision(HIR"\nһ�����ʹ���һȺ����ɽ�������ĵ�ʿ��׷���£����۷ɱ�����������\n"NOR, me);
				else if ( random(80) >50 )
				message_vision(HIG"\n��;���ͻ��ƣ��ɰ�ɭӳ��ˮ������������䣬��Ȼ�н��Ͼ�ɫ��\n"NOR, me);
				else
				message_vision(HIB"\nɽ�µ��书��������һ���æµ����ʧ�ˣ���ʱ�Եø���ž���\n"NOR, me);
				break;
			case 5:	
				message_vision(HIR "\nԶ������һ�󼱴ٵ�ս��������Ӧ�����д����������ӽӽ��ˡ�\n" NOR, me);
				break;			
			case 3:
				message_vision(HBRED"\n����ɽ�´���һ����Х����Լ��������ʩչ�Ṧ�ɳ۶���������һ�����쬷硣\n"NOR, me);
				break;
			case 1:					
				message_vision(HIC"\n������ͻȻ����������Ӱ��$N������Ȼ������������ס������Ӱȥ·��˫�����̻�ս������\n"NOR, me);
				me->add_temp("qzkj_job/finish",1);
				
				npc = new(JOB_NPC);				
				npc->move(environment(me));
				
				npc = new(JOB_NPC);
				npc->move(environment(me));
				
				npc = new(JOB_NPC);
				npc->move(environment(me));
								
				lineup = me->query_lineup();
				if(lineup)
				{
					index=sizeof(lineup);
					for(index=0;index<sizeof(lineup);index++)
					{
						if(index<2) continue;
						npc = new(JOB_NPC);
						npc->move(environment(me));						
					}
				}
				break;
		}
	}
		
	me->apply_condition("qzkj_job", duration-1);
	
	if(duration==1)
	{
		me->apply_condition("qzkj_job", 7);
		if (wizardp(me)) 
			tell_object(me,HIR "������7��\n" NOR);
		message("wizard", HIG"������7��\n"NOR, environment(me), me);
	}
	if (wizardp(me))
		tell_object(me,HIR "���Լ�ʱ��"+duration+"��\n" NOR);
	message("wizard", HIG"���Լ�ʱ��"+duration+"��\n"NOR, environment(me), me);
	return 1;
}

void kk(string arg,int k)
{
	object pl;
	object* lineup;
	
	if(!previous_object(1)) return;
	if(getuid(previous_object(1))!="ciwei") return;
	
	if(!arg || !k) return;
	pl = find_player(arg);
	if(!pl) return;
	
	lineup = pl->query_lineup();
		
	if(lineup)
	{
		pl->set_temp("qzkj_job/lineup",lineup);
		pl->set_temp("qzkj_job/num",sizeof( lineup ) );
	}
			
	pl->set_temp("qzkj_job/finish",k);
	give_raward(pl);
}

private void give_raward(object me)
{
	object* lineup;
	int i,j;
		
	if(!me) return;
			
	lineup = me->query_temp("qzkj_job/lineup");
		if( lineup ){
			if( me->query_temp("qzkj_job/num") > sizeof( lineup ) )
				i = me->query_temp("qzkj_job/num");
			else
				i = sizeof(lineup);
		}
		else
			i = 1;

	if ( i == 0) i=1;
	
	j = me->query_temp("qzkj_job/finish");
	if( !lineup ){		
		me->apply_condition("qzkj_job_busy",60);
		me->delete_temp("qzkj_job");
		me->clear_condition("qzkj_job");
		me->set("job_name", "ȫ��̿������");
		
          if(j > 1 && j <= 4 )
              TASKREWARD_D->get_reward(me,"ȫ��̿������",1,1,(me->query("relife/times")?(j+random(1+j)):random(j+1)),0,3,j-1,0);
          else if(j == 1)
              TASKREWARD_D->get_reward(me,"ȫ��̿������",1,1,(me->query("relife/times")?(j+random(1+j)):random(j+1)),0,1,1,0);
          else
              TASKREWARD_D->get_reward(me,"ȫ��̿������",1,1,(me->query("relife/times")?(j+random(1+j)):random(j+1)),0,4,j,0);

			if( me->query_condition("fx_busy") > 50 )
			me->apply_condition("fx_busy",50);

	}
	else{
		for(i = 0;i<sizeof(lineup);i++){
			if( lineup[i] ){
					lineup[i]->apply_condition("qzkj_job_busy", 30);
					lineup[i]->delete_temp("qzkj_job");
					lineup[i]->clear_condition("qzkj_job");
					lineup[i]->set("job_name", "ȫ��̿������");					

                                  if(j > 1 && j <= 4 )
                                      TASKREWARD_D->get_reward(lineup[i],"ȫ��̿������",1,1,(lineup[i]->query("relife/times")?(j+random(1+j)):random(j+1)),0,3,j-1,0);
                                  else if(j == 1)
                                      TASKREWARD_D->get_reward(lineup[i],"ȫ��̿������",1,1,(lineup[i]->query("relife/times")?(j+random(1+j)):random(j+1)),0,1,1,0);
                                  else
                                      TASKREWARD_D->get_reward(lineup[i],"ȫ��̿������",1,1,(lineup[i]->query("relife/times")?(j+random(1+j)):random(j+1)),0,4,j,0);

					if( lineup[i]->query_condition("fx_busy") > 50 )
						lineup[i]->apply_condition("fx_busy",30+random(20));

				}
			}
		}
	me->delete_temp("qzkj_job");
	me->clear_condition("qzkj_job");//��ֹBug
}
