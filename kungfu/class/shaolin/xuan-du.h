#include <ansi.h>
#include <job_mul.h>

string ask_me()
{
	object asker,me;
	asker = this_player();
	me = this_object();

	if( !(asker->query("luohan_winner")))
		return RANK_D->query_respect(asker)+"���޺�����û�й��������ʸ�̻����ˡ�";

	if((int)asker->query("guilty") > 0 )
		return RANK_D->query_respect(asker)+ "���۷����䣬������û���ʸ�";
		    
	if( asker->query("shen") < 0)
		return "�ҿ�"+RANK_D->query_respect(asker)+ "һ�����������������治֪�Ӻ�˵��";

	if ( asker->query("combat_exp") > 2000000)
		return "�ҿ�"+RANK_D->query_respect(asker)+"�Լ��Ѿ����Լ������ˣ��������İ����ˡ�";

	if((int)asker->query_skill("buddhism",1) < 101 
	 && asker->query_skill("dacheng-fofa",1) < 101)
		return RANK_D->query_respect(asker)+ "��ǳ�����޷����ˣ����Ƕ�����Ҫ����";

	if(me->query("family/family_name")!="������" 
    	 && me->query("class")=="bonze"
	 && me->query("family/family_name")!="������"
	 && me->query("family/family_name")!="������" )
		return "������ô�쵽�ҷ������ģ�";

	if (asker->query("class")!="bonze")
		return RANK_D->query_respect(asker)+ "���ҷ������ˣ��޷��������ˡ�";

	if( asker->query_condition("job_busy"))
		return RANK_D->query_respect(asker) + "�ոռ���������ϣ�������Ϣһ��ɡ�";

	say("\n���ɴ�ʦ˵������ʦ��Ԩ��ֿ��ڶ��ˣ��������������֡�\n");

	asker->set_temp("sl_job",1);
	
	message_vision("\n���ɴ�ʦ����һ����һ�������������ֳ�һ���ķ���̨��\n\n", asker);
      
	return "������׼�����ˣ��뽫��ͽ�������ġ�";
}

int accept_object(object ob, object obj)
{
	mapping fam;
	object me = this_object();
	int obj_exp,my_exp,got_pot,shen,got_exp;
	int skill;

	shen = obj->query("shen");

	if( !ob->query_temp("sl_job") )
	    return notify_fail("���������������ģ���ƭ��ɮ��?!\n");

	if( mapp (fam = obj->query("family")) && fam["family_name"] == "������"){
		say("����ŭ��:�����ֵ������м�ͽ���Ϻ��ж������㡣\n");
		me->kill_ob(ob);
		ob->delete_temp("sl_job");
		return 0;
	}
    
	if( obj->query_temp("last_damage_from") != ob){
		command("say ����������Ե�����Գ��ɡ�");
		ob->delete_temp("sl_job");
		return 0;
	}
	
	if ( shen > 0 ){
		command("say �㾹��һλ����֮ʿŪ���������ʲ����˼? ");    
		command("smash "+ob->query("id"));
		ob->delete_temp("sl_job");
		return 0;
	}
 
	if (userp(obj))
		return notify_fail("������Ҵ�ͨ���ף���Ϊ��ɮ��ɵ��?\n");
       
	obj_exp = (int)obj->query("combat_exp",1);
	my_exp = (int)ob->query("combat_exp",1);

	if (my_exp > obj_exp)
		return notify_fail("���Ҹ�С������Ȱ��,̫Ҳ����ݡ�\n");
    
	if ( obj->query("no_quest")){
		say("����ŭ��������һﵹ�������ţ��Ϻ��ж������㡣\n");
		me->delete("assigned_asker"); 
		me->kill_ob(ob);
		return 0;
	}    

	message_vision("$N��$nһ"+obj->query("unit")+obj->name()+"��\n", ob, me);
	message_vision( HIY"\n���ɴ�ʦ˫��һ�ӣ��ѽ�"+obj->query("name")+"������̨�����ܷ��״�����\n"NOR, ob);
	
	if( ob->query_skill("buddhism",1) <120 
	 && ob->query_skill("dacheng-fofa",1) < 120
	 && !present("jiuhuan xizhang",ob)){
		message_vision( HIR "һ����������������"+ob->name()+"��ͷ����\n" NOR, ob);
		ob->add("jing",-500);
		ob->unconcious();
		ob->delete_temp("sl_job");
		destruct(obj);
		return notify_fail("");
	}
 
	if( ob->query("family/family_name") == "������" )
		skill = ob->query_skill("dacheng-fofa",1);
	else
		skill = ob->query_skill("buddhism",1);

	got_pot = (obj_exp * 50/my_exp) + random(skill)/3 + skill/5;
	got_exp = got_pot/5+ random(got_pot)/10;

	if( got_pot > 200) got_pot = 200 + (got_pot-200)/10;

        /*�������ƿ�ʼ*/
        if (ob->query("registered")==3){
			got_exp = got_exp * SL_DUSHI_JOB_MUL * VIP_MUL /10000;
            		got_pot = got_pot * SL_DUSHI_JOB_MUL * VIP_MUL /10000;
		}
		else
		{
			got_exp = got_exp * SL_DUSHI_JOB_MUL /100;
           		got_pot = got_pot * SL_DUSHI_JOB_MUL /100;
		}
		/*�������ƽ���*/ 


	ob->add("potential",got_pot);
	if( ob->query("potential") > ob->query("max_pot"))
		ob->set("potential",ob->query("max_pot"));

	ob->add("combat_exp",got_exp);
//	ob->add("ffxm_job",1);                                     // ? �ǲ���©�˵ģ��޸����¡�
	ob->add("job_time/�𷨽�ħ",1);
	GIFT_D->check_count(ob,this_object(),"�𷨽�ħ");

	ob->apply_condition("job_busy", 5 + random(3));

	log_file("job/ffxm", sprintf("%8s%-10s��%5d�η𷨽�ħ���񣬵õ�%2d�㾭�飬%3d��Ǳ�ܣ�Ŀǰ���飺%d��\n",
		ob->query("name"),"("+ob->query("id")+")",ob->query("ffxm_job"),got_exp,got_pot, ob->query("combat_exp")),ob);
	
	ob->delete_temp("sl_job");

	if (present("jiuhuan xizhang",ob)){
		message_vision( HIR+ob->name()+"����ҡ�����������Ż����ȣ��Ż���ɣ����׶�Ϣ��\n",ob); 
		message_vision( HIR+ob->name()+"�������д�˰������ģ�һƬ��������ŷ�̨��\n",ob);
		message_vision( ob->name()+"һ���Ϻȣ��Ƶ����壬�Ĵ��ټ�������\n"NOR,ob);
		say("���ɴ�ʦ��ʲ��ݵ�:��ʦ���ޱ߷𷨶ɻ���ͽ��ʹ����ȥ��ħ�����˹���������\n");
	}
	else{
		message_vision( HIY +ob->name()+"�ڷ������д������о��ģ�Ȼ������Խ��Խ�ҡ�\n"NOR, ob);		   
		message_vision( GRN "���׽���Զȥ,��̨һƬƽ����\n"NOR, ob);
		say("���ɴ�ʦ˵��:��ʦ���Ԩ����޷�ұ���������ֻ��ʤ����ħ��ȴ�޷���֮һ����ȥ��\n");
		ob->add("neili", -200);
		ob->add("jing",-100);
		if ((int)ob->query("neili")<0 || ob->query("jing")< 0){
			ob->set("neili",0);
			ob->set("jing",0);
			ob->unconcious();  
		}  
	}

	write( sprintf(HIW "�������������������" 
	    + CHINESE_D->chinese_number( got_exp ) 
	    + "��ʵս�����" 
	    + CHINESE_D->chinese_number( got_pot )
	    + "��Ǳ�ܡ�\n" NOR),me);

	destruct(obj);
	return notify_fail("");
}
