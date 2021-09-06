//man.c for dzd job by Ciwej@SJ
//show one chat robot here ^_^

#include <ansi.h>
#define XKD_D "/d/foshan/xkdd.c"

inherit NPC;

string ask_job();
int debug_trigger(string arg);
int ask_dzd();

void create()
{
	set_name("��������", ({ "zhongnian nanzi","man" }));
	set("gender", "����");
    	set("age", 37);
    	set("long", @LONG
����һ�������Ѯ���������ӡ�
���ϴ��ŵ����ĳ��ݣ��ƺ�����û�ع����ˡ�
LONG);
    	set("combat_exp", 10000000);
    	set("shen", 10000000);
    	set("shen_type", 1);
	set("attitude", "peaceful");
	set("job_npc",1);
	set("no_ansuan",1);
	set("no_get", "�������Ӷ������̫���ˡ�\n");
	
	set("unique", 1);
			
	set("inquiry",
	([
		"����":(:ask_job:),
		"���ǵ�" : (: ask_dzd :),
		"name":"��С�����֣�̫�������벻������",
		//"�㽶":(:debug_trigger:),
		//"rumors":"��������ֳ����Ʒ������ڽ������������壬���⽭����",
		]) );
	
    	set_skill("strike", 470);
	set_skill("dodge", 470);
	set_skill("parry", 470);
	set_skill("tiyunzong", 470);
	set_skill("taizu-quan", 470);
	set_skill("cuff", 470);
	set_skill("force", 470);
	set_skill("hamagong", 470);
	set_skill("literate", 200);
	
	map_skill("force","hamagong");
	map_skill("strike","hamagong");
	map_skill("parry","hamagong");
	map_skill("dodge","tiyunzong");
	map_skill("cuff","taizu-quan");
	
	prepare_skill("strike","hamagong");
	prepare_skill("cuff","taizu-quan");
	
	set("max_qi",20000);
	set("max_jing",20000);
	set("max_jingli",20000);
	set("eff_jingli",20000);
	
	set("oyf/hamagong",3);
	
	set("chat_chance_combat", 99);
	set("chat_msg_combat", ({
 		(: exert_function, "nizhuan" :),
 		(: perform_action, "strike.hama" :),
	}));
	
	set("chat_chance", 99);
	set("chat_msg", ({
		(: exert_function, "nizhuan" :),
 		(: perform_action, "strike.hama" :),
 		//query("name")+"���˴�ü���ƺ���Ҫ˵Щʲô��\n",
	}) );
					
    	add_temp("apply/attack", 50);
    	add_temp("apply/defense", 40);
    	add_temp("apply/armor", 40);	
	if(clonep()) 
	{
		CHANNEL_D->register_relay_channel("chat");
		carry_object("/clone/misc/cloth")->wear();		
	}
	setup();
}
void init()
{
	if(wizardp(this_player())) add_action("debug_trigger","debug");
}

int debug_trigger(string arg)
{	
	if(XKD_D->change_debug())
	{
		write("����ģʽ���ˣ�\n");
		return 1;		
	}
	write("�رյ���ģʽ��ɡ�\n");
	return 1;	
}


int ask_dzd()
{
	command("say Σ�գ�Σ�գ���˵�ϵ�����ֻ��һ���ܻ��Ż����ģ����ǻر�Ҳ�ܷ��������볢��һ�£��ҵ��ǿ��Դ���ȥ��\n");
	this_player()->set_temp("ask_dzd",1);
	return 1;
}

string ask_job()
{
	object me,flag;
	int time;
		
	me = this_player();
	
        //return ("����󺣷��˱Ƚϴ���ʱ�޷����У����������������")
	if(!XKD_D->query_mode() && !me->query_temp("ask_dzd")) return 0;
	if(XKD_D->query_stat()=="ingame")
		return 0;
	if(XKD_D->query_stat()=="overbusy")
		return "����æ���أ��Ȼ���˵��\n";	
	if( !XKD_D->query_mode() && ( me->query_condition("job_busy") ||  me->query("job_name")==XKD_D->query_name())) return "��������ôæ�����볢��ʲô����\n";
	if(!XKD_D->query_mode() && mapp(me->query_conditions_by_type("poison"))){
		command("hmm "+getuid(me));
		return "�����о綾�����ǳ��ܵ��ϼ尾��\n";
	}
	if(!XKD_D->query_mode() && mapp(me->query_conditions_by_type("hurt"))){
		command("hmm "+getuid(me));
		return "��ռ����ֳɱ��ˣ�\n";
	}//over back I will clear_condition so return of poison for forbid player use bug	
	
	if(!XKD_D->query_mode() && me->query_condition("killer")) return XKD_D->query_name()+"�ɲ�����ٸ�����ʲô��ϵ��\n";
	if(!XKD_D->query_mode() && me->query("combat_exp") <20000) return "�����书δ�ɣ���ȥҲ�ա�\n";
   if(!XKD_D->query_mode() && wizardp(me) && getuid(me)!="lsxk") return "���Ͼͱ��������ˡ�\n";
	switch(time = XKD_D->add_player(me,1))
	{
		case -3:command("wawa");
			return "���Ѿ���������\n";
		case -2:command("tm3");
			return "��̫���ˣ�����С����·�ϳ��˰���\n";
		case -1:command("hmm");
			return "���Ǹ���˵��ô��";
		case 0:command("sorry");//debug
			return "���˵�ˣ�"+XKD_D->query_name()+"���ǵ�Ҫ���������ˡ�\n";
	}
	flag = new(MISC_D("dzd_flag"));	
	if(flag) flag->move(me);
	me->delete_temp("ask_dzd");
	command("hehe zhongnian nanzi");
	command("byebye "+getuid(me));
	command(sprintf("whisper %s %s����%sǰ����ɽ�϶ɿڣ������˽Ӵ�����ϴ���"NOR,getuid(me),HIW+"",CHINESE_D->chinese_date(time)));
	//XKD_D->demon_tell(2,me,sprintf(HIW"������ͭ�ƺ�����У�%s��С��壬�����˽Ӵ���͵����͵���\n"NOR,CHINESE_D->chinese_date(time)) );
	return RANK_D->query_respect(me)+"�˵�ʱӢ�ۣ����뵽"+XKD_D->query_name()+"һ�У���������������\n";
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("$N��������������¶��֣���Ȼ�������������о���һ�����ŵ�æ���˻�������\n", ob);
	return;
}
void die()
{
	reincarnate();
	message_vision("$N�������˼���������ɫ�������ö��ˡ�\n",this_object());
	return;	
}

void relay_channel(object me, string verb, string arg)
{	
	call_out("rerere",random(3)+1,me,verb,arg);
}


void rerere(object me, string verb, string arg)
{	
	string ret;
	int emote = 0;
		
	if(!me) return;	
	if(this_object()->query_temp("chat_busy")) return;
	/*
	switch(arg)
	{
		case "���":ret = "��Ҳ��";break;
		case "fuck":ret = "fuck u 2";break;
		case "i love u":ret = "faint";emote=1;break;
		case "byebye":ret = "wave";emote=1;break;
		//case "fuck";ret = "fuck u 2";break;
		//case "fuck";ret = "fuck u 2";break;	
	} */	
	if(strsrch(arg,"���ĵ�����ָͱ��ͱ�������ӣ����������������ľ��һ����ʲô��ӦҲû�С�")!=-1)
	{
		switch(random(11)){
			case 1:
			case 2:
			case 3:
			case 4: emote = 1;
				ret = "poke zhongnian nanzi";
				break;
			case 5:
			case 6:
			case 7: emote = 1;
				ret ="heng";
				break;
			case 10:
				if(!me->query("marry")) return;
				emote = 0;
				ret ="����NPCҮ����Ҳͱ�������������"+me->query("marry/name")+"�鷳��";
				break;
			case 0:
			case 8: emote = 1;
				ret = "hmm "+getuid(me);
				break;
			case 9:return;
		}
	}
	else if(strsrch(arg,"����˵��������������˲�ǳ�����ս�����꣬�ٵ������Ի������Ǿʹ˱������˵������һ����ƮȻ��̶��")!=-1)
	{
		switch(random(4)){
			case 0:	emote = 1;
				ret = "wave "+getuid(me);
				break;
			case 1: emote = 1;
				ret = "byebye "+getuid(me);
				break;
			case 2: emote = 1;
				ret = "wave";
				break;
			case 3: return;
		}
	}
	/*
	�����ġ�(Nipciwei)����⬱�ȭ��������ɽ���ģ���ˮ���������Ǻ�����ڣ���
	else if(strsrch(arg,"")!=-1)
	{
		emote = 1;
		ret = "wave";
	}
	*/
	if(!undefinedp(ret)){
		CHANNEL_D->do_channel(this_object(),"chat",ret,emote);
		set_temp("chat_busy",1);
		call_out("delete_temp",5+random(4),"chat_busy");
	}
}
/*
����ʱ�䣺	�ڼ�give��Ч������ʱ�䲻��give��
�����������һ�������±���
��������̾����������������ô���������뿪����ɽҲ�ܾ���������
�������ӵ�������С�ӻ���֪��Т˳����û�и��ϰ������͸������ʺ򰡡��������֪����Ů���ӡ�������
��������˵��������ʲô����������Ұɡ���

����������ñ�ǣ���ʾ�����±���JOB


���Զ�����JOB BUSY������˵�����±������������ǵ�JOB BUSY����ҿ�������������
*/
//add by tangfeng
int accept_object(object who, object ob,object me)
{
   //9��28��-10��8��
   //1096300800-1097164800
   command("say �������Űɣ�����ʱ����������ڸ��ң��Ǻ�");
	   return 0;
   if(ob->query("id")=="xue yuebing"
	   &&ob->query("festival")=="mid-autumn"
	   &&ob->query("owner")==who->query("id"))
   {
		if(time()<1096300800 && !wizardp(who))
		{
			command("ah");
			command("say ��ô������±��˰����쵽������ô���������뿪����ɽҲ�ܾ�������");
			command("say ��С�ӻ���֪��Т˳����û�и��ϰ������͸������ʺ򰡡��������֪����Ů���ӡ���");
			who->start_busy(1);
			return 0;
		}
		else if(time()>1097164800 && !wizardp(who))
		{
			command("?");
			command("say ��������Ѿ���ȥ�˰ɣ��������뿪����ɽҲ�ܾ�������");
			who->start_busy(1);
			return 0;
		}
     	command("sigh");
     	command("say ����������ô���������뿪����ɽҲ�ܾ�������");
     	command("say ��С�ӻ���֪��Т˳����û�и��ϰ������͸������ʺ򰡡��������֪����Ů���ӡ���");

		if(who->query_temp("quest/gift/mid-autumn/yuebing"))
		{
			command("smile");
			command("say ��ղŸ����ˣ�����������ˣ��������Լ��ɡ�");
			return 0;
		}        
		who->set_temp("quest/gift/mid-autumn/yuebing",1);
     	who->start_busy(1);
		call_out("destroying", 1, ob);        
		return 1;
   }
   else   command("? "+(string)who->query("id"));
   return 0;
}
void destroying(object obj)
{
        if(!userp(obj)) destruct(obj);
        return;
}
