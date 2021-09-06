 // by Xiaoyao

inherit NPC;
#include <ansi.h>
void destroying(object, object);
#include "/d/suzhou/npc/lchj.h";//���Ǿ�

string ask_shifu();
int ask_skills();
int ask_sword();
void kill_hua(object me);
int ask_outxuegu();
string ask_yuanqu();
string ask_dingdian();

void create()
{
        set_name("����", ({ "di yun", "di","yun" }));
        set("long", "����������ף�ͷ��������ֱ���������������ò�������ֱ��ͬ��ɽ�е�Ұ�ˡ�\n");
        set("gender", "����");
        set("age", 35);
        set("unique", 1);
		set("str", 30);
		set("int", 30);
		set("con", 30);
		set("dex", 30);
		set_skill("cuff", 250);
        set_skill("dodge", 250);
        set_skill("parry", 250);
        set_skill("force", 300);
        set_skill("longxiang-boruo", 250);
        set_skill("yuxue-dunxing", 250);
        set_skill("taizu-quan", 200);
        set_skill("blade", 250);
        set_skill("xuedao-jing", 300);
        set_skill("shenzhao-jing", 400);
		map_skill("force", "longxiang-boruo");
		map_skill("dodge", "yuxue-dunxing");
        map_skill("parry", "xuedao-jing");
        map_skill("blade", "xuedao-jing");
        map_skill("cuff","taizu-quan");
        prepare_skill("cuff","taizu-quan");
    set_temp("xs/longxiang",1);
		set("chat_chance_combat", 100);
		set("chat_msg_combat", ({
			(: perform_action, "blade.shendao" :),
		}));
        set("max_neili",20000);
        set("neili",25000);
        set("max_qi",26800);
        set("qi",26800);
        set("eff_jingli",18000);
        set("jingli",18000);
        set("jiali",200);
		set("no_quest",1);//
	set("inquiry", ([
		"name": "�Ҿ��ǵ��ơ�",
		"here": "������ѩɽѩ�ȡ�",
		"���վ�" : (: ask_skills :),//
		"��ʬ����" : (: ask_sword :),//
		"�ݳ���" : (: ask_shifu :),//
		"����" : (: ask_yuanqu :),//
		"ԩ��" : (: ask_yuanqu :),//
		"ԩ��" : (: ask_yuanqu :),//
		"����" : (: ask_dingdian :),//
		"����" : (: ask_outxuegu :),//
		"�뿪" : (: ask_outxuegu :),//
		"���Ǿ�" : "���Ǿ���......��û��˵����",
		"���ǽ���" : "ʲô���ǽ�������ֻѧ����ʬ������",
		"����ɽ" : "������ʦ����",
		"�Դ�ƽ" : "������ʦ����",
		"÷����" : "����ī��÷��������������ϧ����ԩ������",
		"����" : "������˪��������Ѿ�ߡ�",
		"����˼" : "��������˪���ĵ��������ǲ���Ū�˰���",
		"��˪��" : "�����Ǻ��ָ���С�㣬Ҳ�������İ����ˡ�",
		"�仨��ˮ":"��˵��ʲô�����棿���˻���ͷ����������Ѫ�����������ˣ�",
		"������":"����ƽǹ�����ɡ������Ǹ��޳ܵ�ų��",
		"���˷�":"�����ƽ����˷硱�������Ѿ���Ѫ������ɱ���ˣ�",
		"½����":"������½�󵶡��������Ѿ���Ѫ������ɱ���ˣ�",
		"ˮ�":"�����½�ˮᷡ��������Ѿ���Ѫ������ɱ���ˣ�",
		"�ݷ�":random(2)?"������һ�ݴ���İ����������ǰ��û����ϧ���ȵ�ʧȥ��ʱ��ź��Ī����":"������......ֻ��һ�ж���ȥ�ˡ�",
		"ˮ��":random(2)?"ˮ���Ҳ�����������׽������ˣ�":"�һ���ϧ��ΰ���ġ�",
	]));
    
	set("combat_exp", 1500000);
	set("shen_type", 1);
	setup();
	carry_object("/clone/armor/cloth")->wear();
	carry_object(BINGQI_D("xinyuedao"))->wield();
}
/*
void heart_beat()
{
	::heart_beat();
	clear_conditions_by_type("poison");
}
*/
int accept_object(object me, object obj)
{
		int i;
        if ((string)obj->query("id")=="wucan yi") {
			message("vision",me->name()+"������һ���ڲ��¡�\n",environment(me),({me}));
			remove_call_out("destroying");
			call_out("destroying", 1, this_object(), obj);
			if(obj->query("owner")!=me->query("id")) return notify_fail (CYN"�����ƺ�����˴�������һ����\n���ƶ�"+me->name()+"��ʾ���ĸ�л��\n"NOR);  
			command("ah "+me->query("id"));
			command("say ��λ"+RANK_D->query_respect(me)+"Ӧ���Ƕ��������Ѱɡ�");
			command("touch "+me->query("id"));
			if(me->query(QUESTDIR1+"start") && me->query_temp(QUESTDIR1+"asklaozu") && !me->query_temp(QUESTDIR1+"trust") 
				&& !me->query_temp(QUESTDIR1+"kill_hua") && !me->query(QUESTDIR1+"over"))
			{
				me->set_temp(QUESTDIR1+"trust",1);
				me->start_busy(2);
				if(!me->query(QUESTDIR1+"give_yi") )
				{
					i=500+random(300);
					me->add("combat_exp",i);//
					tell_object(me,"�������һ��"HIY"�ڲ���"NOR+"��ò��־��齱����\n");
					log_file("quest/LCHJ", sprintf("%8s(%8s)�����ڲ��»��%d���齱����\n", me->name(1),me->query("id"),i) );	
				}
				me->set(QUESTDIR1+"give_yi",1);//
				remove_call_out("kill_hua");
				call_out("kill_hua", 2, me);
				command("say ��λ"+RANK_D->query_respect(me)+"����̫��л���˰ɡ�");
				me->start_busy(1);
				return 1;
			}
			else
			{                
				command("say ����·������������ţ���λ"+RANK_D->query_respect(me)+"�ܸ�л�㰡��");
				command("goodman");
				me->start_busy(1);
				return 1;
			}
		}
       if ((string)obj->query("id")=="tangshi xuanji") {
			message("vision",me->name()+"Ҫ������һ��"HIY"��ʫѡ��"NOR+"��\n",environment(me),({me}));
			call_out("destroying", 1, this_object(), obj);
			if(obj->query("owner")!=me->query("id") 
				|| !obj->query("look_zi") 
				|| me->query(QUESTDIR2+"baozang")
				|| !me->query_temp(QUESTDIR2+"find_zi")) 
			{
				command("? "+me->query("id"));
				command("points");
				message_vision(HIW"$n���ɻ�ؿ���$N��\n"NOR, me, this_object());
				return 1;  
			}
			command("ah "+me->query("id"));
			command("say "+RANK_D->query_respect(me)+"Ī�Ǽ����ݷ���Ҳ��֪��������������ô���ˡ�");
			tell_object(me,"�������һ��"HIY"��ʫѡ��"NOR+"��ò��־��齱����\n");
			command("whisper "+me->query("id")+" "+HIY"�Ȿ��ʵ�����漰��һ�����ص����ܡ�Ŷ��������Ѿ������ˡ�"NOR);
			command("whisper "+me->query("id")+" "+HIY"��ʵ��Ҳ��һ�����壬��ν�ı��ظ��������ڡ�"NOR);
			command("whisper "+me->query("id")+" "+HIY"���귲���뱦���йص���ֻ�¶�����Ӻ����ˡ�"NOR);			
			command("say �Ȿ�飬�Ҿ����°ɡ��ܸ�л��λ"+RANK_D->query_respect(me)+"��");
			i=300+random(300);
			me->add("combat_exp",i);//
			me->set(QUESTDIR2+"baozang",1);
			me->delete_temp("quest/busy");//
			me->delete_temp(QUESTDIR);
			me->start_busy(1);
			me->set(QUESTDIR+"time",time());
			me->set(QUESTDIR+"combat_exp",me->query("combat_exp")); 
			log_file("quest/LCHJ", sprintf("%8s(%8s)��ʫѡ�����%d���齱����\n", me->name(1),me->query("id"),i) );	
			me->start_busy(1);
			return 1;
		}
		return 0;
}
void kill_hua(object me)
{
	object obj,ob;
	ob = this_object();
	if(!me) return;
	if(!ob) return;
	if(!me->query_temp(QUESTDIR1+"trust")) return;
	if(!me->query(QUESTDIR1+"give_yi")) return;
	if(me->query_temp(QUESTDIR1+"kill_hua")) return;
	if(me->query(QUESTDIR1+"over")) return;
	if(environment(ob)!=environment(me)) return;

	ob->reincarnate();
	ob->set("neili",25000);
	obj=new("/d/xueshan/npc/huatiegan");
	obj->set("no_quest",1);//
	obj->set("quest_object",me);//
	obj->move(environment());
	message_vision(HIW"ͻȻ�����Ա�����һ���ˣ��������ƣ����������ϻ��䡣\n"NOR, me, this_object());
	message_vision(HIY"$N����һ������Ȼ���������϶�����ƽǹ�������ɡ�\n"NOR, me, this_object());
	command("dead "+me->query("id"));
        message_vision(CYN"$Nŭ����$n��һ��һ�ٵش����������伷�������������������㣡������\n"NOR, ob, obj);
        message_vision(CYN"$NҲŭ����$n��һ��һ�ٵش����������伷�������������������㣡������\n"NOR, me, obj);
	obj->kill_ob(ob);
        message_vision(HIR"\n$N����$n��Ц����СС�󱲣�Ҳ�Һ��ҽ�����\n" NOR, obj,ob);
	command("kill "+obj->query("id"));
	ob->kill_ob(obj);
  return;
}
string ask_yuanqu()
{
	object me,ob;
	me = this_player();
	ob = this_object();
	if(me->query_condition("killer"))
	{
	   command("fear "+me->query("id"));
	   return ""+RANK_D->query_respect(me) +"�����Լ�С��ͨ���ɣ�";
	}
	if(me->query(QUESTDIR1+"over"))
	{
	   command("shout");
	   message_vision(HIY"$N����¶���쳣����ɫ��\n", ob);
	   return "Ϊʲô������.........��";
	}
	if(!me->query(QUESTDIR1+"start" ))
	{
	   command("?");
	   return "����˵ʲô��";
	}
	if(!me->query_temp(QUESTDIR1+"kill_hua" ))
	{
	   command("sigh");
	   message_vision(HIY"$N��Ĭ���\n", ob);
	   return "��������������";
	}
	if(!me->query_temp(QUESTDIR1+"askshifu" ))
	{
	   command("shout");
	   message_vision(HIY"$Nһֱ��Ĭ���\n", ob);
	   return "��������������";
	}
	command("flush");
	command("sigh");
	command("say �����˶����ԩ������һ��ͷ��Ҳû�С�������ʦ�����٣�Ҳ��֪��Ϊʲôʦ����Ȼ����ʦ����ͻ������\n"
		+"ʦ��Ҫɱ��ʦ��������֪����ôʦ����ȻĪ��ʧ�١��������Ǹ���ԩ���ң����ҽ��˼������꣬�������ڶ�����\n"
		+"���������˳�������Щ����������ʱ�޿��ڻ��뵱�곡�������Ǹ㲻���ס�");
	message_vision(HIY"$N����¶�����ӵ���ɫ��\n", ob);
	command("qrj");
	me->set(QUESTDIR1+"over",1);
	me->set(QUESTDIR+"time",time());
	me->set(QUESTDIR+"combat_exp",me->query("combat_exp")); 	
	me->delete_temp(QUESTDIR);
	me->delete_temp("quest/busy");//
	return "��Ҳ��֪��ʦ���������������ʲôʱ���ܹ��뿪���Ҳ�����⣡";
}
string ask_dingdian()
{
	object me,ob;
	me = this_player();
	ob = this_object();
	if(me->query(QUESTDIR1+"over"))
	{
	   command("sigh");
	   message_vision(HIY"$N����¶���������ɫ��\n", ob);
	   return "Ҳ��֪�������������ô���ˣ�";
	}
	if(!me->query(QUESTDIR1+"start" ))
	{
	   command("?");
	   return "���Ҷ�����ʲô��";
	}
	if(!me->query_temp(QUESTDIR1+"trust" ))
	{
	   command("sigh");
	   message_vision(HIY"$N�ɻ�ÿ��˿�$n��\n", ob,me);
	   return "���Ҷ�����ʲô��";
	}
	command("sigh");
	message_vision(HIY"$N����¶���������ɫ��\n", ob);
	return "Ҳ��֪�������������ô���ˣ�";
}
string ask_shifu()
{
	object me,ob;
	me = this_player();
	ob = this_object();
	if(me->query_condition("killer"))
	{
	   command("fear "+me->query("id"));
	   return ""+RANK_D->query_respect(me) +"�����Լ�С��ͨ���ɣ�";
	}
	if(me->query(QUESTDIR1+"over"))
	{
	   command("en");
	   message_vision(HIY"$N����¶�����ӵ���ɫ��\n", ob);
	   return "ʦ������ʦ��.........��";
	}
	if(!me->query(QUESTDIR1+"start" ))
	{
	   command("say");
	   return "������ʦ��������ʲô���飿";
	}
	if(!me->query_temp(QUESTDIR1+"kill_hua" ))
	{
	   command("say");
	   return "������ʦ��������ʲô���飿";
	}
	if(me->query_temp(QUESTDIR1+"askshifu"))
	{
	   message_vision(HIY"$N����¶�����ӵ���ɫ��\n", ob);
	   return "��Ҳ��֪��ʦ�����������ֻ�ǵ���һ�����䣬������Ҳ��Ī�����";
	}    
	command("say ������ʦ����");
	command("say");
	message_vision(HIY"$N����¶�����ӵ���ɫ��\n", ob);
	me->set_temp(QUESTDIR1+"askshifu",1);
	return "��Ҳ��֪��ʦ�����������ֻ�ǵ���һ�����䣬������Ҳ��Ī�����";
}
int ask_outxuegu() 
{
	object me = this_player();
	if(this_object()->is_fighting()) return 0;

/*        if(me->query("shen")=0)
	{
		command("heng");
		command("say "+HIY"�ҿ�" + RANK_D->query_respect(me) +"�����а֮����������Ҳ��Ѫ������һ��İɡ�"NOR);
		return 1;
        }  */
	if(me->query_temp(QUESTDIR1+"outxuegu"))
	{
		command("pat "+me->query("id"));
		command("say "+HIY+ RANK_D->query_respect(me) +"ֻ���Լ����������һἰʱ����ġ�"NOR);
		return 1;
	}  
	command("nod");
	command("say ��ѩ�׷ף����û��������æ��ȷ���Ѷ����뿪����ġ�");
	command("pat "+me->query("id"));
	command("say "+HIY"�ҿ�����������" + RANK_D->query_respect(me) +"һ�Ѱɣ�" + RANK_D->query_respect(me) +"ֻ���Լ�Ծ������"NOR);
	me->set_temp("quest/outxuegu",1);//
	return 1;
} 
int ask_skills() 
{
	object me = this_player();
	int i;
	if(this_object()->is_fighting()) return 0;

	message_vision("$N��$n����й����վ��İ��\n", me, this_object());
	if(!me->query(QUESTDIR1+"start"))
	{
		command("?");
		command("say ����æ�ţ���һ��ȥ��"NOR);
		return 1;
	}
	if(!me->query(QUESTDIR1+"over"))
	{
		command("pat");
		command("say ��������æ�ţ����ȵȵȡ�"NOR);
		return 1;
	}
	if(me->query(QUESTDIR4+"shenzhao")>=2 || !me->query(QUESTDIR4+"shenzhao"))
	{
		command("pat");
		command("say "+HIY"�����ȥ����������ʵ�Ҷ����վ���Щ�ط����ǲ����ڻ��ͨ��"NOR);
		command("addoil");
		return 1;
	}
	command("look "+me->query("id"));
	
	//��ͨ�������
	if(me->query(QUESTDIR4+"shenzhao_fail2")>=3 && me->query("registered")<3)
	{
		command("shrug "+me->query("id"));
		command("say �Ѿ���δ��ڣ�����ô����û������");
		command("puke "+me->query("id"));
		return 1;
	}
	//�书ѧϰ֮����Ҫ���һ�죬������Ҫ���50K
	if(me->query(QUESTDIR4+"time") && time()-me->query(QUESTDIR4+"time")<86400)
	{
		command("shake "+me->query("id"));
		command("say �����Ƚ̵�������ɣ�����ɡ�");
		return 1;
	}
	if(me->query(QUESTDIR4+"combat_exp") && me->query("combat_exp")-me->query(QUESTDIR4+"combat_exp")<50000)
	{
		command("look "+me->query("id"));
		command("say ���㵱ǰ�ľ�����»����������򣬻���ץ��ȥ����ȥ�ɡ�");
		return 1;
	}
    
	me->set(QUESTDIR4+"time",time());
	me->set(QUESTDIR4+"combat_exp",me->query("combat_exp")); 
	i= random(20);
	command("say ����統���ȷ����һ�����վ����ڹ����ҾͰ�һЩ���鴫�ڸ���ɡ�");
	command("pat "+me->query("id"));
	if(i==1)
	{
		tell_object(me,HIY"\n�����˵��Ƶ�ָ�㣬�����վ��İ����ƺ���Щ�ĵá�\n"NOR);
		tell_object(me,HIG"\n����ͼ����Ϣ�嵽�ٻ�Ѩ�У�ͻȻֻ��������һ��������һ�������Ӷ�ͷ���������ڴ�������ͨ������\n"
			             +"�ġ��н�Ѩ��������һ·���У�����Ȫ����ͻ������ᡢ���ǡ��Ϲ������á����С���ͥ���β�����ڣ�\n"
						 +"���ϡ��С������䣬����ˮ�֡����ʡ�������ʯ�š���Ԫ���м���������Ѩ���ֻص��ˡ�����Ѩ�������\n"
						 +"һ����������������֮��ȫ����˵�����ĳ������á���Ϣ��һ��ͨ��ʱ���Ǽ��ѣ��ζ�������ͨ����·��\n"
						 +"�ˣ��ڶ��Ρ�������ʱ��Ȼ��Ȼ�ķɿ����䣬���֮�䣬������һʮ�˴Ρ�\n"NOR);
		me->improve_skill("shenzhao-jing", 1000+random(me->query_int()*2));
		me->add("max_neili",10);//����10������
		log_file("quest/LCHJ", sprintf("%8s(%8s) ʧ��%d��ѧ�����վ����߾�����iȡֵ��%d|���飺%d��\n", me->name(1),me->query("id"), me->query(QUESTDIR4+"shenzhao_fail2"),i,me->query("combat_exp")) );
		command("pat "+me->query("id"));
		me->add(QUESTDIR4+"shenzhao",1);//
	}
	else
	{
		log_file("quest/LCHJ", sprintf("%s(%s) �߼����վ�ʧ��%d�Ρ�iȡֵ��%d|���飺%d��\n", me->name(1),me->query("id"),me->query(QUESTDIR4+"shenzhao_fail2"), i,me->query("combat_exp")) );
		tell_object(me,HIY"�����˵��Ƶ�ָ�㣬���Ƕ����վ��İ���ȫȻ����Ҫ�졣\n\n"NOR);
		command("sigh "+me->query("id"));
		command("disapp "+me->query("id"));
		me->add(QUESTDIR4+"shenzhao_fail2",1);//
	}
	return 1;
} 
int ask_sword() 
{
	object me = this_player();
	int i;
	if(this_object()->is_fighting()) return 0;

	message_vision("$N��$n����й���ʬ�����İ��\n", me, this_object());
	if(me->query(QUESTDIR1+"over") && me->query(QUESTDIR4+"sword") )
	{
		if(me->query("potential")>4)
		{
			me->receive_damage("jing", 10);
			tell_object(me,HIY"�����˵��Ƶ�ָ�㣬����ʬ�����İ����ƺ���Щ�ĵá�\n"NOR);
			me->add("potential",-(random(3)+1));
			if( me->query("potential")<0)
				me->set("potential",0);
			me->improve_skill("tangshi-jianfa", 30+random(me->query_int()));
			me->improve_skill("sword", random(me->query_int())/2);
		}
		else 
			tell_object(me,HIY"�����˵��Ƶ�ָ�㣬���ǻ��ǲ�����⡣\n"NOR);
		return 1;
	}
	if(!me->query(QUESTDIR1+"over"))
	{
		command("?");
		command("say ����æ�ţ���һ��ȥ��"NOR);
		return 1;
	}
	command("look "+me->query("id"));	
	//��ͨ�������
	if(me->query(QUESTDIR4+"sword_fail")>=3 && me->query("registered")<3)
	{
		command("shrug "+me->query("id"));
		command("say �Ѿ���δ��ڣ�����ô����û������");
		command("puke "+me->query("id"));
		return 1;
	}
	//�书ѧϰ֮����Ҫ���һ�죬������Ҫ���50K
	if(me->query(QUESTDIR4+"time") && time()-me->query(QUESTDIR4+"time")<86400)
	{
		command("shake "+me->query("id"));
		command("say �����Ƚ̵�������ɣ�����ɡ�");
		return 1;
	}
	if(me->query(QUESTDIR4+"combat_exp") && me->query("combat_exp")-me->query(QUESTDIR4+"combat_exp")<50000)
	{
		command("look "+me->query("id"));
		command("say ���㵱ǰ�ľ�����»����������򣬻���ץ��ȥ����ȥ�ɡ�");
		return 1;
	}
    
	me->set(QUESTDIR4+"time",time());
	me->set(QUESTDIR4+"combat_exp",me->query("combat_exp")); 
	i= random(10);
	command("say ������ʦ�ŵ��书���ҾͰ�һЩ���鴫�ڸ���ɡ�");
	command("smile "+me->query("id"));
	if(i==1)
	{
		tell_object(me,HIY"\n�����˵��Ƶ�ָ�㣬����ʬ�����İ����ƺ���Щ�ĵá�\n"NOR);
		tell_object(me,HIW"\n��һ�С����̺�������������һ�С��Ǻ᲻�ҹ��������������ǡ������羪�磬��ɽ�����ӡ������ƾ���\n"
			             +"һƥ���������˿�ȥ���������б��ǡ������д�㣬������СС����ÿһ�г�ȥ�������ƺ���Ҫ���³�Ϊ\n"
						 +"һ����ʬ����Ȼ������Щ���ţ�����������ȷ�����쳣��\n"NOR);
		me->improve_skill("tangshi-jianfa", 10+random(me->query_int()));
		command("look "+me->query("id"));
		command("buddha "+me->query("id"));
		command("haha "+me->query("id"));
		me->set(QUESTDIR4+"sword",1);//
		log_file("quest/LCHJ", sprintf("%8s(%8s) ʧ��%d��ѧ����ʬ������iȡֵ��%d|���飺%d��\n", me->name(1),me->query("id"), me->query(QUESTDIR4+"sword_fail"),i,me->query("combat_exp")) );
	}
	else
	{
		me->add(QUESTDIR4+"sword_fail",1);//
		command("buddha");
		tell_object(me,HIY"�����˵��Ƶ�ָ�㣬���Ƕ���ʬ�����İ���ȫȻ����Ҫ�졣\n\n"NOR);
		command("sigh "+me->query("id"));
		command("disapp "+me->query("id"));
		log_file("quest/LCHJ", sprintf("%8s(%8s) ��ʬ����ʧ��%d�Ρ�iȡֵ��%d|���飺%d��\n", me->name(1),me->query("id"), me->query(QUESTDIR4+"sword_fail"),i,me->query("combat_exp")) );
	}
	return 1;
} 

void destroying(object me,object obj)
{
        destruct(obj);
        return;
}

