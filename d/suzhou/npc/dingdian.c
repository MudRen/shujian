 // by Xiaoyao

inherit NPC;
#include <ansi.h>
void destroying(object, object);
#include "/d/suzhou/npc/lchj.h";
string ask_diyun();
int ask_skills();

void create()
{
        set_name("����", ({ "ding dian", "ding" }));
        set("long", "����������ף�ͷ��������ֱ���������������ò�������ֱ��ͬ��ɽ�е�Ұ�ˡ�\n");
        set("gender", "����");
        set("age", 35);
        set("unique", 1);

        set_skill("cuff", 120);
        set_skill("dodge", 120);
        set_skill("parry", 130);
        set_skill("force", 300);
        set_skill("qingmang-jianfa", 100);
        set_skill("taizu-quan", 100);
        set_skill("shenzhao-jing", 300);
        map_skill("dodge","qingmang-jianfa");
        map_skill("force","shenzhao-jing");
        map_skill("parry", "qingmang-jianfa");
        map_skill("cuff","taizu-quan");
        prepare_skill("cuff","taizu-quan");
        set("max_neili",3000);
        set("neili",3000);
        set("max_qi",1680);
        set("qi",1680);
        set("eff_jingli",1800);
        set("jingli",1800);
        set("jiali",100);
	set("inquiry", ([
		"����" : (: ask_diyun :),
		"name": "���������Ҿ��Ƕ��䣬����ʲô���飿",
		"here": "����������ݼ������ٺ١�",
		"���վ�" : (: ask_skills :),
		//"���վ�" : random(2)?"����������������ī��÷�����������������ҵ�һ���ڹ����ؾ���":"��������ģ����������֮�ھͿ������վ��ڹ��ķ����ٺ١�",
		"����" : "����������ݡ�",
		"���Ǿ�" : "���������ʲô����......",
		"���ǽ���" : "���������ʲô����......",
		"����ɽ" : "÷�����������յ�������Ф���Ӱ�����ô�������Ľ������ࡣ",
		"�Դ�ƽ" : "÷�����������յ�������Ф���Ӱ�����ô�������Ľ������ࡣ",
		"�ݳ���" : "÷�����������յ�������Ф���Ӱ�����ô�������Ľ������ࡣ",
		"÷����" : "����ī��÷��������������ϧ����ԩ������",
		"����" : "����˪��������Ѿ�ߡ�",
		"����˼" : "������˪���ĵ��������ǲ���Ū�˰���",
		"��˪��" : "�����Ǻ��ָ���С�㣬Ҳ�������İ����ˡ�",
	])); 
	set("combat_exp", 600000);
        set("shen_type", 1);
        setup();
        carry_object("/clone/armor/cloth")->wear();

}
void heart_beat()
{
	::heart_beat();
	clear_conditions_by_type("poison");
}
int accept_object(object me, object obj)
{
        object key;
        if ((string)obj->query("id")=="lu juhua") {
			message("vision",me->name()+"������һ���̾ջ���\n",environment(me),({me}));
			key = unew("/clone/armor/wucanyi");
			if(!clonep(key)) return notify_fail (CYN"����˵�������Ѿ����˸�˪���ӻ��ˣ�����������ˡ�\n"NOR);  
			if(clonep(key) && key->violate_unique()){
				destruct(key);
				return notify_fail (CYN"����˵�������Ѿ����˸�˪���ӻ��ˣ�����������ˡ�\n"NOR);
			} 
			command("touch "+me->query("id"));
			command("say ��λ"+RANK_D->query_respect(me)+"��˪���������ӻ��İ�,�ˣ����ǿ��ǿ�����ԧ�졣");
			key->set("owner",me->query("id"));//
			key->move(me);        
			message_vision("$n�ݸ�$Nһ���ڲ��¡�\n", me, this_object() );
			if(!me->query(QUESTDIR1+"start"))
						me->set(QUESTDIR1+"start",1);//��ʼ��Ŷ
			command("say ��λ"+RANK_D->query_respect(me)+"����̫��л����,�����������ȥ�ðɡ�");
			me->start_busy(1);
			remove_call_out("destroying");
			call_out("destroying", 1, this_object(), obj);
			return 1;
		}
        return 0;
}
string ask_diyun()
{
	object me,ob;
	object *obj;
	int x;
	me = this_player();
	ob = this_object();
	if(me->query_condition("killer"))
	{
	   command("fear "+me->query("id"));
	   return "���Ѿ����ݹٸ�֮�У�"+RANK_D->query_respect(me) +"�����Լ�С��ͨ���ɣ�";
	}
	if(me->query(QUESTDIR1+"over"))
	{
	   command("en");
	   message_vision(HIY"$N����¶���������ɫ��\n", ob);
	   return "ԭ�����ֵ�������ѩɽѩ��һ����������ν�������డ��";
	}
	if(!me->query(QUESTDIR1+"start" ))
	{
	   command("sneer "+me->query("id"));
	   command("say");
	   return "��֪�����ҵ��ֵܸ�ʲô����";
	}
	if(me->query(QUESTDIR1+"start" ) && (me->query_temp(QUESTDIR1+"start")|| me->query(QUESTDIR1+"over")))
	{
	   command("sigh");
	   message_vision(HIY"$N����¶���������ɫ��\n", ob);
	   return "��Ҳ��֪�����ֵ����������Ҳ�������࣬��Ը�ް���";
	}
    
	command("say");
	message_vision(HIY"$N����¶���������ɫ��\n", ob);
	command("look "+me->query("id"));
	//����ʱ��;���������
	//ʱ��һ�죬����500K
	if(me->query(QUESTDIR+"time")&&time()-me->query(QUESTDIR+"time")<86400)
	{
		command("shake "+me->query("id"));
		if(random(2)) return "�����æ�ˣ�"+RANK_D->query_respect(me) +"������Ϣȥ�ɣ�";
		else return "Ѱ�ҵ��ֵ�Ҳ���ü���һʱ��"+RANK_D->query_respect(me) +"������Ϣȥ�ɣ�";
	}
if (!me->query("cw_exp"))
        if(me->query(QUESTDIR+"combat_exp")&&me->query("combat_exp")-me->query(QUESTDIR+"combat_exp")<500000)
	{
		command("sigh "+me->query("id"));
		return "��"+RANK_D->query_respect(me) +"Ŀǰ�ľ������ȥ�ң�Ҳ�ﲻ��ʲôæ������ץ�������ɣ�";
	}
	obj = users();
	x = sizeof(obj);
	while(x--)
	{
		if ( obj[x]->query_temp(QUESTDIR1+"start")&& obj[x]!=me) 
			return ""+obj[x]->query("name")+RANK_D->query_respect(obj[x]) +"�Ѿ�ȥѩɽѰ�ҵ��ֵ��ˣ�"+RANK_D->query_respect(me) +"������ô�ż���";		  
	}
	command("say ����"+RANK_D->query_respect(me) +"�������̾ջ���ĺܸ�л�ˡ�");
	command("thank");
	command("say �����ҵ�ȷ��ʶһ���е��Ƶĺ��ֵܣ�ֻ�ǳ�������˵��ѩɽ��Ѫ������ץ���ˡ�");
	command("yumen");
	command("shout");
	//�趨��־
	me->set(QUESTDIR+"time",time());
	me->set(QUESTDIR+"combat_exp",me->query("combat_exp")); 	
	me->set_temp(QUESTDIR1+"start",1);
	me->set_temp("quest/busy",1);
	log_file("quest/LCHJ", sprintf("%8s(%8s)����ڲ��£�����ʼִ��Quest��\n", me->name(1),me->query("id")) );	
	return "";
}
int ask_skills() 
{
	object me = this_player();
	int i;
	if(me->query(QUESTDIR1+"start") && me->query(QUESTDIR4+"shenzhao"))
	{
		if(me->query("potential")>4)
		{
			message_vision("$N��$n����й����վ��İ��\n", me, this_object());
			me->receive_damage("jing", 10);
			tell_object(me,HIY"�����˶����ָ�㣬�����վ��İ����ƺ���Щ�ĵá�\n"NOR);
			me->add("potential",-(random(3)+1));
			if( me->query("potential")<0)
				me->set("potential",0);
			if(me->query(QUESTDIR4+"shenzhao") < 2 && me->query_skill("shenzhao-jing")>=300)
			{
				if(random(6)==1) tell_object(me,HIR"����ͻȻ�����ص�ָ��������������վ��Ѿ�����ȵز�������Ѱ�ҵ�����Ҳ���и�����˽⡣\n"NOR);			
				me->improve_skill("shenzhao-jing", 10+random(me->query_int()));//ѧϰ�ٶȱ仯
			}
			else
			{
				if(me->query_skill("shenzhao-jing")>=300 || me->query_skill("shenzhao-jing")<=250)//ѧϰ�ٶȿ���
				{
				   me->improve_skill("shenzhao-jing", 25+random(me->query_int()*2));
			     me->improve_skill("force", random(me->query_int())/2);
			  }
			  else
			  {
				   me->improve_skill("shenzhao-jing", 25+random(me->query_int()));
			     me->improve_skill("force", random(me->query_int())/2);
			  }
			}
			

		}
		else 
		{
			message_vision("$N��$n����й����վ��İ��\n", me, this_object());
			tell_object(me,HIY"�����˶����ָ�㣬���ǻ��ǲ�����⡣\n"NOR);
		}
		return 1;
	}
	if(me->query(QUESTDIR1+"start"))
	{
		command("look "+me->query("id"));
		//��ͨ�������
		if(me->query(QUESTDIR4+"shenzhao_fail")>=3 && me->query("registered")<3)
		{
			command("papaya "+me->query("id"));
			command("say �Ѿ���δ��ڣ���λ"+RANK_D->query_respect(me) +"��ô����û������");
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
if (!me->query("cw_exp"))
	   if(me->query(QUESTDIR4+"combat_exp") && me->query("combat_exp")-me->query(QUESTDIR4+"combat_exp")<50000)
	   {
		   command("look "+me->query("id"));
		   command("say ��"+RANK_D->query_respect(me) +"��ǰ�ľ�����»����������򣬻���ץ��ȥ����ȥ�ɡ�");
		   return 1;
	   }

	   me->set(QUESTDIR4+"time",time());
	   me->set(QUESTDIR4+"combat_exp",me->query("combat_exp")); 
	   i= random(15);
	   if(i==1)
	   {
		   command("say ��������ī��÷�����������������ҵ�һ���ڹ����ؾ����Ҿʹ��ڸ�"+RANK_D->query_respect(me) +"�ɡ�");
		   command("say �����վ��������������ڹ���������ǿ�������ķ��š�");		   
		   command("pat "+me->query("id"));
		   tell_object(me,HIY"�����˶����ָ�㣬�����վ��İ����ƺ���Щ�ĵá�\n\n"NOR);
		   me->improve_skill("shenzhao-jing", 5+random(me->query_int()));
		   me->improve_skill("force", random(me->query_int())/2);
		   command("haha "+me->query("id"));	
		   command("gao");
		   command("u&me "+me->query("id"));
		   me->set(QUESTDIR4+"shenzhao",1);//
		   log_file("quest/LCHJ", sprintf("%s(%s) ʧ��%d��ѧ�����վ�������iȡֵ��%d|���飺%d��\n", me->name(1),me->query("id"), me->query(QUESTDIR4+"shenzhao_fail"),i,me->query("combat_exp")) );
	   }
	   else
	   {
		   command("say ��������ī��÷�����������������ҵ�һ���ڹ����ؾ����Ҿʹ��ڸ�"+RANK_D->query_respect(me) +"�ɡ�");
		   if(random(2)) command("say ��������ģ����������֮�ھͿ������վ��ڹ��ķ����ٺ١�");
		   command("say �����վ��������������ڹ���������ǿ�������ķ��š�");		
		   command("ah "+me->query("id"));
		   tell_object(me,HIY"�����˶����ָ�㣬���Ƕ����վ��İ���ȫȻ����Ҫ�졣\n\n"NOR);
		   command("sigh "+me->query("id"));
		   me->add(QUESTDIR4+"shenzhao_fail",1);//
		   command("courage");   		   
		   log_file("quest/LCHJ", sprintf("%s(%s) ѧϰ���վ�ʧ��%d�Ρ�iȡֵ��%d|���飺%d��\n", me->name(1),me->query("id"), me->query(QUESTDIR4+"shenzhao_fail"),i,me->query("combat_exp")) );
	   }
	   return 1;
	} 
	command("hehe");
	command("say �������������վ�������ī��÷�����������������ҵ�һ���ڹ����ؾ���");
	command("smash");
	return 1;
}
void destroying(object me,object obj)
{
        destruct(obj);
        return;
}

