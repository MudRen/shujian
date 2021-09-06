// by action@SJ 2008.12.5
// updated BY Action@SJ 2009/2/17

#include <ansi.h>

#define JOB_NPC "/d/xiangyang/npc/menggu-attacker"
#define JOB_PLACE "/d/xiangyang/xuanwumen"

private void give_raward(object me);

int update_condition(object me, int duration)
{
	object *lineup;
	int lvl,index;

	if( duration == me->query_temp("xykm_job/time")){
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
			me->set_temp("xykm_job/lineup",lineup);
		}
		me->set_temp("xykm_job/lvl", lvl-120-random(10) );
		me->set_temp("xykm_job/num",sizeof( lineup ) );
	}
		
	if( duration <= 1 && !me->query_temp("xykm_job")){
		write(HIY "你时间已过，任务失败。\n" NOR);
		log_file("job/xykm_job", sprintf("%8s%-10s襄阳抵御蒙古大军任务，时间不够失败，经验：%d。",
			me->query("name"), "("+me->query("id")+")", me->query("combat_exp")),me);
		return 0;
	}
		
	if( me->query_temp("xykm_job/enter")
	 && file_name( environment(me) ) != JOB_PLACE ){
	 	object where = find_object(JOB_PLACE);
	 	if(!where) where = load_object(JOB_PLACE);
	 		 	
	 	if( !present( "menggu yongshi", where ) && me->query_temp("xykm_job/finish") )
	 	{
	 		give_raward(me);
			return 0;
	 	}
	 	
		tell_object(me,HIR "你擅离职守，任务失败。\n" NOR);
		log_file( "job/xykm_job", sprintf("%8s%-10s襄阳抵御蒙古大军任务，离开失败，经验：%d。",
			me->query("name"), "("+me->query("id")+")", me->query("combat_exp")),me);
		me->delete_temp("xykm_job");
		me->apply_condition("xykm_job",-1);
		me->apply_condition("job_busy", 10);
		return 0;
	}
	
	if(
	me->query_temp("xykm_job/finish") >= 9
	 ///无具体实际限制 可以放大到9 .... and more
	 && file_name(environment(me)) == JOB_PLACE ){
		if( present( "menggu yongshi", environment(me) ) )
		return 1;
		give_raward(me);
		return 0;
	}
	
	if( duration == 5
	 && file_name( environment(me)) == JOB_PLACE 
	 && !me->query_temp("xykm_job/enter") ){
	 	///开始	 	
		me->set_temp("xykm_job/enter",1);
		me->set_temp("xykm_job/time",random(8));
	}
	if( duration < 5
	 && !me->query_temp("xykm_job/enter") ){
		tell_object(me,HIR "你速度太慢，蒙古勇士已过玄武门，任务失败。\n" NOR);
		log_file( "job/xykm_job", sprintf("%8s%-10s襄阳抵御蒙古大军任务，速度太慢失败，经验：%d。",
			me->query("name"), "("+me->query("id")+")", me->query("combat_exp")),me);
		me->delete_temp("xykm_job");
		me->apply_condition("xykm_job",-1);
		me->apply_condition("job_busy",10);
		return 0;
	}
	/*
	每间隔1 c 来一批 (恢复到7c)			
	5 c 进入准备状态
	*/
	if( file_name(environment(me)) == JOB_PLACE && me->query_temp("xykm_job") ){
		object npc;
		switch (duration){
			case 9:
				message_vision(HIB"\n天色渐渐地暗淡了下来，呼啸的风声仍然没有停下的迹象。\n"NOR, me);
			case 7:
				message_vision(BLU"\n夜越来越深，背面的蒙古军营传来一段似狼声的号角声！\n"NOR, me);				
			case 5:	
				message_vision(HIR"\n蒙古军营中发出的战斗的冲锋的号角声越来越强烈，你不由地感觉到一丝丝寒意！\n" NOR, me);
				break;			
			case 3:
				message_vision(HBRED "\n霎那间，蒙古军营军队已从北方突袭而出，在襄阳城北摆开战斗攻势！\n"NOR, me);
				break;
			case 1:					
				message_vision(HIC "\n蓦然间，三个蒙古勇士在蒙古大将的命令下，施展轻功呼啸而至襄阳城楼上！\n"NOR, me);
				me->add_temp("xykm_job/finish",1);
				
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
		
	me->apply_condition("xykm_job", duration-1);
	
	if(duration==1)
	{
		me->apply_condition("xykm_job", 7);
		if (wizardp(me)) 
			tell_object(me,HIR "重新置7。\n" NOR);
		message("wizard", HIG"重新置7。\n"NOR, environment(me), me);
	}
	if (wizardp(me))
		tell_object(me,HIR "调试计时："+duration+"。\n" NOR);
	message("wizard", HIG"调试计时："+duration+"。\n"NOR, environment(me), me);
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
		pl->set_temp("xykm_job/lineup",lineup);
		pl->set_temp("xykm_job/num",sizeof( lineup ) );
	}
			
	pl->set_temp("xykm_job/finish",k);
	give_raward(pl);
}

private void give_raward(object me)
{
	object* lineup;
	int i,j;
		
	if(!me) return;
			
	lineup = me->query_temp("xykm_job/lineup");
		if( lineup ){
			if( me->query_temp("xykm_job/num") > sizeof( lineup ) )
				i = me->query_temp("xykm_job/num");
			else
				i = sizeof(lineup);
		}
		else
			i = 1;

	if ( i == 0) i=1;
	
	j = me->query_temp("xykm_job/finish");
	if( !lineup ){		
		me->apply_condition("xykm_job_busy",15);
		me->delete_temp("xykm_job");
		me->clear_condition("xykm_job");
		me->set("job_name", "襄阳抵御蒙古大军");
		
          if(j > 1 && j <= 4 )
              TASKREWARD_D->get_reward(me,"襄阳抵御蒙古大军",1,1,(me->query("relife/times")?(j+random(1+j)):random(j+1)),0,3,j-1,0);
          else if(j == 1)
              TASKREWARD_D->get_reward(me,"襄阳抵御蒙古大军",1,1,(me->query("relife/times")?(j+random(1+j)):random(j+1)),0,1,1,0);
          else
              TASKREWARD_D->get_reward(me,"襄阳抵御蒙古大军",1,1,(me->query("relife/times")?(j+random(1+j)):random(j+1)),0,4,j,0);

			if( me->query_condition("fx_busy") > 50 )
			me->apply_condition("fx_busy",50);
	}
	else{
		for(i = 0;i<sizeof(lineup);i++){
			if( lineup[i] ){
					lineup[i]->apply_condition("xykm_job_busy", 15);
					lineup[i]->delete_temp("xykm_job");
					lineup[i]->clear_condition("xykm_job");
					lineup[i]->set("job_name", "襄阳抵御蒙古大军");					

                                  if(j > 1 && j <= 4 )
                                      TASKREWARD_D->get_reward(lineup[i],"襄阳抵御蒙古大军",1,1,(lineup[i]->query("relife/times")?(j+random(1+j)):random(j+1)),0,3,j-1,0);
                                  else if(j == 1)
                                      TASKREWARD_D->get_reward(lineup[i],"襄阳抵御蒙古大军",1,1,(lineup[i]->query("relife/times")?(j+random(1+j)):random(j+1)),0,1,1,0);
                                  else
                                      TASKREWARD_D->get_reward(lineup[i],"襄阳抵御蒙古大军",1,1,(lineup[i]->query("relife/times")?(j+random(1+j)):random(j+1)),0,4,j,0);

					if( lineup[i]->query_condition("fx_busy") > 50 )
						lineup[i]->apply_condition("fx_busy",30+random(20));
				}
			}
		}
	me->delete_temp("xykm_job");
	me->clear_condition("xykm_job");//防止Bug
}
