// ��ʱ���� 40 ����¥���ֿ��Զһ�1ͨ���� by lsxk@hsbbs 2007/7/2

#define SJ_CREDIT_RATE 40  // ��ʱ�������ֶ�ͨ��Ϊ40:1   By lsxk@hsbbs

inherit FIGHTER;
#include <ansi.h>

//string *str_menpai = ({ "wd","hs","ss","gm","gb","tz","dls","sld","mj","thd","kl"});       
//#include "/d/city/npc/skills_pfm.h";
int ask_sj();
int ask_sj_credit();
int ask_up();
void go_up(object me);
int do_duihuan(string);

string *valid_types =
({
	"claw",
	"cuff",
	"finger",
	"hand",
	"leg",
	"strike",
});

void create()
{
	set_name("����", ({ "laopu"}));
	set("long", "һ�����ص����ˣ����ư׷��Բԣ�ȴ��˫Ŀ��磬��������\n");
	set("long_base", HIG"һ�����ص����ˣ����ư׷��Բԣ�ȴ��˫Ŀ��磬��������\n"NOR);
	set("gender", "����");
	set("age", 33);
	set("attitude", "peaceful");
	set("shen", -100);
	set("rank_info/rank","����");
	set("rank_info/self_rude","����");
	set("rank_info/self","����");
	set("rank_info/rude","����");
	set("rank_info/respect","����");
	set("rank_info/color","HIW");
	set("age",80+random(30));
	set("no_quest",1);//

        set("str", 300);
        set("int", 300);

        set("con", 300);
        set("dex", 300);
        set("per", 30);
	set("max_qi", 500);
	set("max_jing", 500);
	set("eff_jingli",400);
	set("neili", 100);
	set("max_neili", 100);
	set("jiali", 20);
	set("combat_exp", 8000+random(500));

	set_skill("force", 70);
	set_skill("dodge", 80);
	set_skill("unarmed", 70);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("cuff", 80);
	set("inquiry", ([
		"name" : random(2)?"�����Ѿ�һ����ͣ�������������ˡ�":"�Ǻǣ��н���ľ��������������ˡ�",
		"����" : random(2)?"�����Ѿ�һ����ͣ�������������ˡ�":"�Ǻǣ��н���ľ��������������ˡ�",
		"����":  "��������˭�����˾������ˡ�����ֻ��������Щ�������Ӳ��������ţ�\n��һ��Ҫ��������Ҳ�������˳���Ϊ��ң�ӡ�",
		"����¥":  "�������Σ����Ǻ���������ѱ棬����¥ȥ��ʶ��ʶô��",

		"�齣" : (: ask_sj :),
		"�ξ�" : (: ask_sj :),
		"�λ�" : (: ask_sj :),
		"��¥" : (: ask_up :),
           "����¥����" : (: ask_sj_credit :),
		"��ʦ" : "��....������ע��һ��Ư�����������˰ɡ�",
    ]));

	setup();
	carry_object(ARMOR_D("shoes"))->wear();
	carry_object(ARMOR_D("changshan"))->wear();
}
void init()
{
    object me,ob; 
	object *obj;
	int i,p;
    mapping skill, pmap;
    string *skl;


    string force_name;
    ::init();
    ob = this_object();
    me = this_player();
    if(ob->is_fighting()) return;
	obj = all_inventory(ob);
	i = sizeof(obj);
	while (i--) {
		if(!userp(obj[i]) && obj[i]->query("weapon_prop"))
			destruct(obj[i]);
	}
	pmap = ob->query_skill_prepare();
	if (pmap)
	{
		skl = keys(pmap);
		foreach (string item in skl)
			ob->prepare_skill(item);
		ob->reset_action();
	}
	skill = ob->query_skills();
	skl = keys(skill);
	i = sizeof(skl);
	while (i--) {
		ob->delete_skill(skl[i]);
	}
	p=ob->query("max_skill");
	i=me->query("max_pot");
	i=i-100;
	if(i<p) i=p; 
	if(i<250) i=250;
	ob->set("max_skill",i);
   	ob->set("party",str_menpai[random(sizeof(str_menpai))]);  	  
//         ob->copy_menpai(({ob->query("party")}),1,random(2),100)
//����npc�������书��                                                   ^M
	ob->copy_state();				//�������ɸ���npc ��һЩ״̬
	ob->set_skills_level(i);
	ob->set("max_neili",me->query("max_neili"));
	ob->set("max_jingli",me->query("max_jingli"));
	p=ob->query("max_qi");
	i=me->query("max_qi")*2;
	if(i<p) i=p;
	ob->set("max_qi",i);
	ob->set("max_jing",me->query("max_jing"));
	ob->set("neili",query("max_neili")*3/2);
	ob->set("jingli",query("max_jingli")*3/2);
	ob->set("eff_jingli",query("max_jingli")*3/2);
	ob->set("qi",query("max_qi"));
	ob->set("eff_qi",query("max_qi"));
	ob->set("jing",query("max_jing")*3/2);
	ob->set("eff_jing",query("max_jing")*3/2);
	if(!stringp(force_name = to_chinese(ob->query_skill_mapped("force"))))
		force_name = "������";
	ob->set("long",ob->query("long_base")+
 //               HIG"����һ���书"+HIW+force_name+HIG"���ѷ�豹��棬�ƺ���"+HIW+ob->query("family/family_name")+HIG"�йء�"NOR)
                HIG"һ���书"+HIW+force_name+HIG"���Ѿ�����ȴ�������ķ�豹����ˡ�"NOR);
    ob->set("jiali",me->query("jiali"));
	ob->set("combat_exp",me->query("combat_exp"));
	ob->set_skill("literate",ob->query("int")*10); 	 											//full literate
	ob->set_skill("wuxing-zhen",ob->query("int")*10); 	
	pmap = ob->query_skill_prepare();
	if (!pmap)
	{
		i=sizeof(valid_types);
		p=0;
		while (i--)
		{
			if (!ob->query_skill(valid_types[i], 1)) continue;
			if (ob->query_skill_mapped(valid_types[i]))continue;
			if(p>=2) continue;
			p=p+1;
			ob->prepare_skill(valid_types[i], ob->query_skill_mapped(valid_types[i]));
		}
	}	
}
int ask_sj_credit()
{
    object me=this_player();
    int i;
    i = (int)me->query("quest/special/score",1);
    if( i<1 ){
        command("say "+(string)me->query("name")+",��ĵ���¥����Ϊ"HIR"��"CYN",Ҫ���Ŭ�����а���"NOR);
        return 1;
    }
    else if(i<50) {
        command("say "+(string)me->query("name")+",��Ŀǰ�ĵ���¥����Ϊ��"+HIY+chinese_number(i)+CYN+"�֣�����Ŭ����"NOR);
        command("addoil "+(string)me->query("id"));
        return 1;
    }
    else {
        command("say "+(string)me->query("name")+",��Ŀǰ�ĵ���¥����Ϊ��"+HIY+chinese_number(i)+CYN+"�֣�"NOR);
        command("haha "+(string)me->query("id"));
        command("gao "+(string)me->query("id"));
        command("say ������"+(string)me->query("name")+"�����¥ս���Իͣ����Ը�⣬�������������һ��齣ͨ�����㵱�����ɣ�"NOR);
        write(HIR"�һ�ָ�"+HIC+"duihuan XXX to ͨ��\n"NOR);
        write(HIG"����XXXΪ��Ҫ�һ����ĵ���¥����������\n"NOR);
        add_action("do_duihuan", ({"duihuan"}));
        return 1;
    }
}

int do_duihuan(string arg)
{
    object me=this_player();
    int i,j;
    string str;

    j=(int)me->query("quest/special/score",1);
   if (!arg){
       write("��Ҫ�һ�ʲô?\n");
       return 1;
    }
   if( sscanf(arg, "%d to %s",i,str) ){
       if(str!="ͨ��"){
       write("��Ҫ������¥���ֶһ���ʲô?\n");
       return 1;
       }

       if(j<i){
           write(HIR"������ô�����¥����ô��\n"NOR);
           return 1;
       }

       if( i< SJ_CREDIT_RATE){
           write(HIW"�����Ҫ���Ѵ���"+HIM+chinese_number(SJ_CREDIT_RATE)+HIW+"�����¥���ֲ��ܶһ�ͨ����\n"NOR);
           return 1;
       }

       if( j< SJ_CREDIT_RATE){
           write(HBRED"��Ŀǰ�ĵ���¥���ָ��������һ�һ���齣ͨ���������Ŭ����\n"NOR);
           return 1;
       }
       me->add("SJ_Credit",i/SJ_CREDIT_RATE);
       me->add("quest/special/score",-i);
       write(HIG"�һ����!��˴ζһ�������"+HIM+chinese_number(i)+HIG+"�����¥���֣�������"+HIW+chinese_number(i/SJ_CREDIT_RATE)+HIG+"��ͨ����\n"NOR);
       return 1;
   }
   else{
       write(HIR"\n�һ�ָ�"+HIC+"duihuan XXX to ͨ��\n"NOR);
       write(HIG"����XXXΪ��Ҫ�һ����ĵ���¥����������\n"NOR);
       write(HIY"\n�밴����ȷ��ʽ���룬������ͨ���һ���\n"NOR);
       return 1;
   }
}

int ask_up()
{
    object me;
	object *obj;
	int x,p;
	mapping mp;
	me=this_player();
   if((int)me->query("quest/special/up/time")+86400 > time())
   {
           command("say �����ս���ã����Ƕ���Ϣһ�°ɣ�\n");
           return 1;
}
    if(me->query_condition("db_exp"))
{
            command("shake");
            command("say �������о�Ӣ֮��״̬,���ǸϿ�ȥ�����ɣ�");
            return 1;
}
	if(me->query_condition("killer"))
	{
		command("sigh");
		command("say ���ڽ���������û�а��Ѫ��Ⱦ�֡��Ϸ�����⣬ֻ�ǹٸ���һ��......");
		message_vision(HIY"$NľľȻ����������֮������ͷ��ʱ��û�����\n"NOR,this_object());
		return 1;
	}
	if(me->query_condition("job_busy"))
	{
		command("sigh");
		command("say ������"+me->query("job_name")+"���񣬻�����΢��Ϣһ�°ɣ�");
		message_vision(HIY"$NľľȻ����������֮������ͷ��ʱ��û�����\n"NOR,this_object());
		return 1;
	}
	if(me->query_temp("��ػ�job")||me->query_temp("tdhjob"))
	{
		command("pat "+me->query("id"));
		command("say ��ػ������æ�ɣ�");
		message_vision(HIY"$NľľȻ����������֮������ͷ��ʱ��û�����\n"NOR,this_object());
		return 1;
	}
	if(me->query("neili")<me->query("max_neili"))
	{
		command("pat "+me->query("id"));
		command("say ���������㣬���ȫ��һս��");
		message_vision(HIY"$NľľȻ����������֮������ͷ��ʱ��û�����\n"NOR,this_object());
		return 1;
	}
	if(me->query("eff_jing")<me->query("max_jing"))
	{
		command("pat "+me->query("id"));
		command("say �㾫Ѫ���㣬���ȫ��һս��");
		message_vision(HIY"$NľľȻ����������֮������ͷ��ʱ��û�����\n"NOR,this_object());
		return 1;
	}
	if( mapp(mp = me->query_conditions_by_type("poison")) && sizeof(mp)>0 )
	{
		command("sigh");
		command("say "+me->query("name")+"�������κ��Լ��Ĳ���˵�ɣ�");
		message_vision(HIY"$NľľȻ����������֮������ͷ��ʱ��û�����\n"NOR,this_object());
		return 1;
	}
	if( mapp(mp = me->query_conditions_by_type("killer")) && sizeof(mp)>0 )
	{
		command("sigh");
		command("say "+me->query("name")+"�����Ƚ�����Լ��ĸ��˶�Թ�����ɣ�");
		message_vision(HIY"$NľľȻ����������֮������ͷ��ʱ��û�����\n"NOR,this_object());
		return 1;
	}
	if( mapp(mp = me->query_conditions_by_type("hurt")) && sizeof(mp)>0 )
	{
		command("sigh");
		command("say "+me->query("name")+"����������һ�����������ɣ�");
		message_vision(HIY"$NľľȻ����������֮������ͷ��ʱ��û�����\n"NOR,this_object());
		return 1;
	}
	if(wizardp(me) && !me->query("env/mengdie_test")) 
	{
		command("sigh");
		command("say "+me->query("name")+"���Ͼͱ����ˣ�ר�ĸ㿪��ȥ�ɣ�");
		message_vision(HIY"$NľľȻ����������֮������ͷ��ʱ��û�����\n"NOR,this_object());
		return 1;
	}
	obj = deep_inventory(me);
	p = sizeof(obj);
	while (p--)
	{
		if (obj[p]->is_character() )
		{
			command("sigh");
			command("say "+me->query("name")+"�������"+obj[p]->query("name")+"��ʲô����Ŷ��");
			message_vision(HIY"$NľľȻ����������֮������ͷ��ʱ��û�����\n"NOR,this_object());
			return 1;
		}
		if(obj[p]->query("unique"))
		{
			command("sigh");
			command("say "+me->query("name")+"�������"+obj[p]->query("name")+"���Ǳ��ﰡ������̫Σ���ˣ�");
			message_vision(HIY"$NľľȻ����������֮������ͷ��ʱ��û�����\n"NOR,this_object());
			return 1;
		}
	}
	if(!me->query_temp("quest/special/sj") )
	{
		command("sigh");
		message_vision(HIY"$NľľȻ����������֮������ͷ��ʱ��û�����\n"NOR,this_object());
		return 1;
	}
	if(me->query_temp("quest/special/up"))
	{
		command("sigh");
		me->delete_temp("quest/special");
		message_vision(HIY"$NľľȻ����������֮������ͷ��ʱ��û�����\n"NOR,this_object());
		return 1;
	}
	//ֻ��һ������
	obj = users();
	x = sizeof(obj);
	while(x--)
	{
		if ( obj[x]->query_temp("quest/special/up") && obj[x]!=me) 
		{
			message_vision(HIY"$NľľȻ����������֮��������̧��ͷ����\n"NOR,this_object());
			command("say ����"+obj[x]->query("name")+"����Ѱ��ȥ�ˣ�"+me->query("name")+"���ǰ��˰ɣ�");	
			return 1;
		}
	}
	message_vision(HIY"$N���ص�һЦ��˵���������ε�С¥���Ǽ��������������ڱ���֮�⣬�������֮�С�������\n"NOR,this_object());
	if(!me->query_temp("quest/special/enter"))
	{
		command("hehe");
		return 1;
	}
	message_vision(HIY"$N����Ц���������ӣ�$n������־��㱡���\n"NOR,this_object(),me);
	me->set_temp("quest/special/up",1);
   me->set("quest/special/up/time",time());
	remove_call_out("go_up");
	call_out("go_up",4,me);
	return 1;
}
void go_up(object me)
{
	object ob,room;
	ob=this_object();
	if(!me) return;
	if(!me->query_temp("quest/special/sj")) return;
	if(!me->query_temp("quest/special/up")) 
	{
		message_vision(HIB"$NͻȻ������ʲô�Ƶģ�΢΢һ���֣�$n��ʱ���ѣ������Լ���Ȼ������"HIW"�����°���"HIB"��\n"NOR,this_object(),me);
		return;
	}
	if(environment(ob)!=environment(me))
	{
		me->delete_temp("quest/special");
		command("hmm");
		return;
	}
	if (!(room = find_object("/d/city/diemenglou1")))
		room = load_object("/d/city/diemenglou1");
	if(!room)
	{
		message_vision(HIY"\n��������֮�䣬����$n�Ѿ����������ߣ�$N�Ѳ�֪����ȥ�ˡ�����\n"NOR,this_object(),me);
		me->delete_temp("quest/special");
		me->move("/d/city/hubian1");
		return;
	}
	command("smile");
	me->move(room);
	message_vision(HIY"\n��������֮�䣬����$n�Ѿ���һ��̨֮ͤ�У�$N�Ѳ�֪����ȥ�ˡ�����\n"NOR,this_object(),me);
	return;        	
}
int ask_sj()
{
    object me;
    me=this_player();
    if(me->query_temp("quest/special/sj"))
    {
		message_vision(HIY"$NľľȻ����������֮������ͷ�������\n"NOR,this_object());
		return 1;
	}
	message_vision(HIY"$NľľȻ����������ڤ�������㣬����Ϊ���������\n"NOR,this_object());
	message_vision(HIY"$NľľȻ����������֮�󣬲�֪�䡭����ǧ��Ҳ����\n"NOR,this_object());
	message_vision(HIY"$NľľȻ����������������Ϊ����������Ϊ����������\n"NOR,this_object());
	message_vision(HIY"$N������������齣�����������Ρ�����������������Ϊ����������\n"NOR,this_object());
	me->set_temp("quest/special/sj",1);
	return 1;
}
int accept_object(object who, object ob)
{
   if(userp(ob)) return 0;        
   if((ob->query("id") == "silver"||ob->query("id") == "gold") && ob->value() >= 5000)
   {
      message_vision(HIW"$N����ؽ����������������㣬��ô�ҵ�������\n"NOR,this_object());
	  command("say");
	  command("hoho");
	  who->set_temp("quest/special/enter",1);
	  return 1;
   }
   message_vision("$N������ҡ��ҡͷ���������㣬��ô�ҵ�������\n",who);
   return 0;
}

