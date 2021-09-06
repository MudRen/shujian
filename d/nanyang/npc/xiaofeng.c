// xiaofeng.c
// Add by tangfeng 2004

inherit F_MASTER;
#include <ansi.h>
inherit NPC;

#define QUESTDIR "quest/�����˲�/"
#define QUESTDIR1 "quest/�����˲�/�貨΢��ƪ/"
#define QUESTDIR2 "quest/�����˲�/����Ӫ��ƪ/"
#define QUESTDIR3 "quest/�����˲�/��������ƪ/"
#define QUESTDIR4 "quest/�����˲�/���ɾ�Ԯƪ/"
#define QUESTDIR5 "quest/�����˲�/��������ƪ/"

int ask_truth();
int ask_yintui();
int ask_father();
int ask_skills();
int ask_save();
void greeting(object me);
void xiaofeng_guiyin(object me);

void create()
{
	set_name("����", ({"xiao feng", "xiao", "feng"}));
	set("gender", "����");
	set("nickname",HIB"����"NOR);
	set("title",HIY"ǰؤ�����"NOR);
	set("age", 58);
	set("long", 
		"������ؤ��ǰ�ΰ������塣\n"
		"������������࣬���ʮ�ֿ��࣬����һ�������ֿ���ʮ\n"
		"�����Ի������ӣ�˫Ŀ��磬��������\n");
	set("attitude", "peaceful");
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 40000);
	set("max_qi", 40000);
	set("jing", 15000);
	set("max_jing", 15000);
	set("eff_jing", 15000);
	set("neili", 30000);
	set("max_neili", 20000);
	set("jiali", 200);
  set("max_jingli", 15000);
  set("jingli", 15000);
	set("eff_jingli", 15000);
  set("combat_exp", 6000000);	 
	set_skill("force", 400);   
	set_skill("bangjue", 200);
	set_skill("literate", 200);        
	set_skill("medicine", 200);        
	set_skill("huntian-qigong", 420);
	set_skill("yijin-jing", 200);     
	set_skill("strike", 400);           
	set_skill("jingang-quan", 400);     
	set_skill("xianglong-zhang", 400);     
	set_skill("dodge", 400);      	     
	set_skill("xiaoyaoyou", 400);   
	set_skill("parry", 400);          
	set_skill("stick", 400);          
	set_skill("dagou-bang", 400);          
	set_skill("cuff", 400);          
	map_skill("cuff", "jingang-quan");
	map_skill("force", "huntian-qigong");
	map_skill("strike", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");
	map_skill("stick", "dagou-bang");
	set("doule_attack",1);
	prepare_skill("strike","xianglong-zhang");
  set("chat_chance_combat", 99);
  set("chat_msg_combat", ({
          (: exert_function, "huntian" :),
          (: exert_function, "shentong" :),
          (: perform_action, "strike.paiyun" :),
          (: perform_action, "strike.xiao" :),
  }));
  set("inquiry", ([
		"����" : random(2)?"�����Ҷ��ܡ�":"�Ҷ���һ���������˸�������񽣸���������˫��",
		"����" : random(2)?"���������ܡ�":"��������Ϊ��翹�������ֻ�����ڸ������Ĺ�������ү�ˡ�",
		"����" : (: ask_truth :),
		"����" : (: ask_truth :),
		"Ϊʲô" : (: ask_truth :),
		"ԭ��" : (: ask_truth :),
		//̫��ȭ���Ӿ���
		"̫��ȭ" : (: ask_skills :),
		"ȭ��" : (: ask_skills :),

		"save" : (: ask_save :),
		"help" : (: ask_save :),
		"���" : (: ask_save :),
		"���" : (: ask_save :),
		"��Ԯ" : (: ask_save :),
		"����" : (: ask_save :),

		"��Զɽ" : (: ask_father :),
		"��ʦ" : "��....����ע��һ��Ư�����������˰ɡ�",
		"ؤ��" : "ؤ�����Ҽң��Ҽ���ؤ�",
		"����" : "��һ���书�������֣�Ҳ���ǰ�����ֵ��ӡ�",
		"������" : "�������Ǵ���μ���ѧ�����֮�ء�",
		"���߹�" : "������˵��һ����Ҳ����Ϊ����Ϊ���壬�书��ߡ�",
		"����" : "......������һ����Ψһ��ǣ���ˡ�",
		"����" : "��������Ҳ�գ����Ϲֵĵ��ӣ��Ǹ������ĺ�������",
		"����" : "��������ã���˵��Ľ�ݹ�����һ��",
		"������" : "�������Ǵ���μ���ѧ�����֮�ء�",
		"����ʮ����" : "���������߽����ĳԷ��Ķ�����������",
		"����˫��" : "������������һ�У�Ҳ�������͵�һ�С�",
		"�򹷰�" : "ؤ�����֮�ⲻ��֮�书��ȷʵ�����ޱȡ�",
		"����" : (: ask_yintui :),
		"����" : (: ask_yintui :),
		"ϴ��" : (: ask_yintui :),
		"���˽���" : (: ask_yintui :),
		"��������" : (: ask_yintui :),
		"�Ⱦ�" : "������һ�ղ����޾ơ��ȿ���ʱ�֣�����һͬ�Ⱦ�ȥ��",
		"Ľ�ݸ�" : "Ľ�ݹ���ȷ���佭���Ĳɣ�ʫ���黭�����������书���ǹھ����¡�",
		"Ľ�ݲ�" : "����˵�ǣ�����Ľ�ݲ����Ľܲţ���ϧӢ�����š�",
		"������" : "��������߾�ѧ����������Ψ�Ҷ���������������ʹ�á�",
    ]));

	setup();
  carry_object(ARMOR_D("changshan"))->wear();
  carry_object(ARMOR_D("shoes"))->wear();
}

void init()
{
	object me;
	//object room;
	me = this_player();
	::init();
	if (interactive(me) && living(me)) {
		if(!me->query_condition("killer")&&me->query(QUESTDIR3+"start") && me->query_temp(QUESTDIR3+"lookcliff")&& !me->query_temp(QUESTDIR3+"over") && !me->query(QUESTDIR3+"over"))
		{
			this_object()->set("qi", this_object()->query("max_qi"));
			this_object()->set("eff_qi", this_object()->query("max_qi"));
			this_object()->set("neili", this_object()->query("max_neili")*2);
			message_vision(HIY"\nֻ��һ��Х����һ����Ӱ�Ѿ������ͱڣ�$n����һ��������$N��\n"NOR,this_object(),me); 
			command("nod "+me->query("id")); 
			message_vision(HIR"$N΢һ�������𡸻��졹�񹦣�ȫ��ǽڷ���һ�󱬶�������졣\n\n"NOR,this_object());   
			tell_object(me,CYN"�㾪�ȵء���������һ����\n"NOR);    
			message_vision(HIW"$N����������һ���������ƿ�������ȫ���ָ��ˡ�"NOR,this_object());                    
			tell_object(me,HIC"\n��û���ϵ������徹Ȼ�ָ����֮Ѹ�٣���Ȼ�ǹ����˵á�\n"NOR);  
			log_file("quest/TLBB", sprintf("%s(%s)����������Ħ�£��ش˼�¼�����飺%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) ); 
			me->set_temp(QUESTDIR3+"over",1);
			command("pat "+me->query("id")); 
			command("thank "+me->query("id"));
			remove_call_out("greeting");
			call_out("greeting",4,me);
			call_out("dest", 600,this_object());
		}
		if(!me->query_condition("killer")&& me->query(QUESTDIR4+"start") && me->query_temp(QUESTDIR4+"breakmen")&&!me->query_temp(QUESTDIR4+"helpstart") &&!me->query_temp(QUESTDIR4+"follow")&& !me->query(QUESTDIR4+"over"))
		{
			command("ah "+me->query("id"));
			message_vision(HIY"$n����ʱ��$N���������������ϣ���ɫ����������\n������һ�Ծ�̳�ѻ����о�$N��������Ӿ�Ҳ�Ǻþƺ÷���������ȱ��\n"NOR,this_object(),me);   		
			command("say û�뵽������"+RANK_D->query_respect(me) +"������ȡ�"); 
			command("touch "+me->query("id"));
			command("thank "+me->query("id"));
			me->start_busy(2);
			me->set_temp(QUESTDIR4+"helpstart",1);
			call_out("dest", 600,this_object());
		}
	} 
}

void greeting(object me)
{
	object ob=this_object();
	int i;
	if(!me)
	{
		message_vision(HIW"$N����ææ���뿪���\n"NOR,ob);
		destruct(ob);
		return;
	}
	if(environment(this_object())!=environment(me)) 
	{
		command("chat "+me->name()+"��ô������ݣ���Ȼ�޶��߿���");
		command("chat* heng "+me->query("id"));
		tell_object(me,HIG"\n�����������Ȼ�������ѣ�ʵ��Υ������֮�顣��Ľ�����������½���\n"NOR); 
		me->delete_temp("quest/�����˲�");
		me->delete_temp("quest/busy");//�����ͻ��־ȡ��
		me->delete(QUESTDIR3+"start");
		me->add("mana",-200);
		if(me->query("mana")<0) me->set("mana",0);
		return;
	}
	if(me->query(QUESTDIR3+"start") && me->query_temp(QUESTDIR3+"lookcliff")&& me->query_temp(QUESTDIR3+"over") && !me->query(QUESTDIR3+"over"))
	{
		message_vision(HIW"$N��$n��ʾ���ĵĸ�л��\n"NOR,this_object(),me);
		tell_object(me,HIG"\n\n���߹�ȥ���˿����壬���ǽ��㿴���ĸ��������壺���ǹ��ʦ������ɽ�����������һ��Ƭ���Ǹ����ӡ�ۣ�\n"
			"�Զ��׼��������˹��⽫���µ��ּ���ȥ�ˡ���\n"NOR);
		tell_room(environment(me),HIG"\n"+me->name()+"�ߵ������ǰ������˵��Щʲô��\n"NOR, ({ me }));

		command("oh");

		me->set(QUESTDIR3+"over",1);
		me->delete_temp("quest/�����˲�");
		me->delete_temp("quest/busy");//�����ͻ��־ȡ��
		me->start_busy(3);
		i=20+random(10);
		me->add("max_neili",i);
		me->add("combat_exp",me->query_skill("force")/2);
		me->add("mana",me->query_skill("force")/5);
        me->set(QUESTDIR+"time",time());
        me->set(QUESTDIR+"combat_exp",me->query("combat_exp"));
        tell_object(me,HIY"\n����"+NATURE_D->game_time()+"���ڰ�������ȷ������֮�գ����"+i+"�����������"+me->query_skill("force")/2+"�㾭���"+(int)me->query_skill("force")/5+"��������\n\n"NOR);
        log_file("quest/TLBB", sprintf("%s(%s) ��������ȷ������ҽ��ѡ���С�������%d�����������%d�㾭�飬%d��������\n", me->name(1),me->query("id"), i,(me->query_skill("force")/2),me->query_skill("force")/5) );


		command("consider");
		message_vision(HIW"\n\n$NͻȻ��Ц�������Ĺ�ãȻ���૵��������������������ˣ�����Ĳ��Ǻ��ˡ���\n"NOR,this_object());
		command("say");
		message_vision(HIC"$N��ɫ������Щ���������ƺ��Ѿ���Щ����\n"NOR,this_object());
		command("crazy");
		tell_object(me,HIW"\nͻȻ֮�䣬����������������ͷ��һ����Ϊ��������ȷ�������ˣ������������Դ��Σ�ֻ�³�͢��֪���������\n"
			"ɥ�������Ҵ�ʱ�������������֮�ʣ��������������Ĵ��ʱ��������һ������֮�ĸ����㣬���ȷ��С����Ϊ\n"
			"һ�㲻��������������Ҳ�к��˻��ˣ�Ҳ�����������壬�α�ִ������ݡ�\n\n"NOR);
		remove_call_out("check_answer");
		call_out("check_answer",3,me,1);
	}
}
void check_answer(object me,int i)
{
	object ob=this_object();
	if(!ob) return;
	if(!me) 
	{
		message_vision(HIW"$N����ææ���뿪���\n"NOR,ob);
		destruct(ob);
		return;
	}
	if(environment(ob)!=environment(me)) 
	{
		command("say "+me->name()+"ʲôʱ�����ˣ���Ҳ�����ˡ�");
		message_vision(HIC"\n$N��������ɽ�£�һ˲���Ѿ���Ӱȫ�ޡ�\n"NOR,ob);
		destruct(ob);
		return;
	}
	if(me->is_fighting(ob)||ob->is_fighting(me)) 
	{
		remove_call_out("check_answer");
		ob->set("kill_id",me->query("id"));
		message_vision(HIW"$N��$n��Цһ������Ȼ����֮Σ�����С�����ҡ�\n"NOR,ob,me);
		me->set(QUESTDIR3+"bad",1);//����ֻҪ��kill����Ϊѡ�����
		                           //���ǽ�����Ҫɱ��Ÿ�
		me->set(QUESTDIR+"time",time());
		me->set(QUESTDIR+"combat_exp",me->query("combat_exp"));
		ob->kill_ob(me);
		command("perform strike.xiao");
		command("yun huntian");
		command("yun shentong");
		return;
	}
	if(me->query(QUESTDIR3+"over"))
	{
		if(random(2)) command("haha");
		else command("smile");
		command("cry");
		if(random(2)) command("say");
		message_vision(HIC"$NԽ������Щ��\n"NOR,ob);
		if(random(2)) command("crazy");

		if(i>=10)
		{
			message_vision(HIC"$n�����ɼ䣬ֻ��$N��һ���񣬷�������ɽ�£���$n��ʱ���Ѿ���Ӱȫ�ޡ�\n"NOR,ob,me);
			log_file("quest/TLBB", sprintf("%s(%s)��Ȼ�������뿪���Ժ��û����ġ�\n", me->name(1),me->query("id")) );                  
			destruct(ob);
		}
		else
		{    	
			i++;
			if(i<2)  tell_object(me,HIR"һʱ�䣬����Ȱ�������ask xiao about ������������Ϊ���ֳ�����kill xiao������һʱίʵ���Ծ�����\n"NOR);
			else 
			{
				if(random(2)) tell_object(me,HIR"��Ȱ�������ask xiao about ������������Ϊ���ֳ�����kill xiao����˲��ľ��������������С�\n"NOR);
				else if(random(2))  tell_object(me,HIR"��ask xiao about ��������kill xiao����������ܼ򵥡�\n"NOR);
				else tell_object(me,HIR"�㻹��һ��ѡ�񣬲�ȥ��ǡ��α�����ⷳ�˵Ľ��������ء�\n"NOR);
			}
			tell_object(me,HIC"�㻹��"+(88-i*8)+"�������\n"NOR);
			remove_call_out("check_answer");
			call_out("check_answer",8,me,i);
		}
	}
}
int ask_save()
{
    object me;
    me=this_player();
    if(me->query(QUESTDIR4+"over"))
    {
    	command("thank "+me->query("id"));
		return 1;
	}
	if(!me->query_condition("killer")&& me->query(QUESTDIR4+"start") 
		&& me->query_temp(QUESTDIR4+"breakmen")
		&& me->query_temp(QUESTDIR4+"helpstart") 
		&&!me->query_temp(QUESTDIR4+"follow")
		&& !me->query(QUESTDIR4+"over"))
	{
		tell_object(me,HIC"\n����ǰ˵���������ǻ��ǸϿ��뿪�˵أ�ֻ�����Ϊ��Ӫ���㣬����������ȫ������������ؤ����֡�����\n"
			"����Զ������������ʮ��������\n"NOR);
		command("nod");
    	command("pat "+me->query("id"));
		command("say �ã�������͸Ͽ�һ�𴳳�ȥ��");
		log_file("quest/TLBB", sprintf("%s(%s)׼��������ɣ��ش˼�¼�����飺%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) ); 
		me->set_temp(QUESTDIR4+"follow",1);
		this_object()->set("daliao",me->query("id"));
		this_object()->set("qi", this_object()->query("max_qi"));
		this_object()->set("eff_qi", this_object()->query("max_qi"));
		this_object()->set("neili", this_object()->query("max_neili")*2);
		command("follow "+me->query("id"));
		message_vision(HIR"$N΢һ�������𡸻��졹�񹦣�ȫ��ǽڷ���һ�󱬶�������졣\n\n"NOR,this_object());   
		remove_call_out("check_me_where");
		call_out("check_me_where",1,me);
		return 1;
	}
	command("@@ "+me->query("id"));
	command("haha "+me->query("id"));
	command("pat "+me->query("id"));
	command("addoil "+me->query("id"));
	return 1;
}
void check_me_where(object me)
{
	object ob;
    int i;
	ob=this_object();
	remove_call_out("check_me_where");
	if(!ob->query("daliao")) return;
	if(!me || me->is_ghost()) 
	{
		ob->unconcious();
		return;
	}
	if(environment(ob)!=environment(me)) 
	{
		if(wizardp(me)) tell_object(me,HIR"\nѰ�����!\n"NOR);
		message_vision(HIW"$N����ææ���뿪���\n"NOR,ob);
		ob->set("qi", ob->query("max_qi"));
		ob->set("eff_qi", ob->query("max_qi"));
		ob->set("neili", ob->query("max_neili")*2);
		ob->move(environment(me));
		message_vision(HIW"$N�Ҵҵ����˹�����\n"NOR,ob);
		message_vision("$N�������˼���������ɫ�������ö��ˡ�\n", ob);
		message_vision("$N�������˼����������������ö��ˡ�\n", ob);
	}

	command("kill liao bing");
	command("kill liao bing 2");
	if((string)file_name(environment(me))!="/d/xingxiu/daliao/shulin")
		call_out("check_me_where",1,me);
	else
	{
		me->start_busy(1);
        tell_object(me,HIG"\n���Ǳߴ���ˣ�һ·�����������߹��ü����ط���������һ��һƬ���ֱߡ�\n"NOR);
		command("touch "+me->query("id"));
        message_vision(HIW"$N����������һ������\n"NOR,ob);
		message_vision(HIW"$N����������һ������\n"NOR,me);
		command("pat "+me->query("id"));
		command("shrug "+me->query("id"));
		command("whisper "+me->query("id")+" ������Ƭ���֣�һֱ���У�Ӧ�þͿ��Ի�����ԭ�ˡ�");
		message_vision(HIW"$NͻȻ��������������������ɽ��ʹ������ެϢ��������֧ɽ��ʹ�Ҹ�Ů����ɫ����\n"NOR,ob);
		command("say ���꺺��۴���ū�������˴�Ƭ�ط�����ū�˲������ࡣ��ʵ������������ū���Ǵ��Σ�����ս�����ܿ�Ŀ϶��ǰ��ա�");
		message_vision(HIW"$N�Ȼ�����������ȼ��Ϣ����ս����ʱ��Ұս����������������챯��������˳�������Ϲҿ�֦����ʿ��Ϳ��ç�������ն�Ϊ����\n"NOR,ob);
		command("whisper "+me->query("id")+" ������������ʥ�˲����Ѷ���֮��Ҳ�գ�������ԭ����֮��Ķ���ԹԹҲһ�ʹ�����");
		command("wave "+me->query("id"));
		command("bye "+me->query("id"));

		i=20+random(10);
		if(!me->query(QUESTDIR4+"over")) 
		{
			me->add("max_neili",i);
			me->add("combat_exp",(me->query_skill("force")+500));
			me->add("mana",me->query_skill("force")/3);
			tell_object(me,HIY"\n����"+NATURE_D->game_time()+"���ڽ�����Ӵ��ɽ�ȳ��������"+i+"�����������"+(me->query_skill("force")+500)+"�㾭���"+(int)me->query_skill("force")/3+"��������\n\n"NOR);
			log_file("quest/TLBB", sprintf("%s(%s) ���ɽ��ƪ��ɡ�������%d�����������%d�㾭�飬%d��������\n", me->name(1),me->query("id"), i,(me->query_skill("force")+500),me->query_skill("force")/3) );
		}
		me->set(QUESTDIR4+"over",1);
        me->set(QUESTDIR+"time",time());
        me->set(QUESTDIR+"combat_exp",me->query("combat_exp"));
        me->delete_temp("quest/�����˲�/���ɾ�Ԯƪ");
		me->delete_temp("quest/busy");//�����ͻ��־ȡ��
		destruct(ob);
  }
}
int ask_father()
{
    object me;
    me=this_player();
    if(me->query(QUESTDIR4+"over"))
    {
    	command("say ��Զɽ�������Ҹ��ס����ѱ����ָ�ɮ��Ϊ���ӡ�");
		  return 1;
	  }
    if(me->query(QUESTDIR3+"over"))
    {
    	command("heng");
    	command("say ��Զɽ�������Ҹ��ס��˳��ܲ�����");
		return 1;
	}
    if(!me->query(QUESTDIR3+"over"))
    {
    	command("? "+me->query("id"));
		return 1;
	}
    command("? "+me->query("id"));
	command("say ��Զɽ������ʶ......");
	return 1;
}
int ask_skills()
{
    object me;
    me=this_player();
    if(me->query("quest/�����˲�/�书/quanli"))
    {
		command("pat "+me->query("id"));
		command("say ���Ƕ�����������......");
		
		message_vision(HIY"\n$N�������һȭ�����$n��æӦ�С�������ʹ��ȭ�У�����һ���ƽƽ���棬��$Nÿһ�ж���\n"
			             +"����һ��������$n�ȷ���$nһ���У�$N���ŵ��У�Ҳ��֪��������������׳�������ж��ӱ���\n"
						 +"Ѹ�ݣ�ÿһ�ж��Ǻ��������⡰̫�泤ȭ������ȭ��ֻ����ʮ���У���ÿһ�ж����໥���ƣ�\n"
						 +"$N��׼�˶Է���ȭ�У�Ȼ���һ����ÿ��Ƶ�ȭ����$n�ɵò��ܣ�\n\n"NOR,this_object(),me);
		command("haha "+me->query("id"));
		return 1;
	}
    if(!me->query(QUESTDIR3+"over"))
    {
    	command("heng");
    	command("say ����æ�ű��𣬴˳��ܲ�����");
		return 1;
	}
    //���Կ�������һ��̫��ȭ��pfm
	//����Ϊ����ˣ������һ������ƫ��

	command("say �����书�����ؼ���һ���ڻ��ͨ�����ۺ����ˣ������ȷ����ˣ���Ҫ�����������");
	command("pat "+me->query("id"));
	command("say ��νƽ����̫��ȭ���ǽ���������������Ϊ���е��书������������ζ������˭������ᵽ��");
	command("haha "+me->query("id"));

	message_vision(HIY"\n$N�������һ��������һȭ�����һ�С�����ն������Ҳ���ǡ�̫�泤ȭ���е���������һ��\n"
		             +"�˹����������Ѽ����������Ǹ������ᣬ�����иգ����ָ��ֱ����������ﵽ��ȭ������֮\n"
					 +"���� ������һ������¶���š�\n"NOR,this_object());
	command("noshame "+me->query("id"));
	message_vision(HIY"\n$N���˵�ͷ��Ĭ����һ�ᣬ�ƺ����书֮��������һ����\n\n"NOR,me);
	me->set("quest/�����˲�/�书/quanli",1);
	me->add("combat_exp",200);
	log_file("quest/TLBB", sprintf("%s(%s) ������ѯ��ȭ�����200�㾭�顣\n", me->name(1),me->query("id")) );
	return 1;
}
int ask_truth()
{
    object me;
    me=this_player();
    if(me->query(QUESTDIR4+"over"))
    {
    	command("say һ�ж��Ѿ���ȥ�������¿�ʼ�ɡ�");
		return 1;
	  }
    if(me->query(QUESTDIR3+"over"))
    {
    	command("heng");
		command("say �˵ȴ���ܲ�����");
		return 1;
	  }
    if(!me->query(QUESTDIR3+"start"))
    {
    	command("? "+me->query("id"));
    	command("say ���У���ڻ�û��ʼ����Ҫclone�Һò���");
    	command("heng "+me->query("id"));
		return 1;
	}
	if(me->query_condition("killer"))
	{
	  	command("heng");
	  	command("say �㻹�Ǵ���ú͹ٸ��Ĺ�ϵ�ɡ�");
	  	return 1;
	}
    if(me->query(QUESTDIR3+"start")&&!me->query_temp(QUESTDIR3+"help"))
    {
    	command("? "+me->query("id"));
    	command("say ��ô�������ҵ��ң�BUG����������ʵ����˭�ڰ��㣿");
		return 1;
	}
    if(me->query(QUESTDIR3+"start")&&me->query_temp(QUESTDIR3+"help")&&!me->query_temp(QUESTDIR3+"askxiao"))
    {
    	message_vision(HIY"$N����$n��ѯ�ʣ���ʱ�ƺ������˺ܶࡣ\n"NOR,this_object(),me);
    	command("say ��Ҳ��֪������ԭί����Щ���������������ð��������Ѷ������ѣ�������ʦ�����޶˱�����");
    	command("sigh");
    	command("say ������δ��Զ�У�������λ"+RANK_D->query_respect(me) +"ȥһ����Ħ�£������˵��һ����ּ��ص����¼���");
    	command("shout");
    	command("thank "+me->query("id"));
    	me->set_temp(QUESTDIR3+"askxiao",1);
		return 1;
	}
    command("thank "+me->query("id"));
    command("say һ������"+RANK_D->query_respect(me) +"�ˡ�");
	return 1;
}
int ask_yintui()
{
    object me;
    me=this_player();
    if(me->query(QUESTDIR4+"over"))
    {
    	command("say һ�ж��Ѿ���ȥ�������¿�ʼ�ɡ�");
		  return 1;
	  }
    if(me->query(QUESTDIR3+"good"))
    {
    	command("sigh");
    	command("say Ҳ�գ����ºδ������ˡ��⽭��������Ҳ�����ˣ��Ҽ��������ˣ�Ҳ�û��Ҵ��ɡ�");
    	command("bye");
   		destruct(this_object());
		return 1;
	}
	if(me->query_condition("killer"))
	{
	  	command("heng");
	  	command("say �㻹�Ǵ���ú͹ٸ��Ĺ�ϵ�ɡ�");
	  	return 1;
	}
    if(!me->query_temp(QUESTDIR3+"good") && !me->query(QUESTDIR3+"good") && me->query(QUESTDIR3+"over")&& !me->query(QUESTDIR3+"bad"))
    {
        remove_call_out("check_answer");
    	tell_object(me,HIW"�������������ɣ�֪������Ϊ�������˵��������ȴ������Խ��Խ���꣬�����ŽУ����Ҳ��Ǻ��ˣ��Ҳ��Ǻ��ˣ�\n"
    	                  "����������²������������²��������������һ������ɽ������ȥ������ʯм�Ľ����Ƿ�������ŭ���죬����һ���Ƶ�\n"
    	                  "��ȥ����Ҫ����һ�����������ܵ�����ί������Ҫ�����ʯ�ڷ�й�����ú��������Ƴ�Ѫ��һ����Ѫ��ӡ����ʯ�ڣ���\n"
    	                  "أ�Բ�ͣ��\n\n"NOR);
		command("shout");
    	message_vision(HIY"$N���������������ɫȴ��Խ��Խ�Ǳ�ʹ��\n\n"NOR,this_object());
    	tell_object(me,HIW"��֪������������书������ʱȰ˵����ȱ���ֻ���ڹ��������ˣ�����������Цһ������Ȼ������ŭ�����㡣������\n"
    	                  "��˵���������ɷ�����𡢷ŵ��£��������к��˻��ˣ��������У���ȻҲ�к��˻��ˡ�����Ϊ�������ֵ���Σ�ֻҪ\n"
    	                  "�������壬�����»�����ҪȥҪ������\n\n"NOR);          	 
    	command("ah "+me->query("id"));
		me->set_temp(QUESTDIR3+"good",1);
		command("papaya");
    	command("consider");
		command("papaya "+this_object()->query("id"));
    	remove_call_out("xiaofeng_guiyin");
    	call_out("xiaofeng_guiyin",5,me);
		return 1;
	}
	if(me->query(QUESTDIR3+"over")&& me->query(QUESTDIR3+"bad"))
	{
		  command("heng "+me->query("id"));
		  kill_ob(me);
		  return 1;
   	}
	command("heng "+me->query("id"));
	return 1;
}
void xiaofeng_guiyin(object me)
{
   object ob=this_object();
   if(!me) 
   {
	   message_vision(HIW"$N����ææ���뿪���\n"NOR,ob);
	   destruct(ob);
	   return;
   }
  if(environment(ob)!=environment(me)) 
  {
    command("chat "+me->name()+"��ô������ݣ���Ȼ�޶��߿���");
    command("chat* heng "+me->query("id"));
    tell_object(me,HIG"\n�����������Ȼ�������ѣ�ʵ��Υ������֮�顣��Ľ�����������½���\n"NOR); 
	me->delete_temp("quest/�����˲�");
	me->delete_temp("quest/busy");//�����ͻ��־ȡ��
    me->delete(QUESTDIR3+"start");
    me->delete(QUESTDIR3+"over");
    me->add("mana",-200);
    if(me->query("mana")<0) me->set("mana",0);
	destruct(ob);
    return;
  }
  if(me->query_temp(QUESTDIR3+"good") && !me->query(QUESTDIR3+"good") && me->query(QUESTDIR3+"over")&& !me->query(QUESTDIR3+"bad"))
  {
    command("nod "+me->query("id"));
    tell_object(me,HIG"\nȴ��������ɫ������ͣ�������ԭ���Ĵ��ǻۣ�Ҳ�������������еĵ�����Ҳ����������\n"NOR);
    command("sigh");
    command("pat "+me->query("id"));
    command("say Ҳ�գ�����ͻ��Ҵ��ɣ������Լ��������������壬��������Ը�������");
    command("haha");
    command("thank "+me->query("id"));
    command("wave "+me->query("id"));
    command("bye "+me->query("id"));
    me->set(QUESTDIR3+"good",1);
	me->delete_temp("quest/�����˲�");
	me->delete_temp("quest/busy");//�����ͻ��־ȡ��
	me->set(QUESTDIR+"time",time());
	me->set(QUESTDIR+"combat_exp",me->query("combat_exp"));
	me->add("mana",me->query_skill("force")/4);
    tell_object(me,HIY"\n\n����"+NATURE_D->game_time()+"ѡ��Ȱ˵�������������Ҳ�㹦�����������"+(int)me->query_skill("force")/4+"�������Ľ�����\n\n");
	log_file("quest/TLBB", sprintf("%s(%s) ѡ��Ȱ˵����������������%d��������\n", me->name(1),me->query("id"), me->query_skill("force")/4) );
	destruct(ob);
  }
}
void kill_ob(object me)
{
 if(me->query(QUESTDIR3+"over")&& !me->query(QUESTDIR3+"good") && !me->query(QUESTDIR3+"bad"))
  {
    message_vision(HIR"$N��Хһ������Ȼ�Ҳ������״̬��Ҳ����"+me->name()+"֮������͵Ϯ�ģ�\n"NOR,this_object());
    command("chat* sneer "+me->query("id"));
   }
  ::kill_ob(me);
}
void die()
{
  object me,ob=this_object();
  int i;
  if(ob->query("kill_id")
         && (me=present(ob->query("kill_id"),environment(ob)))
	  && me->query(QUESTDIR3+"over")
	  && !me->query(QUESTDIR3+"good")
	  && me->query(QUESTDIR3+"bad"))
	{
		me->delete_temp("quest/�����˲�");
		me->delete_temp("quest/busy");//�����ͻ��־ȡ��
		me->set(QUESTDIR+"time",time());
		me->set(QUESTDIR+"combat_exp",me->query("combat_exp"));
		command("chat* heng");
		command("chat �úã�"+me->name()+"��Ȼ���Ҳ�ע��͵Ϯ�ң������书�ָ�֮�գ�������ԭ����Ѫϴ֮ʱ��");
		command("sneer "+me->query("id"));
		command("dead "+me->query("id"));
		command("bye "+me->query("id"));
		i = 10+random(20);
		me->add("max_neili",i);
		tell_object(me,HIY"\n\n����"+NATURE_D->game_time()+"ѡ��Ϊ���ֳ������������壬���"+i+"�������Ľ�����\n\n");
		log_file("quest/TLBB", sprintf("%s(%s) ѡ��������塣���%d��������\n", me->name(1),me->query("id"), i) );
		destruct(ob);
		return;
	}
  if(ob->query("daliao")
    && (me=find_player(ob->query("daliao")))
    && me->query(QUESTDIR4+"start")
    && !me->query(QUESTDIR4+"over"))
	{
		command("chat* inn "+me->query("id"));
		command("say �벻���������ǿ����"+me->name()+"��Ҫ���ң��㻹�������뿪�ɣ���Ҫ���������������л����ٻᣡ");
		command("dead");
		command("wave "+me->query("id"));
		me->set(QUESTDIR+"time",time());
		me->set(QUESTDIR+"combat_exp",me->query("combat_exp"));
		me->delete_temp("quest/�����˲�");
		me->delete_temp("quest/busy");//�����ͻ��־ȡ��
		tell_object(me,HIY"\n\n����"+NATURE_D->game_time()+"Ӫ������ʧ�ܡ�\n\n");
		log_file("quest/TLBB", sprintf("%s(%s) Ӫ������ʧ�ܣ��������������飺%d��\n", me->name(1),me->query("id"), me->query("combat_exp")));
		destruct(ob);
		return;
  }
  if(ob->query("no_death"))
  {
	  ob->set("qi", ob->query("max_qi")*2/3);
	  ob->set("eff_qi", ob->query("max_qi")*2/3);
	  ob->set("jing", ob->query("max_jing"));
	  ob->set("eff_jing", ob->query("max_jing"));
	  ob->add("neili", ob->query("max_neili")*2);
	  ob->set("jingli", ob->query("max_jingli"));
	  if(ob->is_busy()) ob->start_busy(-1);	  
	  message_vision("$N�������˼���������ɫ�������ö��ˡ�\n", ob);
	  message_vision("$N�������˼����������������ö��ˡ�\n", ob);
	  message_vision(HIR "\n$N΢һ�����������������ȫ��ǽڷ���һ�󱬶�������졣\n" NOR, ob);
	  command("heng");
	  return;
  }
  ::die();
}
void unconcious()
{
  die();
}
void dest(object ob)
{
  if(!ob) return;
  tell_room(environment(ob), HIR+"\n"+ob->name()+"�Ҵ�ææ���뿪�ˡ�\n"NOR);
  destruct(ob);
}
