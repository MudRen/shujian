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
		write(HIY "你时间已过，任务失败。\n" NOR);
		log_file("job/qzkj", sprintf("%8s%-10s全真教抗击金兵任务，时间不够失败，经验：%d。",
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
	 	
		tell_object(me,HIY "你擅离职守，任务失败。\n" NOR);
		log_file( "job/qzkj", sprintf("%8s%-10s全真教抗击金兵任务，离开失败，经验：%d。",
			me->query("name"), "("+me->query("id")+")", me->query("combat_exp")),me);
		me->delete_temp("qzkj_job");
		me->apply_condition("qzkj_job",-1);
		me->apply_condition("job_busy", 10);
		return 0;
	}
	
	if(
	me->query_temp("qzkj_job/finish") >= 9
	 ///无具体实际限制 可以放大到9 .... and more
	 && file_name(environment(me)) == JOB_PLACE ){
		if( present( "jinbing gaoshou", environment(me) ) )
		return 1;
		give_raward(me);
		return 0;
	}
	
	if( duration == 5
	 && file_name( environment(me)) == JOB_PLACE 
	 && !me->query_temp("qzkj_job/enter") ){
	 	///开始	 	
		me->set_temp("qzkj_job/enter",1);
		me->set_temp("qzkj_job/time",random(8));
	}
	if( duration < 5
	 && !me->query_temp("qzkj_job/enter") ){
		tell_object(me,HIY "你速度太慢，金兵高手已过中天门，任务失败。\n" NOR);
		log_file( "job/qzkj", sprintf("%8s%-10s全真教抗击金兵任务，速度太慢失败，经验：%d。",
			me->query("name"), "("+me->query("id")+")", me->query("combat_exp")),me);
		me->delete_temp("qzkj_job");
		me->apply_condition("qzkj_job",-1);
		me->apply_condition("job_busy",10);
		return 0;
	}
	/*
	每间隔1 c 来一批 (恢复到7c)			
	玩家可以设置10 c 5c 用于走到smy
	5 c 进入准备状态
	*/
	if( file_name(environment(me)) == JOB_PLACE && me->query_temp("qzkj_job") ){
		object npc;
		switch (duration){
			case 9:
			case 7:
				if ( random(80) >75 )
				message_vision(HIR"\n一个彪型大汉在一群终南山重阳宫的道士的追逐下，疾驰飞奔向重阳宫。\n"NOR, me);
				else if ( random(80) >50 )
				message_vision(HIG"\n沿途冈峦回绕，松柏森映，水田蔬圃连绵其间，宛然有江南景色。\n"NOR, me);
				else
				message_vision(HIB"\n山下的武功镇喧闹在一天的忙碌中消失了，此时显得格外寂静。\n"NOR, me);
				break;
			case 5:	
				message_vision(HIR "\n远处传来一阵急促的战马蹄声，应该是有大批大金国军队接近了。\n" NOR, me);
				break;			
			case 3:
				message_vision(HBRED"\n终南山下传来一阵轻啸，隐约听得有人施展轻功飞驰而来，带来一阵凉飕飕风。\n"NOR, me);
				break;
			case 1:					
				message_vision(HIC"\n中天门突然闪出三条人影，$N飞身纵然而起，立即将挡住三条人影去路，双方立刻混战起来。\n"NOR, me);
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
		me->set("job_name", "全真教抗击金兵");
		
          if(j > 1 && j <= 4 )
              TASKREWARD_D->get_reward(me,"全真教抗击金兵",1,1,(me->query("relife/times")?(j+random(1+j)):random(j+1)),0,3,j-1,0);
          else if(j == 1)
              TASKREWARD_D->get_reward(me,"全真教抗击金兵",1,1,(me->query("relife/times")?(j+random(1+j)):random(j+1)),0,1,1,0);
          else
              TASKREWARD_D->get_reward(me,"全真教抗击金兵",1,1,(me->query("relife/times")?(j+random(1+j)):random(j+1)),0,4,j,0);

			if( me->query_condition("fx_busy") > 50 )
			me->apply_condition("fx_busy",50);

	}
	else{
		for(i = 0;i<sizeof(lineup);i++){
			if( lineup[i] ){
					lineup[i]->apply_condition("qzkj_job_busy", 30);
					lineup[i]->delete_temp("qzkj_job");
					lineup[i]->clear_condition("qzkj_job");
					lineup[i]->set("job_name", "全真教抗击金兵");					

                                  if(j > 1 && j <= 4 )
                                      TASKREWARD_D->get_reward(lineup[i],"全真教抗击金兵",1,1,(lineup[i]->query("relife/times")?(j+random(1+j)):random(j+1)),0,3,j-1,0);
                                  else if(j == 1)
                                      TASKREWARD_D->get_reward(lineup[i],"全真教抗击金兵",1,1,(lineup[i]->query("relife/times")?(j+random(1+j)):random(j+1)),0,1,1,0);
                                  else
                                      TASKREWARD_D->get_reward(lineup[i],"全真教抗击金兵",1,1,(lineup[i]->query("relife/times")?(j+random(1+j)):random(j+1)),0,4,j,0);

					if( lineup[i]->query_condition("fx_busy") > 50 )
						lineup[i]->apply_condition("fx_busy",30+random(20));

				}
			}
		}
	me->delete_temp("qzkj_job");
	me->clear_condition("qzkj_job");//防止Bug
}
