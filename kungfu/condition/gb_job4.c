#include <ansi.h>
#include <job_mul.h>

int update_condition(object me, int duration)
{
	int exp,pot,shen;
	int i;
	object *lineup;
	int lvl,index;
        
	if( duration == me->query_temp("gb_job4/time")){        
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
			me->set_temp("gb_job4/lineup",lineup);
		}
		me->set_temp("gb_job4/lvl", lvl-100-random(6) );
		me->set_temp("gb_job4/num",sizeof( lineup ) );
	}               
        
	if( duration <= 1 && !me->query_temp("gb_job4")){
		write(HIY "��ʱ���ѹ�������ʧ�ܡ�\n" NOR);
		log_file("job/smy", sprintf("%8s%-10s������Ħ������ʱ�䲻��ʧ�ܣ����飺%d��",
			me->query("name"), "("+me->query("id")+")", me->query("combat_exp")),me);
		return 0;
	}
    
	if( me->query_temp("gb_job4/enter") 
	 && file_name( environment(me) ) != "/d/xingxiu/silk3" ){
		tell_object(me,HIY "������ְ�أ�����ʧ�ܡ�\n" NOR);
		log_file( "job/smy", sprintf("%8s%-10s������Ħ�������뿪ʧ�ܣ����飺%d��",
			me->query("name"), "("+me->query("id")+")", me->query("combat_exp")),me);
		me->delete_temp("gb_job4");
		me->apply_condition("gb_job4",-1);
		me->apply_condition("job_busy", 10);
		return 0;
	}
        
	if( duration <=1
	 && me->query_temp("gb_job4/finish") > 3 
	 && file_name(environment(me)) == "/d/xingxiu/silk3" ){
		if( present( "wu shi", environment(me) ) )
		return 1;
        
		lineup = me->query_temp("gb_job4/lineup");
		if( lineup ){
			if( me->query_temp("gb_job4/num") > sizeof( lineup ) )
				i = me->query_temp("gb_job4/num");
			else
				i = sizeof(lineup);
		}
		else
			i = 1;
		if ( i == 0) 
			i=1;
        
		exp=2000/(i+1)+random(500);
		pot=exp/5+random(exp/10);
		shen = exp/2 + pot/2;
		if( exp > 2000 )
		exp = 2000 + random(100);
		
		if( !lineup ){
			       	/*�������ƿ�ʼ*/
        if (me->query("registered")==3){
			exp = exp * SMY_JOB_MUL * VIP_MUL /10000;
            		pot = pot * SMY_JOB_MUL * VIP_MUL /10000;
		}
		else
		{
			exp = exp * SMY_JOB_MUL /100;
           		pot = pot * SMY_JOB_MUL /100;
		}
		/*�������ƽ���*/ 
			
			tell_object( me, sprintf(HIW "�ã���������ˣ���õ���"
					+ CHINESE_D->chinese_number( exp ) 
					+ "��ʵս���飬" 
					+ CHINESE_D->chinese_number( pot )
					+ "��Ǳ�ܺ�"
					+ CHINESE_D->chinese_number( shen ) 
					+ "������\n" NOR) );
			me->add( "combat_exp", exp );
			me->add( "potential", pot );
			me->apply_condition("gb_job_busy",90);
			if( me->query("potential") > me->query("max_pot"))
				me->set("potential",me->query("max_pot"));
			me->add( "shen", shen );
			me->add("job_time/��Ч����",1);
                        me->add("job_time/��Ħ��",1);
			me->set("job_name", "������Ħ��");
			log_file("job/smy", sprintf(HIR"%8s%-10s��Ħ������������õ�%d�㾭�飬Ŀǰ���飺%d��"NOR,
				me->query("name"), "("+me->query("id")+")", exp, me->query("combat_exp")),me);

			if( me->query_condition("fx_busy") > 50 )
				me->apply_condition("fx_busy",50);
		}
		else{
			for(i = 0;i<sizeof(lineup);i++){
				if( lineup[i] ){
					
								       	/*�������ƿ�ʼ*/
			        if (lineup[i]->query("registered")==3){
						exp = exp * SMY_JOB_MUL * VIP_MUL /10000;
			            		pot = pot * SMY_JOB_MUL * VIP_MUL /10000;
					}
					else
					{
						exp = exp * SMY_JOB_MUL /100;
			           		pot = pot * SMY_JOB_MUL /100;
					}
					/*�������ƽ���*/ 
					
					tell_object( lineup[i], sprintf(HIW "�ã���������ˣ���õ���" 
						+ CHINESE_D->chinese_number( exp ) 
						+ "��ʵս���飬" 
						+ CHINESE_D->chinese_number( pot )
						+ "��Ǳ�ܺ�"
						+ CHINESE_D->chinese_number( shen ) 
						+ "������\n" NOR) );

					lineup[i]->add( "combat_exp", exp );
					lineup[i]->add( "potential", pot );
					lineup[i]->apply_condition("gb_job_busy", 60);
					if( lineup[i]->query("potential") > lineup[i]->query("max_pot") )
						lineup[i]->set("potential",lineup[i]->query("max_pot"));
					lineup[i]->add("job_time/��Ч����",1);
					lineup[i]->add("job_time/��Ħ��",1);
					lineup[i]->add("shen", shen );
					lineup[i]->set("job_name", "������Ħ��");

					log_file("job/smy", sprintf("%8s%-10s��Ħ������������õ�%d�㾭�飬Ŀǰ���飺%d��",
						lineup[i]->query("name"), "("+lineup[i]->query("id")+")",exp, lineup[i]->query("combat_exp")),lineup[i]);

					if( lineup[i]->query_condition("fx_busy") > 50 )
						lineup[i]->apply_condition("fx_busy",30+random(20));
				}
			}
		}
		me->delete_temp("gb_job4");
		return 0;
	}

	if( duration == 21
	 && file_name( environment(me)) == "/d/xingxiu/silk3" ){
		me->set_temp("gb_job4/enter",1);
		me->set_temp("gb_job4/time",random(21));
	}
        
	if( duration < 21 
	 && !me->query_temp("gb_job4/enter")){
		tell_object(me,HIY "���ٶ�̫����������ʿ�ѹ���Ħ�£�����ʧ�ܡ�\n" NOR);
		log_file( "job/smy", sprintf("%8s%-10s������Ħ�������ٶ�̫��ʧ�ܣ����飺%d��",
			me->query("name"), "("+me->query("id")+")", me->query("combat_exp")),me);
		me->delete_temp("gb_job4");
		me->apply_condition("gb_job4",-1);
		me->apply_condition("job_busy",10);
		return 0;
	}
    
	if( file_name(environment(me)) == "/d/xingxiu/silk3" 
	 && me->query_temp("gb_job4")
	 && ( duration == 3 
	   || duration == 9
 	   || duration == 15
	   || duration == 21 )){
		me->add_temp("gb_job4/finish",1);
		new("/d/gb/npc/xixia-wushi")->move(environment(me));
		new("/d/gb/npc/xixia-wushi")->move(environment(me));
	}
	me->apply_condition("gb_job4", duration-1);       
	return 1;
}
