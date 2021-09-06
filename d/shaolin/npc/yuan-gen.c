// yuangen.c
// creat by tiantian, modify by looklove

#include <ansi.h>
inherit NPC;

int ask_job();

void create()
{
	set_name("Ե��", ({ "yuan gen", "yuan", "gen" }) );
	set("gender", "����" );
	set("age", 38);
	set("long", "���ǲ�԰�ӵ�����ɮ�ˣ�����ƽӹ���Ȳ���������壬\n"
        "����Ҳûʲô������ƽ����ϲ�����������\n");
    	set("nickname","��԰����");
	set("str", 25);
	set("dex", 20);
	set("con", 17);
	set("int", 15);
	set("shen_type", -1);

	set_skill("unarmed", 50);
	set_skill("dodge", 35);
	set_temp("apply/attack", 5);
	set_temp("apply/attack", 5); 
	set_temp("apply/defense", 5);
	set("combat_exp", 17500 + random(20000));

	set("attitude", "peaceful");
	set("inquiry", ([
		"�ֲ�": (: ask_job :)
	]));
	set("chat_chance", 2);
	set("chat_msg", ({
		CYN"Ե�����������˵�������Ǵ�ĦԺ���޺��õ��������˽䣬ֻҪ�Ƿ�����԰�ӣ���һ��Ҫ�ʸ����ף�\n"NOR,
        }) );
                        
	setup();
	carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

int ask_job()
{
	object me=this_player(), ob=this_object();
	int exp1=me->query("combat_exp");
    
	if( me->query("family/family_name") != "������" ){
		command("say "+RANK_D->query_respect(me)+"�������������������˻���֪�Ӻ�˵��");
		return 1;
	}
    
	if( me->query("class")!="bonze"){
		command("say "+RANK_D->query_respect(me) +"���׼ҵ��ӣ�����������ѧ�ա�");
		return 1;
	}
        
        if ( me->query_condition("job_busy")) { 
        	command("say ������û�գ��Ȼ����ɡ�");
        	return 1;
        }

	if( exp1 < 30000 || exp1 > 60000 ){
		command("say ����û�������������ҿ�������Ƿ��ˡ�");
		command("walkby "+me->query("id"));
		return 1;
	}
    
	if( present("tie tong", me)){
		command("say �㲻��������Ͱ�𣿿�ȥ�ɻ�ɡ�");
		return 1;
	}

	command("say �����㰡�����Ϻ��װף�����͵�Ի��ȣ���Ҳ���ǣ�");
	message_vision(CYN"Ե�����ж�ݺݵض�$N˵�ĵ�������ÿ����һ�ٵ���ˮ���ˣ�ֻ������\n"+
		"һ��������Ӳ�ⵣ�������Ӵ��������ȡ���ȥ��\n��"NOR,me);
	if(!present("tie tong",environment()))
	new("/d/shaolin/obj/tie-tong")->move(environment(this_object()));
	message_vision("$N������ó�һ�Դ���Ͱ���ڵ��ϡ�\n", ob);
	me->set_temp("jiaoshui_job",1);
	me->apply_condition("job_busy", 5+random(5));
	if( random(10) < 1 ){
		message_vision(CYN"Ե��������������У��Ʋ�����СС��ͣ���Ȼ��˵�����Ϊ��ʲô\n"
			+"���ɶ�ȥ����һ�������ղ����سͷ�����γ��������ж�������\n"NOR,me);
		message_vision("$N����һ����֦��ûͷû�Եı���$Nͷ�ϳ�����\n"NOR,this_object());
    	    	message_vision("$N���Ҷ������������Ƭ��֮�䣬��������ͷ����������Ѫ��\n",me);
        	me->add("eff_qi",-(me->query("eff_qi") > 150)?me->query("max_qi")/3:50);
        	if(me->query("eff_qi") <= 0)
            		me->set("eff_qi",1);
        	me->unconcious();
    	}
    	return 1;
}
